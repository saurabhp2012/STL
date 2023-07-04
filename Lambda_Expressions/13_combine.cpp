#include <iostream>
#include <functional>
#include <string>
#include <iterator>
#include <algorithm>

static bool begin_with_a (const std::string& s){

    return s.find("a")==0;
}

static bool end_with_b (const std::string& s){

    return s.rfind("b")==s.length()-1;
}

template<typename A, typename B, typename F>
auto combine(F binary_func,A a, B b){

    return [=](auto param){return binary_func(a(param),b(param));};
}

int main(){

    auto a_xx_b (combine(std::logical_and<>{},begin_with_a,end_with_b));

    std::copy_if(std::istream_iterator<std::string>{std::cin},{},
        std::ostream_iterator<std::string>{std::cout,", "},
        a_xx_b);
    std::cout<<'\n';
}
