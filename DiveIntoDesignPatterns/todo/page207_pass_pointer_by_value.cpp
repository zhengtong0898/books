#include <iostream>

/******************************************************************************
*
* ����: ָ�뵱��ֵ�������ݸ�����, �ḳֵһ��ָ�������?
*
* ��: ��, ��Ϊָ����һ��long����, ���ڳ�������, ���Ի��ָ����и���.
*      ����, ָ��ָ��� ����/���� �ĵ�ַ���ᷢ���仯.
*
*******************************************************************************/
class Person207 {

};


void do_nothing(Person207 * p) {
    std::cout << "inside do_nothing:  p: " <<  p << std::endl;              // 00000219B4420BC0
    std::cout << "inside do_nothing: &p: " << &p << std::endl;              // 00000084F16FF5F0
}


int test_Person207(void) {

    Person207 * p = new Person207{};

    std::cout << "inside main:  p: " << p << std::endl;                     // 00000219B4420BC0
    std::cout << "inside main: &p: " << &p << std::endl;                    // 00000084F16FF618
    do_nothing(p);

    std::cout << "finish" << std::endl;
    delete p;

    return 0;
}