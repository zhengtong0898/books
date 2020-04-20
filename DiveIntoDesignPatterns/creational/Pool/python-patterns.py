"""
*What is this pattern about?
This pattern is used when creating an object is costly (and they are
created frequently) but only a few are used at a time. With a Pool we
can manage those instances we have as of now by caching them. Now it
is possible to skip the costly creation of an object if one is
available in the pool.
A pool allows to 'check out' an inactive object and then to return it.
If none are available the pool creates one to provide without wait.
*What does this example do?
In this example queue.Queue is used to create the pool (wrapped in a
custom ObjectPool object to use with the with statement), and it is
populated with strings.
As we can see, the first string object put in "yam" is USED by the
with statement. But because it is released back into the pool
afterwards it is reused by the explicit call to sample_queue.get().
Same thing happens with "sam", when the ObjectPool created inside the
function is deleted (by the GC) and the object is returned.
*Where is the pattern used practically?
*References:
http://stackoverflow.com/questions/1514120/python-implementation-of-the-object-pool-design-pattern
https://sourcemaking.com/design_patterns/object_pool
*TL;DR
Stores a set of initialized objects kept ready to use.
"""


###############################################################################
#
# queue.Queue()
# 1. 它是一个线程安全的对象, 因为每个操作都使用锁.
# 2. put: 将一条数据写入到队列
# 3. get: 从队列中移除一条数据出来
#
###############################################################################


###############################################################################
#
# 1. with 关键字会触发 __enter__ 和 __exit__ 和 __del__ 这两个函数.
# 2. 函数退出会触发 __del__ 函数.
#
###############################################################################


###############################################################################
#
# 备注:
# 当前样例代码严格意义上来讲算不上一个pool.
# 利用好上述5个特性, 能发挥出强大的效果.
# 一个合格的pool应该要维护一组管理数据.
#
###############################################################################
class ObjectPool:

    def __init__(self, queue, auto_get=False):
        self._queue = queue
        self.item = self._queue.get() if auto_get else None

    def __enter__(self):
        print("__enter__")
        if self.item is None:
            self.item = self._queue.get()
        return self.item

    def __exit__(self, Type, value, traceback):
        print("__exit__")
        if self.item is not None:
            self._queue.put(self.item)
            self.item = None

    def __del__(self):
        print("__del__")
        if self.item is not None:
            self._queue.put(self.item)
            self.item = None


def main():
    import queue

    def test_object(queue):
        pool = ObjectPool(queue, True)
        print('Inside func: {}'.format(pool.item))

    sample_queue = queue.Queue()

    sample_queue.put('yam')
    with ObjectPool(sample_queue) as obj:
        print('Inside with: {}'.format(obj))
    print('Outside with: {}'.format(sample_queue.get()))

    sample_queue.put('sam')
    test_object(sample_queue)
    print('Outside func: {}'.format(sample_queue.get()))

    if not sample_queue.empty():
        print(sample_queue.get())


if __name__ == '__main__':
    main()


### OUTPUT ###
# Inside with: yam
# Outside with: yam
# Inside func: sam
# Outside func: sam