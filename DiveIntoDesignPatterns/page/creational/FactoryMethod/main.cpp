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


// 备注:
// 这个案例有一个潜在的问题, 就是每次调用someOperation
// 都会new一个Product对象, 然后执行一些代码后又将其删除,
// 这种交互被称为一种关系: 依赖.
// 
// 如果 product 本身很重, 并且 someOperation 会被调用多次时
// 就会显得很笨重, 这时可能就应该在Creator类中创建一个成员变量, 
// 建立Creator于Product的关系: 关联.
