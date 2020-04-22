#include <iostream>


/******************************************************************************
*
* �������ṹ
* һ������ͻ��˵�client_interface, 
* �����ͬ��Adapter�̳�interface, ÿ��Adapter���Լ̳л�ۺϾ����ʵ����.
* ÿ��Adapter���ݾ������ʵ�ַ�װ������client_interface��������Ĵ���.
*
*******************************************************************************/


/******************************************************************************
*
* һ������ͻ��˵�client_interface
*
*******************************************************************************/
class ClientInterface {
public:
    virtual ~ClientInterface() {}
    virtual std::string method(std::string data) = 0;
};


/******************************************************************************
*
* ������
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
* main ��������client, ����ҵ���߼���.
*
*******************************************************************************/
int test_adapter147(void) {

    // ��ȡjson�ĳ����͵���ServiceXAdapter
    ServiceX sx;
    ServiceXAdapter sx_adapter(sx);
    auto _ = sx_adapter.method("get json");

    // ��ȡxml�ĳ����͵���ServiceYAdapter
    ServiceY sy;
    ServiceYAdapter sy_adapter(sy);
    auto __ = sy_adapter.method("get xml");

    return 0;
}


/******************************************************************************
*
* todo:
* ServiceXAdapter�ڶ�������ServiceX���ǿ����, ��ʵ����Ҳ����һ��, 
* Ϊʲô�������ǵĹ�ϵ����Ϊ���, ��ServiceXAdapter�ڹ��캯����ʵ������,
* Ҳ���Թ���������������, ����Ҫ���Ƕ����ٱ�¶����, ���͸��Ӷ�.
*
*******************************************************************************/