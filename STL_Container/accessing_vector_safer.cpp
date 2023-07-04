#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    const size_t container_size{1000};
    vector<int> v(container_size,456);

    cout<<"Out of range element value: "<<v[container_size+20]<<'\n';

    cout<<"Out of range element value: "<<v.at(container_size+20)<<'\n';

}