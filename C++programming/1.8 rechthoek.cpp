#include <iostream>
#include <string>
using namespace std;
int main() {
    int breedte_pyramide = 0;
    int c = 0;
    cout<<"Hoe groot wil je je pyramide hebben? Voer alleen cijfers in en geen andere symbolen!";
    cin>>breedte_pyramide;
    for(int c = 0; c<=breedte_pyramide; c++){
        cout<<endl;
        for(int d = 0; d<=c; d++){
            cout<<"X";
        }
    }
};