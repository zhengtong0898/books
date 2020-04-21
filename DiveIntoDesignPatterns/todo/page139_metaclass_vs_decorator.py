# py3.8


###############################################################################
#
# metaclass
# 在派生类中声明metaclass=xx, 将会触发元类的__call__方法
#
###############################################################################
class Base(type):

    def __new__(cls, *args):
        print("base __new__: start")
        obj = super().__new__(cls, *args)
        print("base __new__: end")
        return obj

    def __call__(cls, *args, **kwargs):
        print("base __call__: start")
        obj = super(Base, cls).__call__(*args, **kwargs)
        print("base __call__: end")
        return obj


class Person(metaclass=Base):

    def __new__(cls, *args):
        print("Person __new__: start")
        obj = super().__new__(cls, *args)
        print("Person __new__: end")
        return obj

    def __init__(self):
        print("Person __init__")


def test_metaclass():
    p = Person()

    # output: 
    # base __new__: start
    # base __new__: end
    # base __call__: start              here: wrapper-start
    # Person __new__: start
    # Person __new__: end
    # Person __init__
    # base __call__: end                here: wrapper-stop


###############################################################################
#
# 提问: metaclass 和 decorator 有什么区别吗?
# 
# 回答: 从表现上看没有什么区别, 从特性上看metaclass只能装饰类, 
#      而装饰器可以装饰装饰函数/类/类属性.
#
###############################################################################


if __name__ == '__main__':
    test_metaclass()