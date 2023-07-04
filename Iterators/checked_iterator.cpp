#include<iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<int> v {1,2,3};
    v.shrink_to_fit(); // here size shrinks to 3

    auto it (begin(v));
    cout<<*it<<endl;
    v.push_back(123);// here new memory is allocated as size is 3 & we are pushing more elements
                    //therefore it now will still point to old memory
                    //can be checked using preproccessor macro  D_GLIBCXX_DEBUG
    
    cout<<*it<<endl;
}