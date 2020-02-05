#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
void palindroomCheck(string woord){
    string normaal = woord;
    // gevonden via stackoverflow, erg mooie manier om een string te reversen. Kon geen library vinden die dit beter kon, geen enkele library nodig. https://stackoverflow.com/questions/4951796/how-to-reverse-an-stdstring
    string reversed(normaal.rbegin(), normaal.rend());
    if (normaal.compare(reversed) == 0)
        cout<<"Dit woord is wel een palindroom.";
    else
        cout<<"Dit woord is geen palindroom.";
}

int main(){
    string woord;
    cout<<"Vertel, welk woord wil je checken of het een palindroom is, taco's en katten zijn cool.";
    cin>>woord;
    palindroomCheck(woord);
}

