
#include <algorithm>
#include <iostream>
#include <list>
#include <string>


/******************************************************************************
*
* 如果 Component 维护数据的话, 那么它可以是一个抽象类, 定义一些抽象方法.
* 如果 Component 不维护数据的话, 那么它可以是一个接口类.
*
* protected 允许派生类继承这个成员变量(和成员函数).
*
*******************************************************************************/
class Component {
protected:
    Component* parent_;         // 当前案例中, 这个成员变量并没有怎么使用.
public:
    virtual ~Component() {}

    void 
    SetParent(Component* parent) { this->parent_ = parent; }

    Component* 
    GetParent() const { return this->parent_; }

    virtual void Add(Component* component) {}
    virtual void Remove(Component* component) {}
    virtual bool IsComposite() const { return false; }
    virtual std::string Operation() const = 0; 
};


/******************************************************************************
* 
* Leaf 负责做具体与业务相关的事情.
*
*******************************************************************************/
class Leaf : public Component {
public:
    std::string Operation() const override {
        return "Leaf";
    }
};


/*******************************************************************************
 *
 * Composite 负责维护一个Component聚合列表集(childrens: leaf 或者 Composite), 
 * 成员可能是Leaf也可能是Composite, 因为两个类都继承了Component. 
 *
 * Composite 对象委托(delegate)给聚合列表集(childrens: leaf 或者 Composite)
 * 让他们去具体的事情, 然后由最上级Composite汇总并返回.
 * 
*******************************************************************************/
class Composite : public Component {
protected:
    std::list<Component*> children_;

public:
    void Add(Component* component) override {
        this->children_.push_back(component);
        component->SetParent(this);
    }
    void Remove(Component* component) override {
        children_.remove(component);
        component->SetParent(nullptr);
    }
    bool IsComposite() const override {
        return true;
    }
    std::string Operation() const override {
        std::string result;
        for (const Component* c : children_) {
            if (c == children_.back()) {
                result += c->Operation();
            }
            else {
                result += c->Operation() + "+";
            }
        }
        return "Branch(" + result + ")";
    }
};


/******************************************************************************
*
* The client code works with all of the components via the base interface.
* 客户端根据 Component 接口进行编程.
*
********************************************************************************/
void ClientCode(Component* component) {
    std::cout << "RESULT: " << component->Operation();
}


void ClientCode2(Component* component1, Component* component2) {
    // ...
    if (component1->IsComposite()) {
        component1->Add(component2);
    }
    std::cout << "RESULT: " << component1->Operation();
    // ...
}


int test_composite173() {

    // 客户端把 Leaf 当作独立对象, 直接根据Component接口进行操作.
    Component* simple = new Leaf;
    std::cout << "Client: I've got a simple component:\n";
    ClientCode(simple);
    std::cout << "\n\n";


    // Composite 
    Component* tree = new Composite;
    Component* branch1 = new Composite;

    // Leaf
    Component* leaf_1 = new Leaf;
    Component* leaf_2 = new Leaf;
    Component* leaf_3 = new Leaf;

    // 将 leaf 加入到 Composite--branch1 中.
    branch1->Add(leaf_1);
    branch1->Add(leaf_2);

    // Composite
    Component* branch2 = new Composite;

    // 将 leaf 加入到 Composite--branch2 中. 
    branch2->Add(leaf_3);

    // 将 Composite--branch1 和 Composite--branch2 加入到 Composite--tree 中.
    tree->Add(branch1);
    tree->Add(branch2);
    std::cout << "Client: Now I've got a composite tree:\n";
    ClientCode(tree);
    std::cout << "\n\n";

    std::cout << "Client: I don't need to check the components classes even when managing the tree:\n";
    ClientCode2(tree, simple);
    std::cout << "\n";

    delete simple;
    delete tree;
    delete branch1;
    delete branch2;
    delete leaf_1;
    delete leaf_2;
    delete leaf_3;

    return 0;
}
