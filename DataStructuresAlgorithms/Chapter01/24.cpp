#include <iostream>
#include <vector>


// 题 24:
// 编写一个递归模板函数, 确定元素 x 是否属于数组a[0:n-1].
template<typename T>
bool in_operator(std::vector<T> arr, T t, int offset=0) {
    if (offset >= arr.size()) return false;
    if (arr[offset] == t) return true;
    if (arr[offset] != t) return in_operator(arr, t, offset + 1);
}



int test_in_operator(void) {
    std::vector<int> v = { 1,2,3,5,6,7,8,9 };
    std::cout << in_operator(v, 4, 0) << std::endl;  // 0
    std::cout << in_operator(v, 0, 0) << std::endl;  // 0
    std::cout << in_operator(v, 9, 0) << std::endl;  // 1
    std::cout << in_operator(v, 3, 0) << std::endl;  // 1
    return 0;
}
