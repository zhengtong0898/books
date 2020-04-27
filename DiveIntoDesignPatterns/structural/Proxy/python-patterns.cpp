#include <iostream>


class Subject {
public:
    virtual 
    ~Subject() {}

    virtual void 
    do_the_job(std::string user) = 0;
};


class RealSubject : public Subject {
public:
    void 
    do_the_job(std::string user) {
        std::cout << "I am doing the job for " << user << std::endl;
    }
};


class Proxy : public Subject {
private:
    Subject * real_subject;
public:
    Proxy() {
        real_subject = new RealSubject;
    }

    void
    do_the_job(std::string user) {
        std::cout << "[log] Doing the job for {user} is requested." << std::endl;
        if (user == "admin") this->real_subject->do_the_job(user);
        else std::cout << "[log] I can do the job just for `admins`." << std::endl;
    }
};


int test_proxy222(void) {

    Proxy p;
    p.do_the_job("admin");
    // [log] Doing the job for {user} is requested.
    // I am doing the job for admin

    p.do_the_job("anonymous");
    // [log] Doing the job for {user} is requested.
    // [log] I can do the job just for `admins`.

    RealSubject rs;
    rs.do_the_job("admin");
    // I am doing the job for admin

    rs.do_the_job("anonymous");
    // I am doing the job for anonymous

    return 0;
}