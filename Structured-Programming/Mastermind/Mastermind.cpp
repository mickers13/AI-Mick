#include <vector>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>   
#include <time.h>     
#include <stdio.h>
#include <bits/stdc++.h> 
using std::vector;
using std::string;
using std::endl;
using std::cout;
#include <algorithm> 

/*Niet gelukt:   
    Mergen van poging tot headerfile en de master branche.  ( tijd nood. )   Code in de poging tot headerfile is veel netter en beter verdeeld. Ook is er de crash bug uit gewerkt.
    Maar is er daar 1 andere bug voor terug gekomen. Kijk dus deels naar de code hier en bij de branche hier onder:
    https://github.com/mickers13/AI-Mick/tree/Poging-tot-headerfile

 */


/*Ik doe een paar gekke dingen, die ik zelf erg leuk vond om uit te zoeken om een leuke Commandline game versie van mastermind te maken ( kleurtjes in CMD enzo. ). paar voorbeelden voor de bronnen:
https://en.wikipedia.org/wiki/ANSI_escape_code ik heb deze bron gedeeld met Ayoub.
http://www.cplusplus.com      goede uitleg voor functies met klein voorbeeld.
https://stackoverflow.com/questions/2551775/appending-a-vector-to-a-vector
https://en.cppreference.com/w/cpp/algorithm/next_permutation`
https://www.youtube.com/watch?v=7IQHYbmuoVU
https://www.geeksforgeeks.org/print-all-the-permutation-of-length-l-using-the-elements-of-an-array-iterative/ ( code heb ik gebruikt als template en aangepast naar wat ik wil. )
https://www.systutorials.com/convert-string-to-int-and-reverse/
*/


/*Globale settings voor het hele programma, waar veel naar gekeken gaat worden. 
g_* ter verduidelijking dat het een global is. 
Dit is voor de syntax niet nodig maar wel fijn, aangezien je anders het verschil waarschijnlijk niet ziet.*/
int g_amountOfColumns ;
// global aangezien ik niet continue wil rotzooien met verplaatsen van deze vector aangezien hij vrij groot word. Ik hoorde van een vriend dat een pointer zou kunnen  helpen maar daar heb ik nog
// niet mee gewerkt, ik ga hier ná de deadline kijken hoe dit werkt.  Verder gebruik ik deze vector relatief veel in andere functies.
vector<string> g_possibleGuesses = {};


void startSetup(int columns = 4){
    //defineer variablen, en doe paar dingen die aan het begin mogen gebeuren. 
    ::g_amountOfColumns = columns;

}

void colorprint(string character,char color){
    // een switch, die een kleur pakt en print en weer reset. Erg fijn, python heeft dit niet... BOEEE! Letters staan voor RGB - CMY van rood groen blauw... etc!
    switch(color){
        case'R': 
            cout<<"\033[40;101m";
            cout<<character;
            cout<<"\033[39;49m";
            break;

        case'G':
            cout<<"\033[40;102m";
            cout<<character;
            cout<<"\033[39;49m";
            break;

        case'B':
            cout<<"\033[40;104m";
            cout<<character;
            cout<<"\033[39;49m";
            break;

        case'C':        
            cout<<"\033[40;106m";
            cout<<character;
            cout<<"\033[39;49m";
            break;

        case'M':
            cout<<"\033[40;105m";
            cout<<character;
            cout<<"\033[39;49m";
            break;
        case'Y':
            cout<<"\033[40;103m";
            cout<<character;
            cout<<"\033[39;49m";
            break;
    }
}

void startoutrow(vector<vector<char>>data){
    // Print text lees bare text
        cout<<"\n|Code:";
        
        for(int i = 0; i<g_amountOfColumns; i++){
            cout<<" ";
        }

        cout<<"Clues|\n";

    // Print a line.
        cout<<"|";
        for(int i = 0; i<g_amountOfColumns; i++){
            cout<<"=";
        }cout<<"|";
        for(int i = 0; i<g_amountOfColumns; i++){
            cout<<" ";
        }cout<<"|";
        for(int i = 0; i<g_amountOfColumns; i++){
            cout<<"=";
        }
        cout<<"|                                                                             \n";

    

}

void overwrite(string phrase){
    //overschrijf de vorige lijn met een nieuwe zin. handig voor text ( + veel spaties om volledig te overschrijven)
    cout<<"\033[F\r"<<phrase<<"                                                                                     \n";
}

char checkcode(char code){
    char codei;
    if (code == 'r'){
        codei = 'R';
    }else if(code == 'g'){
        codei = 'G';
    }else if(code == 'b'){
        codei = 'B' ;
    }else if(code == 'c'){
        codei = 'C' ;
    }else if(code == 'm'){
        codei = 'M';
    }else if(code == 'y'){
        codei = 'Y';
    }else {
        //non correct code syntax
        codei = '0';
    }
    return codei;
}

void dashcodes(char code){
    if (code == '*'){
            cout<<"\033[F\r These are all useable colours: \033[40;101m r  \033[40;102m g  \033[40;104m b  \033[40;106m c  \033[40;105m m and \033[40;103m y \033[39;49m                                             ";
        Sleep(200);
    }
}

char inputcode(){
    char code;
    cout<<"\rEnter the colour (use * for a list of colours.) (only lowercase.) :     ";
    std::cin>>code;
    dashcodes(code);
    char vec_code;
    vec_code = checkcode(code);
    while (vec_code =='0' ){
        cout<<"\033[F\rEnter the colour (use * for a list of colours.) (only lowercase.) :     ";
        std::cin>>code;
        dashcodes(code);
        vec_code = checkcode(code);
    }
    
    return vec_code;
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
    //( heuristiek ) ( ik wilde eerst iets anders proberen, namenlijk de bitwaarden vergelijken van alles en dan de waarde het meest dichtbij het gemiddelde bitwaarde pakken, maar dat kwam 
    // letterlijk op het zelfde neer...)
    if (g_possibleGuesses.size()== 0){
        g_possibleGuesses = generatePossibleGuesses(data,false);
        std::sort(g_possibleGuesses.begin(),g_possibleGuesses.end());
        string temp = g_possibleGuesses[(g_possibleGuesses.size()/2)];

        // verwijder de keuze, want als deze fout is is het geen mogenlijke optie, en we kunnen deze altijd nog terug vinden in data.
        g_possibleGuesses.erase(g_possibleGuesses.begin()+ g_possibleGuesses.size()/2);
        cout<<g_possibleGuesses.size()<<" = grote van mogenlijke opties";
        return temp;
    }else{
        // bereken nu welke nog mogenlijk zijn, door naar de feedback te kijken.
        // Als de feedback overeenkomt met de laatste poging ( vergeleken dus mét de laatste poging)
        
        if (g_possibleGuesses.size() >= 3){
            g_possibleGuesses = generatePossibleGuesses(data,true);
            cout<<"zoveel : "<< g_possibleGuesses.size()<<"  | aantal mogelijkheden";
            string code = g_possibleGuesses[(g_possibleGuesses.size()/2)];
            g_possibleGuesses.erase(g_possibleGuesses.begin()+ g_possibleGuesses.size()/2);
            return code;
        }
        else if (g_possibleGuesses.size() > 0){
            g_possibleGuesses = generatePossibleGuesses(data,true);
            cout<<"zoveel : "<< g_possibleGuesses.size()<<"  | aantal mogelijkheden";
            string code = g_possibleGuesses[0];
            g_possibleGuesses.erase(g_possibleGuesses.begin()+1);
            return code;
        }else{ 
            g_possibleGuesses = generatePossibleGuesses(data,true);
            string code = g_possibleGuesses[0];
            return code;
            // er blijft nog maar 1 over
        }
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
       
    


char getData(vector<vector<char>> data, int index, int index2){
    int length = data.size();
    return data[index][index2];
}


void printrow(vector<vector<char>> &data,vector<char> newestCode){
    // Print a frame + items van de vector met de laatste index ( wat de nieuwste is.)
        startoutrow(data);
        cout<<"\033[F";

        // code print         
        for (int j = 0; j <= data.size()-1; j++){
            cout<<"|";
            for(signed int i = 0; i<g_amountOfColumns; i++){
                
                colorprint("X",getData(data, j, i));

            }cout<<"|";
            for(int i = 0; i<g_amountOfColumns; i++){
                cout<<" ";


            // hints print
            }cout<<"|";
            cout<<"W"<<newestCode[0]<<"B"<<newestCode[1];
            for(int i = 0; i<g_amountOfColumns-(newestCode.size()+2); i++){
                cout<<"=";
            }
            cout<<"|                                                                                                                  \n\n";    
        }
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

 
    
    // Deze branche heeft een simpel keuze menu

    
    
    //algemeen, nodig in zowel user als AI.
   
    startSetup(4);
    system("CLS");
    string secret = generateSecret();
    cout<<"het geheim niet door vertellen:"<< secret;
    char test;
    vector<vector<char>> data;
    
    startoutrow(data);
    int menu;
    cout<<"Enter 0 for player and 1 for ai modus. : ";
    std::cin>>menu;
    if (menu == 0){
        //USER PLAYS MODUS:
        while(1){
            string newestCode;
            vector<char> newestFeedback;
            newestCode = writeNewData(data,newestFeedback,false);
            newestFeedback = feedback(newestCode, secret,data, true);
            printrow(data, feedback(newestCode, secret,data, true));
            if(newestFeedback[0] == '4'){
                cout<<"whoo gewonnen!";
                break;
            }
        }
    }else{    
        while(1){
            //AI PLAYS MODUS: 
            string newestCode;
            vector<char> newestFeedback;
            newestCode = writeNewData(data,newestFeedback,true);
            newestFeedback = feedback(newestCode, secret,data, true);
            printrow(data, newestFeedback);
            if(newestFeedback[0] == '4'){
                cout<<"whoo gewonnen!";
                break;
            }
        }
    }
    

    return 0;
}