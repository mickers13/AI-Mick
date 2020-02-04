#include <iostream>
using namespace std;
int main() {
    char c;
    cout<<"geef een character: ";
    cin>>c;
    cout<<c<<" + 32 ="<< int(c)+32;
    cout<<c<<" + 32 ="<< char(int(c)+32);
}