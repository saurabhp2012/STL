#include<iostream>
#include<fstream>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;
 
template<typename T>
size_t word_count(T &is){

    return distance(istream_iterator<string>{is},{});
    //disctance calculates how many increamenting steps are required to go from one iterating posititon to other
}
int main(int argc, char **argv)
{
    size_t wc;
    if(argc==2){
        ifstream ifs {argv[1]};
        wc = word_count(ifs);
    }
    else{
        wc = word_count(cin);
    }

    cout<<"There are "<<wc<<" words\n";
}

