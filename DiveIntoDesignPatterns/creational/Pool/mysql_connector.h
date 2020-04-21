#pragma once
#ifndef __MYSQLCONNECTOR_INCLUDED__
#define __MYSQLCONNECTOR_INCLUDED__

class MySQLPool;


class MySQLConnector: public std::enable_shared_from_this<MySQLConnector> {
private:
    MySQLPool * pool;

public:
    MySQLConnector(MySQLPool * s);
    ~MySQLConnector();

public:
    void release();
};

#endif // !__MYSQLCONNECTOR_INCLUDED__
