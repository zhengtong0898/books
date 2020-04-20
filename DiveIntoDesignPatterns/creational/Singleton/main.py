# py3.8
# ��python����ĵ����ֶ���ʵ�ַ�ʽ
# �ο�: https://stackoverflow.com/q/6760685/12353483


###############################################################################
#
# ��ʽһ: ������ĵ���
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
# ��ʽ��: ���� + ά�������(�����ͬ��ĵ���)
#
# ��ע: ���ڲ��õ��Ǽ̳�, �����_instance�����Ҳ�����������������, ���Զ��
#      ��ͬ�����ʵ����, ����ͬһ������, ��ͬ�����ʵ����, �����ɲ�ͬ�Ķ���.
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
# ��ʽ��: metaclass
# metaclass ��ʵ����һ����װ����, ���˶���.
# ��Ϊ __call__ ������ ������ ������ʵ��������, װ����Ҳ��һ����.
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
# ��ʽ��: borg(a singleton with shared-state among instances)
# �����ֵ�����shadow copy����(��c++����, ��������)ʵ�����ݹ���(���ݵ���).
#
###############################################################################
class Singleton4(object):

    # ״̬����
    _shared_state = {}

    def __init__(self):
        # ÿ�������ʼ����һ���������, ��shadow copy��__dict__
        # ��python��, object���������ݶ������� __dict__ ��
        # ���, �����Ϊ�൱����hook��Ϊ.
        self.__dict__ = self._shared_state
        self.state = "Init"

    def __str__(self):
        return self.state


class Way4(Singleton4):
    pass


def test_method_4():
    a1 = Way4()
    a2 = Way4()

    # a1 �� a2 ����ͬһ������
    assert a1 != a2

    # ���� a2.state �� a2.state ������״̬����ͬ��.
    assert a1.state == a2.state

    # ��������һ�������state����ı����������state.
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
