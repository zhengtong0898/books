#include <iostream>


class Component {
protected:
    virtual ~Component() {}
public:
    virtual void execute() = 0;
};


class ConcreteComponent : public Component {
public:
    void execute() { std::cout << "concrete task" << std::endl; }
};


class BaseDecorator : public Component {
protected:
    Component & wrapper;
public:
    BaseDecorator(Component & c): wrapper(c) {}
    virtual void execute() {
        std::cout << "do something: start by BaseDecorator" << std::endl;
        wrapper.execute();
        std::cout << "do something: stop  by BaseDecorator" << std::endl;
    }
};


class ConcreteDecorator1 : public BaseDecorator {
public:
    ConcreteDecorator1(Component & c): BaseDecorator(c) {}
    void execute() override {
        std::cout << "do something: start by ConcreteDecorator1" << std::endl;
        wrapper.execute();
        std::cout << "do something: stop  by ConcreteDecorator1" << std::endl;
    }
};



class ConcreteDecorator2 : public BaseDecorator {
public:
    ConcreteDecorator2(Component& c) : BaseDecorator(c) {}
    void execute() override {
        std::cout << "do something: start by ConcreteDecorator2" << std::endl;
        wrapper.execute();
        std::cout << "do something: stop  by ConcreteDecorator2" << std::endl;
    }
};


int main(void) {

    // 层层套入
    ConcreteComponent concrete;
    ConcreteDecorator1 decorator1(concrete);
    ConcreteDecorator2 decorator2(decorator1);

    // 触发递归行为.
    decorator2.execute();

    // output:
    // do something: start by ConcreteDecorator2
    // do something : start by ConcreteDecorator1
    // concrete task
    // do something : stop  by ConcreteDecorator1
    // do something : stop  by ConcreteDecorator2

    return 0;
}