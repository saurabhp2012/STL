#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<cassert>

using namespace std;
 
void insertSorted(vector<string>& v, const string& word){

    const auto insert_pos( lower_bound(begin(v),end(v),word));\
    v.insert(insert_pos,word);
}
int main()
{
    vector<string> v {"some","random","word","unsorted"};

    assert(false==is_sorted(begin(v),end(v)));
    sort(begin(v),end(v));
    assert(true==is_sorted(begin(v),end(v)));

    insertSorted(v,"foo");
    insertSorted(v,"zoo");

    for(const auto& w:v){
        cout<<w<<" ";
    }
    cout<<'\n';


    return 0;
}