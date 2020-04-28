#include <iostream>
#include <vector>


/*******************************************************************************
 *
 * 问题: weakref 和 std::reference_wrapper 有什么区别?
 * 
 * 回答: 其实这两个对象没有必然的联系, 因为它们两分别试图解决不同的场景.
 *       weakref 解决那些想调用某个对象又不想(或无法)负责销毁该对象的场景.
 *       reference_wrapper 解决 STL 容器默认是以值得形式添加到容器中, 
 *       reference_wrapper 方式减少复制行为, 降低内存开销和提高运行速度.
 *       
 ******************************************************************************/


/******************************************************************************
 *
 * weakref 是什么?
 * weakref是一个指针, 用于约束对象的有效范围,
 * 即: 当对象的引用<=0时, 任何操作都会抛出异常, 因为指针对象已经被删除(回收).
 *
 * weakref 有哪些有效成员函数?
 *       expired(): 当前对象引用数量是0则返回true(已过期), 否则返回false(未过期).
 *     use_count(): 统计当前对象产生了多少个引用.
 *         reset(): release resource, convert to null weak_ptr object.
 *          lock(): convert to shared_ptr.
 * 
 * 为什么要提供这些成员函数?
 * 只有在使用weakref的成员函数判断了引用有效之后, 
 * 再调用指针对象的具体方法, 才不会报错.
 *
 * 什么时候应该使用weakref?
 * 1. 定时任务:     
 *    那些定时任务需要调用某个指针的场景, 
 *    如果使用常规指针, 当程序退出时会导致无法正常回收指针.
 * 2. 相互内嵌:     
 *    规避 dangling pointer 问题
 * 3. 有明确要求时
 *
 ******************************************************************************/
class Person10002 {
public:
    Person10002() {
        std::cout << "Person10002 Initialize" << std::endl;
    }
    
    ~Person10002() {
        std::cout << "Person10002 Destroy" << std::endl;
    }

    void 
    show_something() {
        std::cout << "Person10002 show_something" << std::endl;
    }

};


int test_Person10002(void) {

    std::shared_ptr<Person10002> p { new Person10002 };

    std::weak_ptr<Person10002> wp = p;

    std::cout << "use_count: " << wp.use_count() << std::endl;          // use_count: 1
    if (!wp.expired()) {
        
        std::shared_ptr<Person10002> wpr = wp.lock();                   // 增加了一次引用

        std::cout << "use_count: " << wp.use_count() << std::endl;      // use_count: 2
        wpr->show_something();

    }                                                                   // 离开作用域: 删除一次引用
    std::cout << "use_count: " << wp.use_count() << std::endl;          // use_count: 1

    std::cout << "hello world!" << std::endl;
    return 0;
}


/******************************************************************************
 *
 * std::reference_wrapper 是什么?
 * std::reference_wrapper is a class template that wraps a reference in a copyable, 
 * assignable object. It is frequently used as a mechanism to store references inside 
 * standard containers (like std::vector) which cannot normally hold references. 
 *
 * std::reference_wrapper 有什么优点?
 * 不产生复制(构造函数), 因此起到减少内存开销, 减少计算开销.
 * 
 * std::reference_wrapper 有什么缺点?
 * 好像没有什么缺点哦.
 * 
 *
 ******************************************************************************/
int test_reference_wrapper10002(void) {

    int s = 10;

    {
        std::vector<int> vi;
        vi.push_back(s);

        // 指针地址:     s: 000000F9692FFBF4; 值: 10
        // 指针地址: vi[0]: 000002B5F2ECFE60; 值: 10
        std::cout << "指针地址:     s: " << &s     << "; 值: " << s     << std::endl;    
        std::cout << "指针地址: vi[0]: " << &vi[0] << "; 值: " << vi[0] << std::endl;   
        std::cout << std::endl;
    }


    // 这个代码块不能运行, 因为 STL 容器不支持直接写引用的语法: <int &>.
    // 报错信息: error C2528: 'pointer': pointer to reference is illegal
    //           see reference to class template instantiation 'std::allocator<int &>' being compiled
    // {
    //     std::vector<int &> vi;
    //     vi.push_back(s);
    //     std::cout << "指针地址:     s: " << &s << "; 值: " << s << std::endl;
    //     std::cout << "指针地址: vi[0]: " << &vi[0] << "; 值: " << vi[0] << std::endl;
    //     std::cout << std::endl;
    // }


    {
        std::vector<std::reference_wrapper<int>> vi;
        vi.push_back(s);
        // 指针地址:     s: 000000F9692FFBF4; 值: 10
        // 指针地址: vi[0]: 000002B5F2ECFE60; 值: 10
        std::cout << "指针地址:     s: " << &s           << "; 值: " << s << std::endl;
        std::cout << "指针地址: vi[0]: " << &vi[0].get() << "; 值: " << vi[0] << std::endl;
        std::cout << std::endl;
    }

    return 0;
}