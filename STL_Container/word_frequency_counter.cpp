#include<iostream>
#include<map>
#include <vector>
#include<algorithm>
#include<iomanip>

using namespace std;
 
string filterPunctuation(const string& s){

    const char* forbidden (".,;: ");
    const auto idx_start (s.find_first_not_of(forbidden));
    const auto idx_end (s.find_last_not_of(forbidden));

    return s.substr(idx_start,idx_end - idx_start + 1);

}
int main()
{
    map<string,size_t> words;
    int max_word_len {0};

    string s;
    while(cin>>s){
        auto filtered (filterPunctuation(s));
        max_word_len = max<int>(max_word_len,filtered.length());
        ++words[filtered];
    }
    
    vector<pair<string,size_t>> word_counts;
    word_counts.reserve(words.size()); // preallocates memory in the vector to accommodate the expected number of elements.
 //optimizes the vector's capacity to reduce reallocations and improve performance.

    move(begin(words),end(words),back_inserter(word_counts));//efficiently transferring ownership of the elements rather than making copies
   //back_inserter iterator is used as the destination iterator to insert the elements into word_counts. 
   //The back_inserter iterator allows adding elements at the end of the vector.

//move operation modifies the original words map. After the move, the words map will be empty.
// The elements are effectively "moved" or transferred from words to word_counts rather than being copied.
//This can be more efficient when dealing with large or expensive-to-copy elements.

sort(begin(word_counts),end(word_counts),[](const auto& a, const auto& b){return a.second>b.second;});

cout<<"# "<<setw(max_word_len)<< "<WORD>"<<" #<COUNT>\n";

for(const auto & [word,count]:word_counts){
    cout<<setw(max_word_len+2)<<word<<" #"<<count<<'\n';
}
}