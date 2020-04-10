#include <cmath>
#include <iostream>


// Ìâ22-3:
// ±àĞ´C++µİ¹éº¯Êı¼ÆËã A(i, j).
int akermann(int i, int j) {
    if (i == 1 && j >= 1) return static_cast<int>(pow(2, j));
    if (i >= 2 && j == 1) return akermann(i - 1, 2);
    if (i >= 2 && j >= 2) return akermann(i - 1, akermann(i, j - 1));

    return 0;
}

int test_akermann(void) {
    std::cout << akermann(2, 2) << std::endl;
    return 0;
}
