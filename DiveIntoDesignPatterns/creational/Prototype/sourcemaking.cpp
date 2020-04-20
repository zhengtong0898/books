#include <iostream>
#include <ostream>
#include <string>


class Sourcemakeing {
private:
    std::string url;
public:
    Sourcemakeing(std::string s): url(s) {}
    friend std::ostream & operator<<(std::ostream & os, const Sourcemakeing & s);
};


std::ostream & operator<<(std::ostream & os, const Sourcemakeing & s) {
    os << "<Sourcemakeing url=\"" << s.url << "\">";
    return os;
}


class Prototype {
private:
    std::string     pattern_name;
    std::string     index;
    Sourcemakeing & sm;
public:
    Prototype(Sourcemakeing & s): sm(s), pattern_name("prototype"), index("4") {}
    Prototype(const Prototype & prototype): sm(prototype.sm) {
        this->index = prototype.index;
        this->pattern_name = prototype.pattern_name;
    }
    friend std::ostream & operator<<(std::ostream & os, const Prototype & pt);
};


std::ostream & operator<<(std::ostream & os, const Prototype & pt) {
    os << "<Prototype pattern_name=\""   << pt.pattern_name 
       << "\" index=\"" << pt.index << "\" sm=" << pt.sm << ">";
    return os;
}


int test_prototype(void) {

    Sourcemakeing sm("https://sourcemaking.com/design_patterns/prototype/python/1");
    Prototype pt(sm);
    Prototype pt2(pt);

    std::cout << sm << std::endl;
    std::cout << pt << std::endl;
    std::cout << pt2 << std::endl;

    return 0;
}