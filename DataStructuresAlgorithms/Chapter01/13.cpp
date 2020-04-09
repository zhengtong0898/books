#include <iostream>
#include <memory>
#include <algorithm>


// 题13: 
// 编写一个模板函数 changeLength1D, 它将一个一维数组的长度从oldLength变成newLength.
// 函数首先分配一个新的、长度为newLength的数组, 然后把原数组的前min{oldLength, newLength}个
// 元素复制到新数组中, 最后释放原数组所占用的空间.
template<typename T>
void changeLength1D(T *& originArr, int oldLength, int newLength) {

    T * newerArr = new T[newLength];

    // 第一种写法
    int minLength = std::min(oldLength, newLength);
    std::copy(originArr, originArr + minLength, newerArr);
    delete[] originArr;
    originArr = newerArr;

    // 第二种写法
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
