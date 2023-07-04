#include <iostream>
#include<vector>
//#include<algorithm>

using namespace std;

int main(){

    vector<int> v {1,2,3,2,5,2,6,2,4,8};
    {
        const auto new_end (remove(begin(v),end(v),2));
        v.erase(new_end,end(v));
    }

    for(auto it: v){
        cout<<it<<", ";
    }
    cout<<'\n';

    {
        const auto odd ([](int i){ return i%2!=0;}); //predicate function

        v.erase(remove_if(begin(v),end(v),odd),end(v));
            //size still same
    }

    v.shrink_to_fit(); //allocate new memory & copy old data to this memory, hence shrinked 

        for(auto it: v){
        cout<<it<<", ";
    }
    cout<<'\n';

}