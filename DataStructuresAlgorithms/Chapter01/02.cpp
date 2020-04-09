// 题02: 编写一个模板函数 count, 返回值是数组a[0:n-1]中value出现的次数.
#include <iostream>
#include <string>
#include <vector>


template<typename T>
int count(T * arr[], int length, T * value) {
    int counter = 0;
    for (int i = 0; i < length; ++i) {
        if (arr[i] != value) continue;
        counter += 1;
    }
    std::cout << "char_count: ";
    return counter;
}


template<typename T>
int count(T arr[], int length, T value) {
    int counter = 0;
    for (int i = 0; i < length; ++i) {
        if (arr[i] != value) continue;
        counter += 1;
    }
    std::cout << "other_count: ";
    return counter;
}


int test_count(void) {

    // int
    int int_arr[] = { 0, 1, 2, 7, 3, 8, 4, 5, 6, 7, 8, 9 };
    int int_length = sizeof(int_arr) / sizeof(int_arr[0]);
    int int_counter = count(int_arr, int_length, 8);
    std::cout << "int_counter: " << int_counter << std::endl;

    // float
    float float_arr[] = { 0.0f, 0.1f, 0.2f, 0.3f, 0.4f };
    int   float_length = sizeof(float_arr) / sizeof(float_arr[0]);
    int   float_counter = count(float_arr, float_length, 0.4f);
    std::cout << "float_counter: " << float_counter << std::endl;

    // char
    const char * char_arr[] = { "foo", "bar", "foo" };
    int char_length = sizeof(char_arr) / sizeof(char_arr[0]);
    int char_counter = count(char_arr, char_length, "foo");
    std::cout << "char_counter: " << char_counter << std::endl;

    // string
    std::string string_arr[] = { "hello", "world", "good", "person", "c++", "python", "good", "good" };
    int string_length = sizeof(string_arr) / sizeof(string_arr[0]);
    int string_counter = count(string_arr, string_length, std::string("good"));
    std::cout << "string_counter: " << string_counter << std::endl;

    return 0;
}
