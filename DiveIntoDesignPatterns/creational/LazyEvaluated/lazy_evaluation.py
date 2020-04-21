"""
Lazily-evaluated property pattern in Python.
https://en.wikipedia.org/wiki/Lazy_evaluation
*References:
bottle
https://github.com/bottlepy/bottle/blob/cafc15419cbb4a6cb748e6ecdccf92893bb25ce5/bottle.py#L270
django
https://github.com/django/django/blob/ffd18732f3ee9e6f0374aff9ccf350d85187fac2/django/utils/functional.py#L19
pip
https://github.com/pypa/pip/blob/cb75cca785629e15efb46c35903827b3eae13481/pip/utils/__init__.py#L821
pyramimd
https://github.com/Pylons/pyramid/blob/7909e9503cdfc6f6e84d2c7ace1d3c03ca1d8b73/pyramid/decorator.py#L4
werkzeug
https://github.com/pallets/werkzeug/blob/5a2bf35441006d832ab1ed5a31963cbc366c99ac/werkzeug/utils.py#L35
*TL;DR
Delays the eval of an expr until its value is needed and avoids repeated evals.
"""
# py3.8
import functools


###############################################################################
#
# ������ʾ���Ϊһ����ĳ�Ա�������л���.
# ���Ǹ���������, ԭ��������: https://docs.python.org/3/howto/descriptor.html
# 
# Person ��� relatives ����, ����װ������, �÷����ͱ��������, ��:
# Person.relatives = lazy_property(Person.relatives)
# Person.relatives ��һ���෽��(class method), �����һ�������(class variable)
# 
# ����һ��������Ĭ����Ϊ:
# The default behavior for attribute access is to get, set, or delete the 
# attribute from an object��s dictionary. For instance, a.x has a lookup chain 
# starting with a.__dict__['x'], then type(a).__dict__['x'], and continuing 
# through the base classes of type(a) excluding metaclasses
# 
# ���ҵ���������������� __get__/__set__/__delete__����һ������ʱ, ��ô�������
# ����һ�� descriptor. �������ұ�����Ĭ����Ϊ�������仯:
# If the looked-up value is an object defining one of the descriptor methods, 
# then Python may override the default behavior and invoke the descriptor 
# method instead. Where this occurs in the precedence chain depends on 
# which descriptor methods were defined.
#
# ���������Բ��� �� ʵ����������Բ��� ��һ��:
# For objects, the machinery is in object.__getattribute__() which transforms 
# b.x into type(b).__dict__['x'].__get__(b, type(b)). The implementation 
# works through a precedence chain that gives data descriptors priority 
# over instance variables, instance variables priority over non-data 
# descriptors, and assigns lowest priority to __getattr__() if provided. 
# The full C implementation can be found in PyObject_GenericGetAttr() 
# in Objects/object.c.
# 
###############################################################################
class lazy_property:

    def __init__(self, function):
        # function == Person.relatives
        self.function = function

        # �ο�: todo/page139_decorator.py
        functools.update_wrapper(self, function)

    def __get__(self, obj, type_):
        # obj == hon
        if obj is None:
            return self

        # self.function(obj) == Person.relatives(hon)
        val = self.function(obj)

        # ������д�� hon.__dict__["relatives"] = val
        obj.__dict__[self.function.__name__] = val
        return val


class Person:

    def __init__(self, name, occupation):
        self.name = name
        self.occupation = occupation

    @lazy_property
    def relatives(self):
        # let's assume that it costs much time.
        relatives = "Many relatives."
        return relatives


def main():
    hon = Person('Jhon', 'Coder')
    print(sorted(hon.__dict__.items()))

    hon.relatives
    print(sorted(hon.__dict__.items()))
