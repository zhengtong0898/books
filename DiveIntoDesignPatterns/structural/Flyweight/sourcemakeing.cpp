#include <iostream>


/******************************************************************************
*
* Gazillion ����һ�� flyweight
* Factory ��һ�� factory method, ���𴴽�����, ���ṩ��������.
*
* Gazillion �� m_value_one ���� intrinsic, �� value_two �� extrinsic.
*
*******************************************************************************/
class Gazillion
{
private:
    int m_value_one;

public:
    Gazillion(int value_one) {
        m_value_one = value_one;
        std::cout << "ctor: " << m_value_one << '\n';
    }

    ~Gazillion() { 
        std::cout << m_value_one << ' '; 
    }

    void 
    report(int value_two) { 
        std::cout << m_value_one << value_two << ' '; 
    }
};


class Factory
{
private:
    // �����, ���ڻ����ж���, ���Gazillion���󱻳�Ϊ flyweight.
    static Gazillion * s_pool[];

public:
    static int X, Y;

public:
    static Gazillion * 
    get_fly(int in) {
        if (!s_pool[in]) s_pool[in] = new Gazillion(in);
        return s_pool[in];
    }

    static void 
    clean_up() {
        std::cout << "dtors: ";
        for (int i = 0; i < X; ++i)
            if (s_pool[i]) delete s_pool[i];
        std::cout << '\n';
    }
};


int Factory::X = 6, Factory::Y = 10;
Gazillion* Factory::s_pool[] = { 0, 0, 0, 0, 0, 0 };


int test_flyweight208() {

    for (int i = 0; i < Factory::X; ++i) {

        // Factory::get_fly(i), ��ȡ�ж���, �����ھʹ���, ���ھͲ�����.
        for (int j = 0; j < Factory::Y; ++j)
            Factory::get_fly(i)->report(j);
        std::cout << '\n';

    }

    Factory::clean_up();

    return 0;
}


// output
// ctor: 0
// 00 01 02 03 04 05 06 07 08 09
// ctor: 1
// 10 11 12 13 14 15 16 17 18 19
// ctor : 2
// 20 21 22 23 24 25 26 27 28 29
// ctor : 3
// 30 31 32 33 34 35 36 37 38 39
// ctor : 4
// 40 41 42 43 44 45 46 47 48 49
// ctor : 5
// 50 51 52 53 54 55 56 57 58 59
// dtors : 0 1 2 3 4 5
