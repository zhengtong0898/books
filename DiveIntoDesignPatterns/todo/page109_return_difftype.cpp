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
    void set_small_foo() {
        std::cout << "set small 109 foo" << std::endl;
    }
    void set_foo() {
        std::cout << "Small109 foo" << std::endl;
    }
};


class Big109 : public Interface109 {
public:
    void set_bigfoo() {
        std::cout << "set big 109 foo" << std::endl;
    }
    void set_foo() {
        std::cout << "Big109 foo" << std::endl;
    }
};


class AbstractClass109 {
public:
    virtual ~AbstractClass109() {}
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



int test_return_difftype109(void) {

    AbstractClass109 * ac = new SmallDerivedClass109;
    Interface109 * is109 = ac->get_result();
    Small109 * s109 = dynamic_cast<Small109*>(is109);
    s109->set_foo();
    s109->set_small_foo();


    std::cout << "return difftype" << std::endl;

    return 0;
}