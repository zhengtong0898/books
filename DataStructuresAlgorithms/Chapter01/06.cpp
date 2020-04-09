// 题06: 编写一个模板函数 is_sorted, 当且仅当a[0:n-1]有序时, 返回值时true.
#include <iostream>


template<typename T>
bool is_sorted(T * arr, int length) {
    bool status = true;
    for (int i = 1; i < length; ++i) {
        T previous = arr[i - 1];
        T current = arr[i];
        if (previous < current) continue;
        status = false;
        break;
    }
    return status;
}


int test_is_sorted(void) {
    int arr[] = { 4, 5, 6, 7 };
    bool sorted = is_sorted(arr, 4);
    std::cout << "sorted: " << sorted << std::endl;

    return 0;
}