# py3.8
import queue


class MySQLConnector:

    def __init__(self, pool):
        self.pool = pool

    def release(self):
        self.pool.release(self)


class MySQLPool:

    def __init__(self, maxsize=100):
        self.maxsize = maxsize
        self.pool = queue.Queue()
        self.idles = maxsize
        self.pendings = 0

        # 一次性创建所有连接.
        for i in range(self.maxsize):
            conn = MySQLConnector(self)
            self.pool.put(conn)

    def get(self):
        conn = self.pool.get()
        self.idles -= 1
        self.pendings += 1
        return conn

    def release(self, conn):
        self.pool.put(conn)
        self.idles += 1
        self.pendings -= 1

    def __str__(self):
        return ("<{} idles=\"{}\" pendings=\"{}\">"
                .format(self.__class__.__name__, self.idles, self.pendings))


def main():
    pool = MySQLPool(50)
    conn = pool.get()
    assert pool.idles == 49
    conn.release()
    assert pool.idles == 50


if __name__ == '__main__':
    main()
