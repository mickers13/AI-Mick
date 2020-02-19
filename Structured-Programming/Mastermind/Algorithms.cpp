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
#include "Functions.h"

// Alle wat moeilijkere algoritmes in 1 file, kleine overlap met Functions. ( sommige functies hadden op beide plekken kunnen staan. )

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

  
vector<string> generateLetter(int arr[],int len,int L) { 
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
  
    lijst = generateLetter(arr, len, L); 
        
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
            // voeg de laatste toegevoegde gok toe om dingen mee te vergelijken
            compareCode.push_back(data[data.size()-1][i]);
        }
        feedbk.push_back(data[data.size()-1][4]);
        feedbk.push_back(data[data.size()-1][5]);
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
        
        if (g_possibleGuesses.size() >= 3){
            ::g_possibleGuesses = generatePossibleGuesses(data,true);
            cout<<"zoveel : "<< g_possibleGuesses.size()<<"  | aantal mogelijkheden--";
            string code = g_possibleGuesses[(g_possibleGuesses.size()/2)];
            ::g_possibleGuesses.erase(g_possibleGuesses.begin()+ g_possibleGuesses.size()/2);
            return code;
        }
        else if (g_possibleGuesses.size() <= 2 && g_possibleGuesses.size() > 0 ){
            // het heeft geen nut om midden te pakken van iets wat minder dan 3 is.
            ::g_possibleGuesses = generatePossibleGuesses(data,true);
            cout<<"zoveel : "<< g_possibleGuesses.size()<<"  | aantal mogelijkheden++";
            string code = g_possibleGuesses[0];
            ::g_possibleGuesses.erase(g_possibleGuesses.begin()+1);
            return code;
        }else{ 
            ::g_possibleGuesses = generatePossibleGuesses(data,true);
            string code = g_possibleGuesses[0];
            ::g_possibleGuesses.erase(g_possibleGuesses.begin()+1);
            return code;
            // er blijft nog maar 1 over dus dit zou hem 100% moeten zijn.
        }
            
    }
   
}

string writeNewData(vector<vector<char>> &data, vector<char>newestfeedback,  bool ai){
 // sla data op in 2d vector. Ik heb character genomen omdat dat makkelijker vergelijken is dan een string.
    string newestCode;
    int length = data.size()-1;
    if(ai == false){
        //als de speler wilt spelen dan moet hij invoeren wat het word.
        for(signed int i = 0 ; i<g_amountOfColumns; i++){
            char newdata =  inputcode();
                if (length<4){
                    data[length].push_back(newdata);
                    newestCode.push_back(newdata);
                    }
                }
    }else{
        //als je de ai wilt gebruiken zoekt hij ook welke gok je wilt doen.
        newestCode = determineGuess(data,newestfeedback);
        for(signed int i = 0 ; i<g_amountOfColumns; i++){
            char newdata = newestCode[i];
            data[length].push_back(newdata);
        }
    } 
    
    return newestCode;
}
