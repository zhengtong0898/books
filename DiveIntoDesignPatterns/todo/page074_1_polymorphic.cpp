#include <iostream>


/******************************************************************************
* ����ļ̳�, ��̬�µ�����������������޷�����.                                  *
*******************************************************************************/
class BaseInherit01 {
public:
    BaseInherit01() {
        std::cout << "BaseInherit01 init" << std::endl;
    }

    ~BaseInherit01() {
        std::cout << "BaseInherit01 Destroy" << std::endl;
    }
};



class DerivedClass01: public BaseInherit01 {
public:
    DerivedClass01(): BaseInherit01() {
        std::cout << "DerivedClass01 init" << std::endl;
    }
    ~DerivedClass01() {
        std::cout << "DerivedClass01 Destroy" << std::endl;
    }
};



/******************************************************************************
* ��������̳еĶ���,                                                          *
* ����Ĺ��캯��������������, ������Ĺ��캯��Ҳ����������.                       *
* �������������������������, ���������������Ҳ����������.                       *
*******************************************************************************/
int test_basic_init_and_destroy(void) {

    DerivedClass01 * dc = new DerivedClass01;
    delete dc;
    std::cout << "cast inderit" << std::endl;

    // output:
    // 
    // BaseInherit01 init                           ���� ����   ���캯��
    // DerivedClass01 init                          ���� ������ ���캯��
    // DerivedClass01 Destroy                       ���� ������ ��������
    // BaseInherit01 Destroy                        ���� ����   ��������
    // cast inderit

    return 0;
}


/******************************************************************************
* ������̬�̳еĶ���,                                                          *
* ����Ĺ��캯��������������, ������Ĺ��캯����������.                          *
* �������������������������, ���������������������������.                       *
*******************************************************************************/
int test_polymorphic_init_and_destroy(void) {

    BaseInherit01 * dc = new DerivedClass01;    //  ��̬
    delete dc;
    std::cout << "cast inderit" << std::endl;

    // output
    // BaseInherit01 init                           ���� ����   ���캯��
    // DerivedClass01 init                          ���� ������ ���캯��
    // BaseInherit01 Destroy                        ���� ����   ��������
    // cast inderit
    //
    // ע��: �����ٴ��������������������.

    return 0;
}


/******************************************************************************
* �����̬�̳��޷�����������������������, ���� virtual ������������.              *
*******************************************************************************/
class BasePolymorphic01 {
public:
    BasePolymorphic01() {
        std::cout << "BasePolymorphic01 init" << std::endl;
    }
    virtual ~BasePolymorphic01() {
        std::cout << "BasePolymorphic01 Destroy" << std::endl;
    }
};


class DerivedPolymorphic01: public BasePolymorphic01 {
public:
    DerivedPolymorphic01() {
        std::cout << "DerivedPolymorphic01 init" << std::endl;
    }
    ~DerivedPolymorphic01() {
        std::cout << "DerivedPolymorphic01 Destroy" << std::endl;
    }
};


int test_polymorphic2_init_and_destroy(void) {

    BasePolymorphic01 * bp = new DerivedPolymorphic01;
    delete bp;

    // output
    // BasePolymorphic01 init                       ���� ����   ���캯��
    // DerivedPolymorphic01 init                    ���� ������ ���캯��
    // DerivedPolymorphic01 Destroy                 ���� ������ ��������
    // BasePolymorphic01 Destroy                    ���� ����   ��������
    // cast inderit

    std::cout << "cast inderit" << std::endl;

    return 0;
}
