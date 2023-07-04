#include<iostream>

class fitbit{
    size_t i{0}; //index
    size_t a{0};
    size_t b{1}; //holds last two fibannaci values
    public:
        fitbit() = default;
        explicit fitbit(size_t i_):i(i_){}

        size_t operator* (){return b;}
        constexpr fitbit& operator++(){
            const size_t old_b {b};
            b+=a;
            a = old_b;
            ++i;
            return *this;
            //1 2 3 5 8 13

        }
        bool operator !=(const fitbit& other){return i!=other.i;}

};

class fib_range{
    size_t end_n;
    public:
        fib_range(size_t end_n_):end_n(end_n_){}

        fitbit begin() {return fitbit{};}
        fitbit end() {return fitbit{end_n};}

};
 
int main()
{
    for(size_t i:fib_range(10)){
        std::cout<<i<<", ";
    }
    std::cout<<'\n';
}