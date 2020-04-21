# py3.8
import time
import functools


###############################################################################
#
# ����: װ�������ڴ�����ؽ׶�(����ִ�н׶�)����������?
# ��: �ǵ�, ����Ĵ���, ֻ�Ƕ���, 
#       û���κε���, ��Ȼ���ӡ��: load-time: simple_decorator is invoking...
#
###############################################################################
def simple_decorator(func):
    print("load-time: simple_decorator is invoking...")

    def simple_wrapper(*args, **kwargs):
        return func(*args, **kwargs)
    return simple_wrapper


@simple_decorator
def foo():
    return "foo"


###############################################################################
#
#
# functools.wraps
# ����һ��������, ����ְ���ǵ��� functools.update_wraps ��αװװ������������,
# ��װ������������Ϊʵ�ʺ�����, �ÿ�������debug(dir)ʱ��ֱ��֪����ǰ����ʱ�ĸ�����.
#
#
# functools.update_wraps(wrapper,
#                        wrapped,
#                        assigned = WRAPPER_ASSIGNMENTS,
#                        updated = WRAPPER_UPDATES)
#
# �� simple_decorator ����Ϊ������������
#
# wrapper: <function simple_decorator.<locals>.simple_wrapper at 0x000000000xx>
# wrapped: <function foo at 0x000000000xx>
# assigned: ('__module__', '__name__', '__qualname__', '__doc__', '__annotations__')
# updated: ('__dict__',)
#
# 1. ���������ְ��ʱ�� wrapped �Ķ���� assigned �⼸����ʡ���Ը���д�뵽 wrapper ����.
# 2. �ٽ� wrapped �Ķ���� __dict__ ����д�뵽 wrapper ����.
# 3. wrapper.__wrapped__ = wrapped ��ʾ ���ε�ʱ�ĸ�����.
#
#
###############################################################################
def elasped_decorator(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        start = time.time()
        res = func(*args, **kwargs)
        stop = time.time()
        return res
    return wrapper


@elasped_decorator
def bar():
    return "bar"


def main():
    print(bar)
    print(dir(bar))
    print(bar.__wrapped__)


if __name__ == '__main__':
    main()
