#include<iostream>
using namespace std;

class Test{
    int one{1};
    int two{2};

    public:
        void run(){
            int three {3};
            int four {4};

            auto pLambda = [this, three,four](){
                one = 11;
                cout<<three<<", "<<four<<endl;
                cout<<one<<endl;
            };

            pLambda();
        }
}; 
int main()
{
    Test test;
    test.run();
    return 0;
}