#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;



int main() {
    int hoeveel = 0;
    int temp= 0;
    int sum = 0;
    
    vector<int> lijstjecijfers;
    cout<<"hoeveel cijfers wil het gemiddelde van hebben?: ";
    cin>>hoeveel;
    for(int i = 0;i < hoeveel;i++){
        cout<<"voer een cijfer in. :";
        cin>>temp;
        lijstjecijfers.push_back(temp);
        
    }
    int lengte = lijstjecijfers.size();
    for(int i = 0;i < lengte;i++){
        sum += lijstjecijfers[i];
    }
    cout<<"Jou gemiddelde is: "<<sum/lengte;

}
