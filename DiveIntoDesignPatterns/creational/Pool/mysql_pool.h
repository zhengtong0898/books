#pragma once
#ifndef __MYSQLPOOL_INCLUDED__
#define __MYSQLPOOL_INCLUDED__
#include <ostream>
#include <mutex>
#include <queue>

class MySQLConnector;


class MySQLPool {
private:
    int                                         maxsize;
    int                                         idles;
    int                                         pendings;
    std::mutex                                  mutex;
    std::queue<std::shared_ptr<MySQLConnector>> queue;

public:
    MySQLPool(int max);

public:
    std::shared_ptr<MySQLConnector> get();

    void release(std::shared_ptr<MySQLConnector> conn);

    friend std::ostream & operator<<(std::ostream & os, MySQLPool & pool);
};


#endif // !__MYSQLPOOL_INCLUDED__
