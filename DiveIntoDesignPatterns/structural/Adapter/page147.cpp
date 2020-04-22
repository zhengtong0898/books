#include <iostream>


/******************************************************************************
*
* 适配器结构
* 一个面向客户端的client_interface, 
* 多个不同的Adapter继承interface, 每个Adapter可以继承或聚合具体的实现类.
* 每个Adapter根据具体类的实现封装出符合client_interface场景输出的代码.
*
*******************************************************************************/


/******************************************************************************
*
* 一个面向客户端的client_interface
*
*******************************************************************************/
class ClientInterface {
public:
    virtual ~ClientInterface() {}
    virtual std::string method(std::string data) = 0;
};


/******************************************************************************
*
* 具体类
*
*******************************************************************************/
class ServiceX {
public:
    std::string XMethod(std::string target) { return "x_result"; }
};


class ServiceY {
public:
    std::string YMethod(std::string target) { return "y_result"; }
};


/******************************************************************************
*
* Adapter
*
*******************************************************************************/
class ServiceXAdapter: public ClientInterface {
private: 
    ServiceX & service;
public:
    ServiceXAdapter(ServiceX & s): service(s) {}
    std::string method(std::string target) {
        std::string x_data = service.XMethod(target);
        // do some convert
        std::string converted = x_data;
        return converted;
    }
};


class ServiceYAdapter : public ClientInterface {
private:
    ServiceY & service;
public:
    ServiceYAdapter(ServiceY & s): service(s) {}
    std::string method(std::string target) {
        std::string x_data = service.YMethod(target);
        // do some convert
        std::string converted = x_data;
        return converted;
    }
};


/******************************************************************************
*
* main 函数就是client, 就是业务逻辑类.
*
*******************************************************************************/
int test_adapter147(void) {

    // 获取json的场景就调用ServiceXAdapter
    ServiceX sx;
    ServiceXAdapter sx_adapter(sx);
    auto _ = sx_adapter.method("get json");

    // 获取xml的场景就调用ServiceYAdapter
    ServiceY sy;
    ServiceYAdapter sy_adapter(sy);
    auto __ = sy_adapter.method("get xml");

    return 0;
}


/******************************************************************************
*
* todo:
* ServiceXAdapter在定义上与ServiceX如此强关联, 连实例化也必须一致, 
* 为什么不把他们的关系定义为组合, 让ServiceXAdapter在构造函数中实例化它,
* 也可以管理它的生命周期, 最主要的是对外少暴露操作, 降低复杂度.
*
*******************************************************************************/