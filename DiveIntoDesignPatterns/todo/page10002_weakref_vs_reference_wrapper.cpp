#include <iostream>
#include <vector>


/*******************************************************************************
 *
 * ����: weakref �� std::reference_wrapper ��ʲô����?
 * 
 * �ش�: ��ʵ����������û�б�Ȼ����ϵ, ��Ϊ�������ֱ���ͼ�����ͬ�ĳ���.
 *       weakref �����Щ�����ĳ�������ֲ���(���޷�)�������ٸö���ĳ���.
 *       reference_wrapper ��� STL ����Ĭ������ֵ����ʽ��ӵ�������, 
 *       reference_wrapper ��ʽ���ٸ�����Ϊ, �����ڴ濪������������ٶ�.
 *       
 ******************************************************************************/


/******************************************************************************
 *
 * weakref ��ʲô?
 * weakref��һ��ָ��, ����Լ���������Ч��Χ,
 * ��: �����������<=0ʱ, �κβ��������׳��쳣, ��Ϊָ������Ѿ���ɾ��(����).
 *
 * weakref ����Щ��Ч��Ա����?
 *       expired(): ��ǰ��������������0�򷵻�true(�ѹ���), ���򷵻�false(δ����).
 *     use_count(): ͳ�Ƶ�ǰ��������˶��ٸ�����.
 *         reset(): release resource, convert to null weak_ptr object.
 *          lock(): convert to shared_ptr.
 * 
 * ΪʲôҪ�ṩ��Щ��Ա����?
 * ֻ����ʹ��weakref�ĳ�Ա�����ж���������Ч֮��, 
 * �ٵ���ָ�����ľ��巽��, �Ų��ᱨ��.
 *
 * ʲôʱ��Ӧ��ʹ��weakref?
 * 1. ��ʱ����:     
 *    ��Щ��ʱ������Ҫ����ĳ��ָ��ĳ���, 
 *    ���ʹ�ó���ָ��, �������˳�ʱ�ᵼ���޷���������ָ��.
 * 2. �໥��Ƕ:     
 *    ��� dangling pointer ����
 * 3. ����ȷҪ��ʱ
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
        
        std::shared_ptr<Person10002> wpr = wp.lock();                   // ������һ������

        std::cout << "use_count: " << wp.use_count() << std::endl;      // use_count: 2
        wpr->show_something();

    }                                                                   // �뿪������: ɾ��һ������
    std::cout << "use_count: " << wp.use_count() << std::endl;          // use_count: 1

    std::cout << "hello world!" << std::endl;
    return 0;
}


/******************************************************************************
 *
 * std::reference_wrapper ��ʲô?
 * std::reference_wrapper is a class template that wraps a reference in a copyable, 
 * assignable object. It is frequently used as a mechanism to store references inside 
 * standard containers (like std::vector) which cannot normally hold references. 
 *
 * std::reference_wrapper ��ʲô�ŵ�?
 * ����������(���캯��), ����𵽼����ڴ濪��, ���ټ��㿪��.
 * 
 * std::reference_wrapper ��ʲôȱ��?
 * ����û��ʲôȱ��Ŷ.
 * 
 *
 ******************************************************************************/
int test_reference_wrapper10002(void) {

    int s = 10;

    {
        std::vector<int> vi;
        vi.push_back(s);

        // ָ���ַ:     s: 000000F9692FFBF4; ֵ: 10
        // ָ���ַ: vi[0]: 000002B5F2ECFE60; ֵ: 10
        std::cout << "ָ���ַ:     s: " << &s     << "; ֵ: " << s     << std::endl;    
        std::cout << "ָ���ַ: vi[0]: " << &vi[0] << "; ֵ: " << vi[0] << std::endl;   
        std::cout << std::endl;
    }


    // �������鲻������, ��Ϊ STL ������֧��ֱ��д���õ��﷨: <int &>.
    // ������Ϣ: error C2528: 'pointer': pointer to reference is illegal
    //           see reference to class template instantiation 'std::allocator<int &>' being compiled
    // {
    //     std::vector<int &> vi;
    //     vi.push_back(s);
    //     std::cout << "ָ���ַ:     s: " << &s << "; ֵ: " << s << std::endl;
    //     std::cout << "ָ���ַ: vi[0]: " << &vi[0] << "; ֵ: " << vi[0] << std::endl;
    //     std::cout << std::endl;
    // }


    {
        std::vector<std::reference_wrapper<int>> vi;
        vi.push_back(s);
        // ָ���ַ:     s: 000000F9692FFBF4; ֵ: 10
        // ָ���ַ: vi[0]: 000002B5F2ECFE60; ֵ: 10
        std::cout << "ָ���ַ:     s: " << &s           << "; ֵ: " << s << std::endl;
        std::cout << "ָ���ַ: vi[0]: " << &vi[0].get() << "; ֵ: " << vi[0] << std::endl;
        std::cout << std::endl;
    }

    return 0;
}