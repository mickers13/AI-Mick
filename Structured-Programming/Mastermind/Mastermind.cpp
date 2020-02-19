#include <vector>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>   
#include <time.h>     
#include <stdio.h>
#include <bits/stdc++.h> 
#include <algorithm> 
using std::vector;
using std::string;
using std::endl;
using std::cout;
// header file zelf gemaakt voor minder grote stapels code:
#include "Functions.h"



/*Ik doe een paar gekke dingen, die ik zelf erg leuk vond om uit te zoeken om een leuke Commandline game versie van mastermind te maken ( kleurtjes in CMD enzo. ). paar voorbeelden voor de bronnen:
https://en.wikipedia.org/wiki/ANSI_escape_code ik heb deze bron gedeeld met Ayoub.
http://www.cplusplus.com      goede uitleg voor functies met klein voorbeeld.
https://stackoverflow.com/questions/2551775/appending-a-vector-to-a-vector
https://en.cppreference.com/w/cpp/algorithm/next_permutation`
https://www.youtube.com/watch?v=7IQHYbmuoVU
https://www.geeksforgeeks.org/print-all-the-permutation-of-length-l-using-the-elements-of-an-array-iterative/ ( code heb ik gebruikt als template en aangepast naar wat ik wil. )
https://www.systutorials.com/convert-string-to-int-and-reverse/
*/

void overwrite(string phrase){
    //overschrijf de vorige lijn met een nieuwe zin. handig voor text ( + veel spaties om volledig te overschrijven)
    cout<<"\033[F\r"<<phrase<<"                                                                                     \n";
}

int checkWhite(string code, string secret){
    int white = 0;
    for(int i = 0; i < code.size(); i++){
        if(code[i] == secret[i]){
            white++;
        }
    }
    return white;
}

int checkBlack(string code, string secret){
    int black = 0;
    string tcode = code;
    string tsecret = secret;
    for(int i = 0; i < tcode.size(); i++){
        std::size_t found = tsecret.find_first_of(tcode[i]);
        if ((found!=std::string::npos)){
            black++;
            //verwijder zodat hij deze specifieke niet nog een keer kan controleren.
            tsecret.erase (tsecret.begin()+found);
    }
    }

    return black;
    
}

int convertStringToInt(string code){
    int nummer = std::stoi(code);
    return nummer;
}
// string zoekBitWaarde(int gemiddelde){
//     while(1){
//         for(int i = 0 ; i < g_possibleGuesses.size(); i++){
//             if(gemiddelde ==convertStringToInt(g_possibleGuesses[i])){
//                 return g_possibleGuesses[i];
//             }
//         }
//     gemiddelde+1;
//     }
// }

int berekenGemGuess(){
    int totaal = 0;
            for(int i = 0; i < g_possibleGuesses.size()-1 ; i++){
                totaal += convertStringToInt(g_possibleGuesses[i]);
            }
            int gemiddelde = totaal / g_possibleGuesses.size();
            return gemiddelde;
}

string covertToLen(int n, int arr[], int len, int L, int j ) { 
    string woord="";
    // Sequence is of length L 
    for (int i = 0; i < L; i++) { 
        // Print the ith element 
        // of sequence 
        switch(arr[n % len]){
                case 1 :
                woord.push_back( 'R' ); 
                //cout<<"R";
                break;
                case 2 :
                woord.push_back( 'G' );
                //cout << "G" ; 
                break;
                case 3 :
                woord.push_back( 'B' );
                //cout << "B" ; 
                break;
                case 4 :
                woord.push_back( 'C' );
                //cout << "C" ; 
                break;
                case 5 :
                woord.push_back( 'M' );
                //cout << "M" ; 
                break;
                case 6 :
                woord.push_back( 'Y' );
                //cout << "Y" ; 
                break;
        
                }

        n /= len; 
    } 
    

    return woord;
} 
  
vector<string> print(int arr[],int len,int L) { 
    vector<string> lijst={} ;
    string woordReturn = "";

    for (int i = 0; i < (int)pow(len, L); i++) { 
        woordReturn = covertToLen(i, arr, len, L, i); 

        lijst.push_back(woordReturn);

    } 
    return lijst;
} 
  
vector<string> generateAllCodes(){ 
    vector<string> lijst ={};
    int arr[] = { 1, 2, 3 ,4 , 5, 6}; 
    int len = sizeof(arr) / sizeof(arr[0]); 
    int L = 4; 
  
    lijst = print(arr, len, L); 
        
    return lijst; 
} 

vector<char> feedback(string code,string secret,vector<vector<char>> &data,bool write){
    // geeft feedback op de code vergeleken met de 2e code, wat de secret KAN zijn. Het kan ook een andere zijn. Als write true is, slaat hij het op in data.
    int white = 0;
    int black = 0;
    white = checkWhite(code, secret);
    char cwhite = white +'0';
    black = checkBlack(code, secret)-white ;
    char cblack = black + '0';
    vector<char> feedbk { cwhite, cblack  };
    if(write == true){
        if (data.size() == 0){  
            data.push_back(feedbk); 
        }else{
            int length = data.size()-1;
            data[length].insert(data[length].end(), feedbk.begin(), feedbk.end());
        }
        
    }
    return feedbk;
}   

vector<string> generatePossibleGuesses(vector<vector<char>> &data, bool full){
    if (full != true){
        vector<string> possible = {};
        string listColours = "rgbcmy";

        possible = generateAllCodes();
            
        std::sort(possible.begin(), possible.end());
        return possible;
    
    }else{
        string compareCode;
        vector<string> possible = {};
        vector<char> feedbk;
        for(int i = 0; i < g_amountOfColumns-1; i++){
            compareCode.push_back(data[data.size()-2][i]);
        }
        feedbk.push_back(data[data.size()-2][4]);
        feedbk.push_back(data[data.size()-2][5]);
        for(int i = 0; i < g_possibleGuesses.size(); i++){
            if (feedbk == feedback(g_possibleGuesses[i], compareCode, data, false)){
                possible.push_back(g_possibleGuesses[i]);
            }

        }
        std::sort(possible.begin(), possible.end());
        return possible;
    }


}


string determineGuess(vector<vector<char>> data, vector<char>newestfeedback){
    //ik pak het midden van gesorteerde mogenlijke  hierdoor hoop ik beter te kunnen uitsluiten welke daadwerkelijk mogenlijk is.
    //( heuristiek )
    if (g_possibleGuesses.size()== 0){
        g_possibleGuesses = generatePossibleGuesses(data,false);
        //geef het midden van de lijst.
        std::sort(g_possibleGuesses.begin(),g_possibleGuesses.end());
        string temp = g_possibleGuesses[(g_possibleGuesses.size()/2)];
        // verwijder de keuze, want als deze fout is is het geen mogenlijke optie, en we kunnen deze altijd nog terug vinden in data.
        g_possibleGuesses.erase(g_possibleGuesses.begin()+ g_possibleGuesses.size()/2);
        cout<<g_possibleGuesses.size()<<" = grote van mogenlijke opties";
        return temp;
    // er is een vorige guess gedaan. Dus nu kunnen we daar op in met de feedback.
    }else{
        
       
        // bereken nu welke nog mogenlijk zijn, door naar de feedback te kijken.
        // Als de feedback overeenkomt met de laatste poging ( vergeleken dus mét de laatste poging)
        
        if (g_possibleGuesses.size() > 3){
            g_possibleGuesses = generatePossibleGuesses(data,true);
            cout<<"zoveel : "<< g_possibleGuesses.size()<<"  | aantal mogelijkheden";
            string code = g_possibleGuesses[(g_possibleGuesses.size()/2)];
            g_possibleGuesses.erase(g_possibleGuesses.begin()+ g_possibleGuesses.size()/2);
            return code;
        }
        else if (g_possibleGuesses.size() <= 2 && g_possibleGuesses.size() > 0 ){
            g_possibleGuesses = generatePossibleGuesses(data,true);
            cout<<"zoveel : "<< g_possibleGuesses.size()<<"  | aantal mogelijkheden";
            string code = g_possibleGuesses[0];
            g_possibleGuesses.erase(g_possibleGuesses.begin()+1);
            return code;
        }else{ 
            g_possibleGuesses = generatePossibleGuesses(data,true);
            cout<<"oh je, wss gaat er iets fout";
            string code = g_possibleGuesses[0];
            g_possibleGuesses.erase(g_possibleGuesses.begin()+1);
            return code;
            // er blijft nog maar 1 over
        }
        
        string code = "RRRR";
        return code;          
    }
   
}

string writeNewData(vector<vector<char>> &data, vector<char>newestfeedback,  bool ai = false){
    data.push_back(vector <char> ());
    string newestCode;
    int length = data.size()-1;
    if(ai == false){
        for(signed int i = 0 ; i<g_amountOfColumns; i++){
            char newdata =  inputcode();
                if (length<4){
                    data[length].push_back(newdata);
                    newestCode.push_back(newdata);
                    }
                }
    }else{
        newestCode = determineGuess(data,newestfeedback);
        for(signed int i = 0 ; i<g_amountOfColumns; i++){
            char newdata = newestCode[i];
            data[length].push_back(newdata);
        }
    } 
    
    return newestCode;
}







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

    // test secret
    
    

    //TODO: MENU MAKEN DIE MODUS SELECTEERD
    
    //algemeen, nodig in zowel user als AI.
   
    startSetup(4);
    system("CLS");
    string secret = generateSecret();
    cout<<"het geheim niet door vertellen:"<< secret;
    char test;
    vector<vector<char>> data;
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