#include <iostream>


/*
 *
 * ����: �����в����ܲ����� constexpr ������������?
 *  
 * �ش�: ����, ��Ϊ char ** ����һ��constexpr ����.
 * 
 */


int test_page10003(int argc, char ** argv) {

    // �����ڱ���: 
    // error C2131 : expression did not evaluate to a constant
    // message : failure was caused by a read of a variable outside its lifetime
    // message : see usage of 'argc'
    //
    // ������Ϣ: argc �ڱ�������һ����û�д����Ķ���(a variable outside its lifetime).
    // static_assert(argc == 1);

    return 0;
}