#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
 
bool check(string& test){
    return test.size()==3;
}
class Check{
    public:
        bool operator()(string &test){
            return test.size()==3;
        }
} check1;

//standard function type
//function<return type(param passed)> func name
void run(function<bool(string &test)> check2){
    string s = "dog";
    cout<<"from run() "<<check2(s)<<endl;
}
int main()
{
    vector<std::string> v{"one","two","three"};
    int size = 3;
    auto pLambda = [size](string& test){return test.size()==size;};
    std::cout<<count_if(begin(v),end(v),pLambda);
    std::cout<<endl;
    std::cout<<count_if(begin(v),end(v),check);
    std::cout<<endl;
    std::cout<<count_if(begin(v),end(v),check1);
    std::cout<<endl;
    run(pLambda);
    run(check);
    run(check1);
    function<int(int,int)> add = [](int a, int b){return a+b;};
    cout<<add(7,3)<<endl;

    return 0;
}