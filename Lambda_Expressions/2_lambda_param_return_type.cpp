#include<iostream>
using namespace std;
 
void test(void(*greet)(string)){
    greet("Bob");
}
void runDivide(double (*divide)(double a, double b)){
    auto rVal = divide(9,3);
    cout<<rVal<<endl;
}
int main()
{
   auto pGreet = [](string name){cout<<"Hello "<<name<<endl;};
   pGreet("abd");
   test(pGreet);

    //trailing return type
   auto pDivide = [](double a, double b)->double{
    if(b==0) return 0;
    return a/b;
   };
   cout<<pDivide(10.0,2.0)<<endl;
   cout<<pDivide(10.0,0)<<endl;
   runDivide(pDivide);

}