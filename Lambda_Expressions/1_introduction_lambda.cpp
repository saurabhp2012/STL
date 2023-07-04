#include<iostream>
using namespace std;
 
void test(void (*pFunc)()){
    pFunc();
}
int main()
{
    auto func = [](){cout<<"Hello";};

    func();
    cout<<endl;
    test(func);

    cout<<endl;

    test([](){cout<<"Hello";});

    return 0;
}