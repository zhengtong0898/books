#include <iostream>


// ��21_3:
// ��дһ��C++�ݹ麯������f(n).


// ���乫ʽ:
// \begin{ align }
//     f(n) =
//     \begin{ cases }
//         n / 2     & n��ż�� \\
//         f(3n + 1) & n������
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