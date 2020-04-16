#include <iostream>


/******************************************************************************
* ������(���麯��)                                                             *
* �﷨: virtual return-type function() = 0;                                   *
* �����಻�ܱ�ʵ����, Ҳ����������Ա����, Ҳ���ܶ������Ĵ��麯����ʵ��             *
* ������ֻ��ͨ���̳�, ����������ʵ����Щ���麯��                                 *
*                                                                             *
* ���ֱ�����OOP�Ľӿڸ�����һ�µ�, �����c++�г�������ǽӿ�.                     *
*                                                                             *
* �ο�: https://en.cppreference.com/w/cpp/language/abstract_class             *
*******************************************************************************/
class AbstractClass074 {
public:
    // �����������������������, ��������ͨ��vtable�ҵ������ಢ�������������������.
    virtual ~AbstractClass074() {};                 
    virtual void hello() = 0;
};


class AbstractChildren : public AbstractClass074 {
public:
    virtual ~AbstractChildren() {
        std::cout << "AbstractChildren destroy" << std::endl;
    }

    virtual void hello() {
        std::cout << "hello" << std::endl;
    }
};


int test_AbstractClass074(void) {

    AbstractClass074 * abs_obj = new AbstractChildren;
    abs_obj->hello();
    delete abs_obj;
    std::cout << "hello world!" << std::endl;

    return 0;
}