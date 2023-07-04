#include<iostream>
using namespace std;
 
int main()
{
    int cats = 5;
    //capture by value, can't change lvalue->can use mutable
    [cats]() mutable {
        cats = 8;
        cout<<cats<<endl;
    }();
    return 0;
}