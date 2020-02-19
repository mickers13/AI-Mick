#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>   
#include <time.h>     
#include <stdio.h>
#include <bits/stdc++.h> 
#include <algorithm> 
using std::vector;
using std::string;
using std::endl;
using std::cout;
// header files zelf gemaakt voor minder grote stapels code (700 lines als het 1 file was.)
#include "Functions.h"


// helaas een Bug in deze versie telt hij af inplaatsvan dat hij het midden pakt.
// inplaatsvan dat hij elke loop opnieuw de mogenlijke berekend gaat hij de lijs tmet mogenlijke af.

/*Ik doe een paar gekke dingen, die ik zelf erg leuk vond om uit te zoeken om een leuke Commandline game versie van mastermind te maken ( kleurtjes in CMD enzo. ). paar voorbeelden voor de bronnen:
https://en.wikipedia.org/wiki/ANSI_escape_code ik heb deze bron gedeeld met Ayoub.
http://www.cplusplus.com      goede uitleg voor functies met klein voorbeeld.
https://stackoverflow.com/questions/2551775/appending-a-vector-to-a-vector
https://en.cppreference.com/w/cpp/algorithm/next_permutation`
https://www.youtube.com/watch?v=7IQHYbmuoVU
https://www.geeksforgeeks.org/print-all-the-permutation-of-length-l-using-the-elements-of-an-array-iterative/ ( code heb ik gebruikt als template en aangepast naar wat ik wil. )
https://www.systutorials.com/convert-string-to-int-and-reverse/
*/


string generateSecret(){
    string secret = "";
    int secretnummer;
    string listofcolours = "RGBCMY";
    //maak random seed
    srand (time(NULL));

    // kies een random letter uit list of colours tot het even lang is aan de lengte die nodig is.
    char secretletter ;
    for(int i = 0 ; i < g_amountOfColumns; i++){
        secretnummer = rand() % listofcolours.size()-1 + 1;
        secretletter = listofcolours[secretnummer];
        cout<< secretletter;
        //voeg toe aan secret
        secret.push_back(secretletter);
    }
    return secret;
}

int main() {

  
    startSetup(4);
    system("CLS");
    string secret = generateSecret();
    cout<<"het geheim niet door vertellen:"<< secret;
    char test;
    vector<vector<char>> data = {vector<char>{}};
    string newestCode;
    startoutrow(data);
    // uncomment voor player
    //USER PLAYS MODUS:
    // newestCode = writeNewData(data,false);
    // printrow(data, feedback(newestCode, secret,data, true));
    
    // comment voor player modus.
    //AI PLAYS MODUS: 
    vector<char> newestFeedback;
    while(1){
        newestCode = writeNewData(data,newestFeedback,true);
        newestFeedback = feedback(newestCode, secret,data, true);
        printrow(data, newestFeedback);
        if(newestFeedback[0] == '4'){
            cout<<"whoo gewonnen!";
            break;
        }
    }
    

    return 0;
}