#include<iostream>
#include <functional>
#include<list>
#include<map>
using namespace std;

struct billionare{
    string name;
    double dollars;
    string country;
}; 

int main()
{
    list<billionare> billionares{
        {"Bill Gates",86.0,"USA"},
        {"Warren Buffet",75.6,"USA"},
        {"Jeff Bezos",72.8,"USA"},
        {"Amego Ortego",71.6,"Spain"},
        {"Carlos Slim",56.5,"Mexico"},
        {"Wang Jianlan",31.3,"China"}


    };

    map<string,pair<const billionare,size_t>> m;

    for(const auto& b: billionares){
        auto [iterator, success] = m.try_emplace(b.country,b,1);// better then checking then insert

        if(!success){ // if value pair already present in map then pair is not constructed hecne save runtime cost of copying
            iterator->second.second+=1;
        }
    }

for(const auto& [key, value]:m){
    const auto &[b, count] = value;
    cout<<b.country<<":"<<count<<" billionaries. Richest is "<<b.name<<" with "<<b.dollars<<" B$\n";
}
    return 0;
}