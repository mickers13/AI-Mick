#include <iostream>
using namespace std;
int main() {
    int breedte_pyramide = 0;
    int breedteCounter = 0;
    cout<<"Hoe groot wil je je pyramide hebben? Voer alleen cijfers in en geen andere symbolen!";
    cin>>breedte_pyramide;
    for(int breedteCounter = 0; breedteCounter<=breedte_pyramide; breedteCounter++){
        cout<<endl;
        for(int lengteCounter = 0; lengteCounter<=breedteCounter; lengteCounter++){
            cout<<"X";
        }
    }
    for(int breedteCounter2 = breedte_pyramide-1; breedteCounter2>0; breedteCounter2--){
        cout<<endl;
        for(int lengteCounter = 0; lengteCounter<=breedteCounter2; lengteCounter++){
            cout<<"X";
        }
    }
}

