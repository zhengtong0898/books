# py3.8


###############################################################################
#
# metaclass
# ��������������metaclass=xx, ���ᴥ��Ԫ���__call__����
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
# ����: metaclass �� decorator ��ʲô������?
# 
# �ش�: �ӱ����Ͽ�û��ʲô����, �������Ͽ�metaclassֻ��װ����, 
#      ��װ��������װ��װ�κ���/��/������.
#
###############################################################################


if __name__ == '__main__':
    test_metaclass()