#include <iostream>
#include <memory>
#include <algorithm>


// ��13: 
// ��дһ��ģ�庯�� changeLength1D, ����һ��һά����ĳ��ȴ�oldLength���newLength.
// �������ȷ���һ���µġ�����ΪnewLength������, Ȼ���ԭ�����ǰmin{oldLength, newLength}��
// Ԫ�ظ��Ƶ���������, ����ͷ�ԭ������ռ�õĿռ�.
template<typename T>
void changeLength1D(T *& originArr, int oldLength, int newLength) {

    T * newerArr = new T[newLength];

    // ��һ��д��
    int minLength = std::min(oldLength, newLength);
    std::copy(originArr, originArr + minLength, newerArr);
    delete[] originArr;
    originArr = newerArr;

    // �ڶ���д��
    // int minLength = oldLength < newLength ? oldLength : newLength;
    //for (int i = 0; i < minLength; ++i) {
    //    newerArr[i] = originArr[i];
    //}
    //delete[] originArr;
    //originArr = newerArr;
}


int test_changeLength1D(void) {

    const int oldLength = 5;
    const int newLength = 3;
    int * originArr = new int[oldLength];
    originArr[0] = 1;
    originArr[1] = 2;
    originArr[2] = 3;
    originArr[3] = 4;
    originArr[4] = 5;

    for (int i = 0; i < oldLength; ++i) {
        std::cout << "ele-1: " << originArr[i] << std::endl;
    }

    changeLength1D(originArr, oldLength, newLength);

    int minLength = oldLength < newLength ? oldLength : newLength;
    for (int i = 0; i < minLength; ++i) {
        std::cout << "ele-2: " << originArr[i] << std::endl;
    }

    return 0;
}
