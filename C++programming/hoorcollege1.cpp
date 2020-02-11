#include <iostream>
using namespace std;


int max (int x,int y){
    if( x >y ) {
        return x;
    }else {
        return y;
    }
    
}


int main()
{
    int x= 1;
    int y= 3;
    cout<<max(x,y);
    /* code */
    return 0;
}
