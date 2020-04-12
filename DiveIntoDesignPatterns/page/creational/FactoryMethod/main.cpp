#include <iostream>


class Product {
public:
    virtual void doStuff() = 0;
};


class ConcreteProductA: public Product {
public:
    ConcreteProductA() {}
    void doStuff() {
        std::cout << "doSuff in ConcreteProductA" << std::endl;
    }
};


class ConcreteProductB : public Product {
public:
    ConcreteProductB() {}
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
    ConcreteCreateA() {}
    Product * createProduct() {
        return new ConcreteProductA;
    }
};


class ConcreteCreateB : public Creator {
public:
    ConcreteCreateB() {}
    Product* createProduct() {
        return new ConcreteProductB;
    }
};


int main(void) {

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
