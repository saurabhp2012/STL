#include<iostream>
#include <set>
#include <string>
#include<iterator>
using namespace std;
 
int main()
{
    set<string> s;
    istream_iterator<string> it {cin};
    istream_iterator<string> end;

    copy(it,end,inserter(s,s.end()));

    for(const auto word:s){
        cout<<word<<", ";
    }
    cout<<'\n';

    return 0;
}