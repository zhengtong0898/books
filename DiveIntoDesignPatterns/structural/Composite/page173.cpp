
#include <algorithm>
#include <iostream>
#include <list>
#include <string>


/******************************************************************************
*
* ��� Component ά�����ݵĻ�, ��ô��������һ��������, ����һЩ���󷽷�.
* ��� Component ��ά�����ݵĻ�, ��ô��������һ���ӿ���.
*
* protected ����������̳������Ա����(�ͳ�Ա����).
*
*******************************************************************************/
class Component {
protected:
    Component* parent_;         // ��ǰ������, �����Ա������û����ôʹ��.
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
* Leaf ������������ҵ����ص�����.
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
 * Composite ����ά��һ��Component�ۺ��б�(childrens: leaf ���� Composite), 
 * ��Ա������LeafҲ������Composite, ��Ϊ�����඼�̳���Component. 
 *
 * Composite ����ί��(delegate)���ۺ��б�(childrens: leaf ���� Composite)
 * ������ȥ���������, Ȼ�������ϼ�Composite���ܲ�����.
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
* �ͻ��˸��� Component �ӿڽ��б��.
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

    // �ͻ��˰� Leaf ������������, ֱ�Ӹ���Component�ӿڽ��в���.
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

    // �� leaf ���뵽 Composite--branch1 ��.
    branch1->Add(leaf_1);
    branch1->Add(leaf_2);

    // Composite
    Component* branch2 = new Composite;

    // �� leaf ���뵽 Composite--branch2 ��. 
    branch2->Add(leaf_3);

    // �� Composite--branch1 �� Composite--branch2 ���뵽 Composite--tree ��.
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
