#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int count(vector<int> lijst,int length,int character){
    int frequentie = 0;
    
    for(int i=0; i<=length; i++){
        if (lijst[i] == character){
            frequentie++ ;
        }

    }
    
    return frequentie;
}

int difference(vector<int> lijst,int length){
    int temp = 0;
    int difference = 0;
    int max_diff = 0;
    vector<int> arrays;
    for(int i=1; i<length; i++){
        difference = abs(lijst[i] - lijst[i-1]);
        if (difference > max_diff){
            max_diff = difference;
        }
    }
    return max_diff;
}
bool binarycheck(vector<int> lijst,int length){
    if(count(lijst, length, 1) >= count(lijst, length, 0)){
        if(count(lijst, length, 0) <= 12){
            return true;
        }
    }else{
        return false;
    }
}

int main(){


    vector<int> lijst = {1,1,0,0,0,0,0,0,8,8};
    int sizeLijst= lijst.size();
    
    int max_diff = difference(lijst,sizeLijst);
    cout << "Het maximale verschil is: "<< max_diff<< endl;
    
    cout << "Klopt het dat de lijst voldoet aan de eisen van de opdracht op canvas?" ;
    if(binarycheck(lijst,sizeLijst)==0){
        cout<<"Nee dat klopt niet";
        }else{
            cout<<"Ja dat klopt.";
            }
}
