#include <iostream>
#include <memory>
#include <queue>
#include <mutex>
#include <thread>
#include <cassert>
#include "mysql_pool.h"
#include "mysql_connector.h"


/******************************************************************************
*
* MySQLConnector
*
*******************************************************************************/
MySQLConnector::MySQLConnector(MySQLPool * s) : pool(s) {}
MySQLConnector::~MySQLConnector() {
    std::cout << "Destroy MySQLConnector" << std::endl;
}

void MySQLConnector::release() {
    this->pool->release(shared_from_this());
}



/******************************************************************************
*
* MySQLPool
*
*******************************************************************************/
MySQLPool::MySQLPool(int max): maxsize(max), idles(max), pendings(0) {
    for (int i = 0; i < maxsize; ++i) {
        //MySQLConnector * conn = new MySQLConnector{ this };
        std::shared_ptr<MySQLConnector> conn(new MySQLConnector{ this });
        this->queue.push(conn);
    }
}

std::shared_ptr<MySQLConnector> MySQLPool::get() {
    auto ms = std::chrono::milliseconds(10);
    while (!this->mutex.try_lock()) std::this_thread::sleep_for(ms);

    this->idles -= 1;
    this->pendings += 1;
    auto obj = this->queue.back();
    this->mutex.unlock();
    return obj;
}


void MySQLPool::release(std::shared_ptr<MySQLConnector> conn) {
    auto ms = std::chrono::milliseconds(10);
    while (!this->mutex.try_lock()) std::this_thread::sleep_for(ms);

    this->idles += 1;
    this->pendings -= 1;
    this->queue.push(conn);
    this->mutex.unlock();
}


std::ostream & operator<<(std::ostream & os, MySQLPool & pool) {
    os << "<MySQLPool idles=" << pool.idles 
       << " pendings="        << pool.pendings << ">";
    return os;
}


int main(void) {

    MySQLPool pool { 50 };
    auto conn = pool.get();
    std::cout << pool << std::endl;          // <MySQLPool idles=49 pendings=1>
    auto conn2 = pool.get();
    std::cout << pool << std::endl;          // <MySQLPool idles=48 pendings=2>
    conn->release();
    std::cout << pool << std::endl;          // <MySQLPool idles=49 pendings=1>
    conn2->release();
    std::cout << pool << std::endl;          // <MySQLPool idles=50 pendings=0>

    std::cout << "pool pattern" << std::endl;
    return 0;
}
