#include<iostream>
#include <stack>
#include <iterator>
#include <map>
#include <sstream>
#include <cassert>
#include <vector>
#include <stdexcept>
#include <cmath>
using namespace std;
 

template<typename IT>
double evaluateRPN(IT it, IT end){

    stack<double> st;

    map<string,double(*)(double,double)> ops{
        {"+",[](double a, double b){ return a + b;}},
        {"-",[](double a, double b){ return a - b;}},
        {"*",[](double a, double b){ return a * b;}},
        {"/",[](double a, double b){ return a / b;}}
    };

    auto pop_stack([&](){auto r (st.top());st.pop();return r;});

    for(; it!=end;++it){
        stringstream ss {*it};
        if(double val;ss>>val){
            st.push(val);
        }
        else{
            assert(st.size()>=2);

            const auto r{pop_stack()};
            const auto l{pop_stack()};

            try
            {
                st.push(ops.at(*it)(r,l));
            }
            catch(const std::out_of_range& e)
            {
                throw invalid_argument(*it);
            }
            
            return st.top();
        }
    }
}
int main()
{
    try
    {
        cout << evaluateRPN(istream_iterator<string>{cin},{})<<'\n';
    }
    catch(const std::invalid_argument& e)
    {
        std::cout<<"Invalid operator " << e.what() << '\n';
    }
    
}