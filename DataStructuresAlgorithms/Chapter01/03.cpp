// 题03: 编写一个模板函数 fill, 给数组 a[start:end-1] 赋值 value.
#include <iostream>
#include <limits>


template<typename T>
void fill(T * arr[], int length, T * value) {
    for (int i = 0; i < length; ++i) {
        arr[i] = value;
    }
    std::cout << "char_count: ";
}


template<typename T>
void fill(T arr[], int length, T value) {
    for (int i = 0; i < length; ++i) {
        arr[i] = value;
    }
    std::cout << "other_count: ";
}


int test_fill03(void) {
    // int
    int int_arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int int_length = sizeof(int_arr) / sizeof(int_arr[0]);
    fill(int_arr, int_length, 8);
    for (auto ele: int_arr) std::cout << ele << " ";
    std::cout << std::endl;

    // char
    const char* char_arr[]  = { "你好", "我好" };
    int         char_length = sizeof(char_arr) / sizeof(char_arr[0]);
    fill(char_arr, char_length, "c++");
    for (auto ele : char_arr) std::cout << ele << " ";
    std::cout << std::endl;

    return 0;
}
