// 题04: 编写一个模板函数 inner_product, 返回值是 $$ \sum_{i=0}^{n-1}a[i] * b[i]  $$ .
#include <iostream>


// 打开这个编辑器网址, 输入下面这个数学符号语法, 得到题目要求的数学公式.
// https://www.mathjax.org/#demo
// $$ \sum_{i=0}^{n-1}a[i] * b[i]  $$


template<typename T>
T inner_product(T a[], T b[], int n) {
    T sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i] * b[i];
    }
    return sum;
}


int test_inner_product(void) {

    // int
    int int_a[] = { 1,2,3,4,5 };
    int int_b[] = { 1,2,3,4,5 };
    auto int_sum = inner_product(int_a, int_b, 5);
    std::cout << "sum: " << int_sum << std::endl;

    // float
    float float_a[] = { 1.1f, 1.2f, 1.3f, 1.4f, 1.5f };
    float float_b[] = { 1.1f, 1.2f, 1.3f, 1.4f, 1.5f };
    auto float_sum = inner_product(float_a, float_b, 5);
    std::cout << "sum: " << float_sum << std::endl;

    return 0;
}


// $$ \sum_{i=1}^{10}i  = 55    $$      1+2+3+4+5...+10  = 55
// $$ \sum_{i=1}^{50}i  = 1275  $$      1+2+3+4+5...+50  = 1275
// $$ \sum_{i=1}^{100}i = 5050  $$      1+2+3+4+5...+100 = 5050
int sigma_sum(int n = 100) {
    int sum = 0;
    for (int i = 0; i <= n; ++i) sum += i;
    return sum;
}


int test_sigma_sum(void) {
    auto sum = sigma_sum(10);
    std::cout << "sum: " << sum << std::endl;
    return 0;
}
