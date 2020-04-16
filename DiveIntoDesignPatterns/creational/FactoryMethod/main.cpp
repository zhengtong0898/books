#include <iostream>


// ������һ���ӿں�, �̳�����ӿڵ�����������Ҫʵ������ӿ�
// �������������������������߹���������������֮��, һ���ܷ��ʵ��������.
class Product {
public:
    virtual void doStuff() = 0;
};


class ConcreteProductA: public Product {
public:
    void doStuff() {
        std::cout << "doSuff in ConcreteProductA" << std::endl;
    }
};


class ConcreteProductB : public Product {
public:
    void doStuff() {
        std::cout << "doSuff in ConcreteProductB" << std::endl;
    }
};



class Creator {
public:
    virtual Product * createProduct() = 0;
    void someOperation() {
        Product * product = this->createProduct();
        product->doStuff();
        delete product;
    }
};


class ConcreteCreateA : public Creator {
public:
    Product * createProduct() {
        return new ConcreteProductA;
    }
};


class ConcreteCreateB : public Creator {
public:
    Product* createProduct() {
        return new ConcreteProductB;
    }
};


int main_(void) {

    Creator * create_a = new ConcreteCreateA;
    create_a->someOperation();

    Creator * create_b = new ConcreteCreateB;
    create_b->someOperation();

    return 0;
}


// ��ע:
// ���������һ��Ǳ�ڵ�����, ����ÿ�ε���someOperation
// ����newһ��Product����, Ȼ��ִ��һЩ������ֽ���ɾ��,
// ���ֽ�������Ϊһ�ֹ�ϵ: ����.
// 
// ��� product �������, ���� someOperation �ᱻ���ö��ʱ
// �ͻ��Եúܱ���, ��ʱ���ܾ�Ӧ����Creator���д���һ����Ա����, 
// ����Creator��Product�Ĺ�ϵ: ����.
