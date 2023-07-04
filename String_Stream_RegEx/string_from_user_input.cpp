#include <iostream>

using namespace std;

int main(){
    cout<<"Please Enter two numbers: \n";
    int x;double y;
    if(cin>>x>>y){
        cout<<"You entered: "<<x<<" and"<<y<<'\n';

    }
    else{
        cout<<" Oh no, that did not go well\n";
        cin.clear(); //drop all input 
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // Ignore remaining characters until a new line is encountered
    }

    cout<<"now please enter some comma-separated names:\n";
    //cin >> ws is used as the input stream before getline(). 
    //The ws manipulator is used to skip leading whitespace before reading each line.
    // This ensures that any trailing whitespace from previous inputs is ignored.
    
    //.getline(input_stream, string_variable, delimiter);

    for(string s;getline(cin>>ws,s,',');){
        if(s.empty()){break;}
        cout<<"name: \""<<s<<"\"\n";
    }
}