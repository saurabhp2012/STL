#include<iostream>
#include<map>
using namespace std;
 
template<typename M>
void print(const M& m){
    cout<<"Race Placement:\n";
    for(const auto& [placement, driver]:m){
        cout<<placement<<": "<<driver<<'\n';
    }
}
int main()
{
    map<int,string> race_placement{
        {1, "Mario"},{2,"Luigi"},{3,"Bowser"},{4,"Peach"},{5,"Yoshi"}
    };
    print(race_placement);

    {
        auto a(race_placement.extract(3));// (C++17)extracts removes item from map without any allocation side effects 
        auto b(race_placement.extract(5));

        swap(a.key(),b.key());

        race_placement.insert(std::move(a));//(C++17) new overloaded insert accepts the handle of extracted nodes in order to insert them without touching the allocator
        race_placement.insert(std::move(b));


    }
    print(race_placement);
    return 0;
}