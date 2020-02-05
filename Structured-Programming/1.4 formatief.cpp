#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
bool palindroomCheck(string woord){
    string normaal;
    reverse(woord.begin(),woord.end());
    if (normaal == woord){
        cout<< woord<<endl;
        cout<<"jaaaaaaa hoor. Dit is palindroom.";
    }   else{
        cout<< woord<<endl;
        cout<<"Nee helaas. Geen palindroom, probeer het een andere keer weer!";
    }
    


    ;
    
}

int main(){
    string woord;
    cout<<"Vertel, welk woord wil je checken of het een palindroom is, taco's en katten zijn cool.";
    cin>>woord;
    palindroomCheck(woord);
}

