#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <functional>

template<typename Container>
static auto consumer(Container& container) {
    return [&](typename Container::value_type value) { //returns a function object that captures  that container by reference
        container.push_back(value); // function object itself accepts int parameters, append that int into conainer that it captures
    };
}

template<typename Container>
static void print (const Container &c){
    for(auto i:c){
        std::cout<<i<<", ";
    }
    std::cout<<'\n';
}

int main(){

    std::deque<int> d;
    std::list<int> l;
    std::vector<int> v;
    
    const std::vector<std::function<void(int)>> consumers {consumer(d),consumer(l),consumer(v)};

    for(size_t i = 0;i<10;i++){
        for(auto & consume:consumers){
            consume(i);
        }
    }

    print(d);
    print(l);
    print(v);
}