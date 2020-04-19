"""
*What is this pattern about?
It decouples the creation of a complex object and its representation,
so that the same process can be reused to build objects from the same
family.
This is useful when you must separate the specification of an object
from its actual representation (generally for abstraction).
*What does this example do?
The first example achieves this by using an abstract base
class for a building, where the initializer (__init__ method) specifies the
steps needed, and the concrete subclasses implement these steps.
In other programming languages, a more complex arrangement is sometimes
necessary. In particular, you cannot have polymorphic behaviour in a constructor in C++ -
see https://stackoverflow.com/questions/1453131/how-can-i-get-polymorphic-behavior-in-a-c-constructor
- which means this Python technique will not work. The polymorphism
required has to be provided by an external, already constructed
instance of a different class.
In general, in Python this won't be necessary, but a second example showing
this kind of arrangement is also included.
*Where is the pattern used practically?
*References:
https://sourcemaking.com/design_patterns/builder
*TL;DR
Decouples the creation of a complex object and its representation.
"""


###############################################################################
#
# AbstractObject/DirectorObject: 既是 抽象对象 也是 指挥官(主管)角色
# 抽象对象: 抽象了一组公共接口
# 指挥官: 在__init__中定义了操作步骤.
#
###############################################################################
class Building:
    def __init__(self):
        self.build_floor()
        self.build_size()

    def build_floor(self):
        raise NotImplementedError

    def build_size(self):
        raise NotImplementedError

    def __repr__(self):
        return 'Floor: {0.floor} | Size: {0.size}'.format(self)


class House(Building):
    def build_floor(self):
        self.floor = 'One'

    def build_size(self):
        self.size = 'Big'


class Flat(Building):
    def build_floor(self):
        self.floor = 'More than One'

    def build_size(self):
        self.size = 'Small'


###############################################################################
#
# In some very complex cases, it might be desirable to pull out the building
# logic into another function (or a method on another class), rather than being
# in the base class '__init__'. (This leaves you in the strange situation where
# a concrete class does not have a useful constructor)
#
# 翻译
# 在一些复杂的场景中, 通常都不会使用上面那种将操作步骤写在__init__中,
# 而是操作步骤环节剥离到外部由外部函数来决定如何构建.
#
# 备注
# 这样做的好处是构建逻辑取决于需求, 而不是被固化在这一组代码中,
# 不同的需求写不同的指挥官函数.
#
###############################################################################
class ComplexBuilding:
    def __repr__(self):
        return 'Floor: {0.floor} | Size: {0.size}'.format(self)


class ComplexHouse(ComplexBuilding):
    def build_floor(self):
        self.floor = 'One'

    def build_size(self):
        self.size = 'Big and fancy'


###############################################################################
#
# 不维护任何数据或状态就像这样, 写一个函数就完事了,
# 如果要维护数据和状态就写一个类, 然后使用聚合的形式来使类始终能访问到building.
#
###############################################################################
def construct_building(cls):
    building = cls()
    building.build_floor()
    building.build_size()
    return building


def main():
    """
    >>> house = House()
    >>> house
    Floor: One | Size: Big
    >>> flat = Flat()
    >>> flat
    Floor: More than One | Size: Small
    # Using an external constructor function:
    >>> complex_house = construct_building(ComplexHouse)
    >>> complex_house
    Floor: One | Size: Big and fancy
    """
    house = House()
    print(house)

    flat = Flat()
    print(flat)

    complex_house = construct_building(ComplexHouse)
    print(complex_house)


if __name__ == "__main__":
    main()
