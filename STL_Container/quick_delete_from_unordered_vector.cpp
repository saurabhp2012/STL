#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 template<typename T>
 void quickRemoveAt(vector<T>& v, size_t index){
    //O(1) remove
    if(index<v.size()){
        v.at(index) = move(v.back()); //take last value & overwrite at which needs to be removed
        v.pop_back();
    }
 }
template<typename T>
void quickRemoveAt(vector<T>& v, typename vector<T>::iterator it){
    //O(1)
    if(it!=end(v)){
        *it = move(v.back());
        v.pop_back();
    }
 }
int main()
{
    vector <int> v {123,456,789,100,200};

    quickRemoveAt(v,2);//index as param
    
    for(auto it:v) cout<<it<<", ";
    cout<<'\n';

    quickRemoveAt(v,find(begin(v),end(v),123));//iterator as param

    for(auto it:v) cout<<it<<", ";
    cout<<'\n';
}