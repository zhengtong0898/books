# py3.8
# 在python里面的单例又多种实现方式
# 参考: https://stackoverflow.com/q/6760685/12353483


###############################################################################
#
# 方式一: 单个类的单例
#
###############################################################################
class Singleton1(object):
    _instance = None

    def __new__(cls, *args, **kwags):
        if cls._instance is None:
            cls._instance = object.__new__(cls, *args, **kwags)
        return cls._instance


def test_method_1():

    s1 = Singleton1()
    s2 = Singleton1()
    assert s1 == s2


###############################################################################
#
# 方式二: 基类 + 维护类变量(多个相同类的单例)
#
# 备注: 由于采用的是继承, 基类的_instance类变量也变成了派生类的类变量, 所以多个
#      相同的类的实例化, 都是同一个对象, 不同的类的实例化, 会生成不同的对象.
#
###############################################################################
class Singleton2(object):
    _instance = None

    def __new__(cls, *args, **kwags):
        if cls._instance is None:
            cls._instance = object.__new__(cls, *args, **kwags)
        return cls._instance


class Way2(Singleton2):
    def __init__(self):
        self.way = "way1"


class Other2(Singleton2):

    def __init__(self):
        self.way = "other"


def test_method_2():
    w1 = Way2()
    w2 = Way2()
    w3 = Other2()

    assert w1 == w2
    assert w1 != w3
    assert w2 != w3


###############################################################################
#
# 方式三: metaclass
# metaclass 其实就是一个类装饰器, 仅此而已.
# 因为 __call__ 包裹了 派生类 的整个实例化过程, 装饰器也是一样的.
#
###############################################################################
class Singleton3(type):
    _instances = {}

    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = super(Singleton3, cls).__call__(*args, **kwargs)
        return cls._instances[cls]


class Way3(metaclass=Singleton3):
    def __init__(self):
        self.way = "way2"


def test_method_3():
    w1 = Way3()
    w2 = Way3()
    assert w1 == w2


###############################################################################
#
# 方式四: borg(a singleton with shared-state among instances)
# 利用字典对象的shadow copy特性(在c++里面, 叫做引用)实现数据共享(数据单例).
#
###############################################################################
class Singleton4(object):

    # 状态共享
    _shared_state = {}

    def __init__(self):
        # 每个对象初始化第一件事情就是, 先shadow copy给__dict__
        # 在python中, object的所有数据都保存在 __dict__ 中
        # 因此, 这个行为相当于是hook行为.
        self.__dict__ = self._shared_state
        self.state = "Init"

    def __str__(self):
        return self.state


class Way4(Singleton4):
    pass


def test_method_4():
    a1 = Way4()
    a2 = Way4()

    # a1 和 a2 不是同一个对象
    assert a1 != a2

    # 但是 a2.state 和 a2.state 的数据状态是相同的.
    assert a1.state == a2.state

    # 更改任意一个对象的state都会改变其他对象的state.
    a1.state = "running"
    assert a1.state == "running"
    assert a2.state == "running"
    a2.state = "done"
    assert a1.state == "done"
    assert a2.state == "done"


if __name__ == '__main__':
    test_method_1()
    test_method_2()
    test_method_3()
    test_method_4()
