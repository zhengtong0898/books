#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <memory>
#include <type_traits>


class Localizer {
public:
    virtual ~Localizer() {}
    virtual std::string localize(std::string msg) = 0;
};


class GreekLocalizer: public Localizer {
private:
    std::map<std::string, std::string> translations;
public:
    GreekLocalizer(): translations{ {"dog", "σκύλος"}, {"cat", "γάτα"} } {}
    std::string localize(std::string msg) {
        auto found = this->translations.find(msg);
        if (found == this->translations.end()) return msg;
        return this->translations[msg];
    }
};


class EnglishLocalizer : public Localizer {
public:
    std::string localize(std::string msg) {
        return msg;
    }
};


// TODO: 使用typeid的方式来写这个函数.
std::shared_ptr<Localizer> get_localizer(std::string key) {
    static std::map<std::string, std::function<std::shared_ptr<Localizer>()>> localizer{
        {"Greek",   []() -> std::shared_ptr<Localizer> { return std::shared_ptr<Localizer>(new GreekLocalizer);   } },
        {"English", []() -> std::shared_ptr<Localizer> { return std::shared_ptr<Localizer>(new EnglishLocalizer); } }
    };
    return localizer[key]();
}


int test_Localizer(void) {

    std::cout << typeid("GreekLocalizer").name() << std::endl;

    std::cout << get_localizer("Greek")->localize("dog") << std::endl;
    std::cout << get_localizer("English")->localize("dog") << std::endl;
    std::cout << "main" << std::endl;
    return 0;
}