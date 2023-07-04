#include<iostream>
using namespace std;
 
int main()
{
    int one = 1;
    int two  = 2;
    int three = 3;
    
    //capture one and two by value
    [one,two](){cout<<one<<", "<<two<<endl;}();

    //capture all local variable by value
    [=](){cout<<one<<", "<<two<<endl;}();

    //Default capture all local variable by value, but capture three by reference
    [=,&three](){cout<<one<<", "<<two<<", "<<three<<endl;three=7;}();

    cout<<three<<endl;

    //Default capture all local variable by reference,
    [&](){cout<<one<<", "<<two<<", "<<three<<endl;three=7;two=4;}();
    cout<<two<<endl;

    //Default capture all local variable by reference, but capture three by value
    [&,three](){cout<<one<<", "<<two<<", "<<three<<endl;one=9;}();
    cout<<one<<endl;


}