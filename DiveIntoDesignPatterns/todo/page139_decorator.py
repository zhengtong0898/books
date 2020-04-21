# py3.8
import time
import functools


###############################################################################
#
# 提问: 装饰器是在代码加载阶段(不是执行阶段)就运行了吗?
# 答案: 是的, 下面的代码, 只是定义, 
#       没有任何调用, 仍然会打印出: load-time: simple_decorator is invoking...
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
# 这是一个抽象函数, 它的职责是调用 functools.update_wraps 来伪装装饰器函数名称,
# 将装饰器函数名改为实际函数名, 让开发者在debug(dir)时更直观知道当前对象时哪个函数.
#
#
# functools.update_wraps(wrapper,
#                        wrapped,
#                        assigned = WRAPPER_ASSIGNMENTS,
#                        updated = WRAPPER_UPDATES)
#
# 以 simple_decorator 代码为例来剖析参数
#
# wrapper: <function simple_decorator.<locals>.simple_wrapper at 0x000000000xx>
# wrapped: <function foo at 0x000000000xx>
# assigned: ('__module__', '__name__', '__qualname__', '__doc__', '__annotations__')
# updated: ('__dict__',)
#
# 1. 这个函数的职责时将 wrapped 的对象的 assigned 这几个内省属性覆盖写入到 wrapper 对象.
# 2. 再将 wrapped 的对象的 __dict__ 覆盖写入到 wrapper 对象.
# 3. wrapper.__wrapped__ = wrapped 表示 修饰的时哪个函数.
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
