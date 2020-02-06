#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main() {
    cout<<"probeer een cijfer te raden tussen de 0 en de 10"<<endl;
    srand (time(NULL));
    int geheimcijfer = rand() % 10 + 1;
    
    int poging;
    while(1){

        cout<<"voer een cijfer in tot je het goed hebt:"<<endl;
        cin>>poging;
        if( poging == geheimcijfer ){
            
            cout<<"Whooo het is gelukt!";
            break;

        } else {

            cout<<"Helaas, probeer opnieuw.";

        }
    }


}
