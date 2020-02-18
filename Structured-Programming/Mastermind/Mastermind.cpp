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

/*Ik doe een paar gekke dingen, die ik zelf erg leuk vond om uit te zoeken om een leuke Commandline game versie van mastermind te maken ( kleurtjes in CMD enzo. ). paar voorbeelden voor de bronnen:
https://en.wikipedia.org/wiki/ANSI_escape_code ik heb deze bron gedeeld met Ayoub.
http://www.cplusplus.com      goede uitleg voor functies met klein voorbeeld.
https://stackoverflow.com/questions/2551775/appending-a-vector-to-a-vector
https://en.cppreference.com/w/cpp/algorithm/next_permutation`
https://www.youtube.com/watch?v=7IQHYbmuoVU
https://www.geeksforgeeks.org/print-all-the-permutation-of-length-l-using-the-elements-of-an-array-iterative/ ( code heb ik gebruikt als template en aangepast naar wat ik wil. )
*/


/*Globale settings voor het hele programma, waar veel naar gekeken gaat worden. 
g_* ter verduidelijking dat het een global is. 
Dit is voor de syntax niet nodig maar wel fijn, aangezien je anders het verschil waarschijnlijk niet ziet.*/
int g_amountOfColumns;
int g_amountOfColours;


void startSetup(int columns = 4, int colours = 6){
    //defineer variablen, en doe paar dingen die aan het begin mogen gebeuren.
    ::g_amountOfColumns = columns;
    ::g_amountOfColours = colours;
}


// COMMENT: deze functie heeft niets te maken met de core game.
// Dus zet hem in een aparte file voor functies die dingen mooier maken.

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

// COMMENT: ook deze functie print iets.
// Zet hem in een aparte file.

void startoutrow(vector<vector<char>>data){
    // Print text.
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
    cout<<black << "hoeveelheid zwart";
    return black;
    
}

// COMMENT: geen idiote functie namen alstublieft XD.

string convert_To_Len_th_base(int n, int arr[], int len, int L, int j ) { 
    string woord;
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
  
// Print all the permuatations 
vector<string> print(int arr[],int len,int L) { 
    vector<string> lijst ;
    string woordReturn = "";
    // There can be (len)^l 
    // permutations 
    for (int i = 0; i < (int)pow(len, L); i++) { 
        // Convert i to len th base 
        woordReturn = convert_To_Len_th_base(i, arr, len, L, i); 
        lijst.push_back(woordReturn);
    } 
    return lijst;
} 

// COMMENT: wat is driver code?

// Driver code 

// COMMENT: wat generaten we hier?
vector<string> generate(){ 
    vector<string> lijst ;
    int arr[] = { 1, 2, 3 ,4 , 5, 6}; 
    
    // COMMENT: Waarom de lengte berekenen van een array met fixed length?
    
    int len = sizeof(arr) / sizeof(arr[0]); 
    int L = 4; 
  
    // function call  
    lijst = print(arr, len, L); 
        
    return lijst; 
} 

vector<string> generatePossibleGuesses(vector<vector<char>> data,vector<string> lastPossibleGuesses){

    vector<string> possible = {};
    string listColours = "rgbcmy";
    if (lastPossibleGuesses.size() != 0){// als er een vorige gok is gedaan.
        
    }else { // als er dus nog geen vorige gok is gedaan. ( betekend dat data ook leeg is.)
        possible = generate();
        
    }

    // std::sort(possibleGuesses.begin(), possibleGuesses.end());
    cout <<possible[(possible.size()/2)];
    return possible;
}

string determineGuess(vector<vector<char>> data, vector<string> lastPossibleGuesses){
    vector<string> possibleguesses = generatePossibleGuesses(data, lastPossibleGuesses);
    //als ik het midden pak van een gesorteerde lijst van mogelijke, is het een soort binary search maar beter!() ( heuristiek )
    
    string test = possibleguesses[(possibleguesses.size()/2)];
    return test;
   
}

    


vector<char> feedback(string code,string secret,vector<vector<char>> data,bool write){
    int white = 0;
    int black = 0;
    white = checkWhite(code, secret);
    char cwhite = white +'0';
    black = checkBlack(code, secret)-white ;
    char cblack = black + '0';
    vector<char> feedbk { cwhite, cblack  };
    if(write == true){
        int length = data.size()-1;
        data[length].insert(data[length].end(), feedbk.begin(), feedbk.end());
    }
    return feedbk;
}   



string writeNewData(vector<vector<char>> data, bool ai = false){
    data.push_back(vector <char> ());
    string newestCode;
    vector<string> lastPossibleGuesses = {};
    int length = data.size()-1;
    if(ai == false){
        for(signed int i = 0 ; i<g_amountOfColumns; i++){
        char newdata =  inputcode();
            if (length<4){
                data[length].push_back(newdata);
                newestCode.push_back(newdata);
            }
            }}
            else{
                newestCode = determineGuess(data, lastPossibleGuesses);
                
               
            }
        return newestCode;
        }
       
    


char getData(vector<vector<char>> data, int index, int index2){
    int length = data.size();
    return data[index][index2];
}



void printrow(vector<vector<char>> data,vector<char> newestCode){
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

    // test secret
    
    

    //TODO: MENU MAKEN DIE DEZE SELECTEERD
    //USER PLAYS MODUS:
    startSetup(4,6);
    system("CLS");
    string secret = generateSecret();
    cout<<"het geheim niet door vertellen:"<< secret;
    char test;
    vector<vector<char>> data;
    string newestCode;
    startoutrow(data);
    // un comment voor player
    // newestCode = writeNewData(data,false);
    // printrow(data, feedback(newestCode, secret,data, true));
    
    //AI PLAYS MODUS
    newestCode = writeNewData(data,true);
    cout<<"en door";
    printrow(data, feedback(newestCode, secret,data, true));

    
}

