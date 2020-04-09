#include <iostream>


// 题21_3:
// 编写一个C++递归函数计算f(n).


// 补充公式:
// \begin{ align }
//     f(n) =
//     \begin{ cases }
//         n / 2     & n是偶数 \\
//         f(3n + 1) & n是奇数
//     \end{ cases }
// \end{ align }


int CollatzConjecture(int n) {
    std::cout << n << std::endl;
    if (n <= 1) return n;
    bool is_even = n % 2 ? false : true;
    if (is_even) return CollatzConjecture(n / 2);
    else return CollatzConjecture(3 * n + 1);
}


int test_CollatzConjecture(void) {

    CollatzConjecture(7);

    return 0;
}