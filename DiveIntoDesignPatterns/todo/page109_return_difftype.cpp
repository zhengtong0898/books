#include <iostream>

/******************************************************************************
*
* ����: һ���������Ƿ���Զ���һ��������, ��������ͨ������ʵ��ʱ���ز�ͬ����?
*
* ��: ������, �⽫����������(ambiguous); �������Ը���(��̬)��Ҫ����, 
*       ���������Ͳ������ͱ��뱣��һ��, ��������Ҳ���뷵��һ��.
*
* ����: ��һ���������, �������ڸ���ʱ���Է���"��ͬ����", �������ͽ���: CoVariant.
*       ��Щ"��ͬ����"����̳�ͬһ������, �����ڳ�����ĳ��󷽷��ķ���ֵ���Ͷ�����
*       һ��Ҫ��������Ȳ�����ָ������, ������������Ϊ��.
*
*******************************************************************************/
class Interface109 {
public:
    virtual ~Interface109() {}
    virtual void set_foo() = 0;
};


class Small109 : public Interface109 {
public:
    void set_foo() {
        std::cout << "Small109 foo" << std::endl;
    }
};


class Big109 : public Interface109 {
public:
    void set_foo() {
        std::cout << "Big109 foo" << std::endl;
    }
};


class AbstractClass109 {
public:
    virtual Interface109 * get_result() = 0;
};


class SmallDerivedClass109 : public AbstractClass109 {
public:
    Small109 * get_result() {
        return new Small109;
    }
};


class BigDerivedClass109 : public AbstractClass109 {
public:
    Big109 * get_result() {
        return new Big109;
    }
};



int main(void) {

    new SmallDerivedClass109;

    std::cout << "return difftype" << std::endl;

    return 0;
}