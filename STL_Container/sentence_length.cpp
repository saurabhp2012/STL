#include<iostream>
#include <iterator>
#include <algorithm> 
#include <map>
using namespace std;
 
string filterWhiteSpace(const string& s){
    const char* ws {" \r\n\t"};
    auto a (s.find_first_not_of(ws));
    auto b (s.find_last_not_of(ws));

    if(a==s.string::npos) return {};
    
    return s.substr(a,b);

}

multimap<size_t,string> getSentanceStats(const string & content){

    multimap<size_t,string> ret;

    const auto end_it(end(content));
    auto it1 (begin(content));
    auto it2 (find(it1,end_it,'.'));

    while(it1!=end_it && distance(it1,it2)>0){

        string s {filterWhiteSpace({it1,it2})};

        if(s.length()>0){
            const auto words (count(begin(s),end(s),' ')+1);
            ret.emplace(make_pair(words,std::move(s)));
        }

        it1 = next(it2,1);
        it2 = find(it1,end_it,'.');

    }
    return ret;

}
int main()
{
    cin.unsetf(ios::skipws);
    string content {istream_iterator<char>{cin},{}};

    for(const auto & [word_count,sentence]:getSentanceStats(content)){
        cout<<word_count<<" word: "<<sentence<<'\n';
    }
}