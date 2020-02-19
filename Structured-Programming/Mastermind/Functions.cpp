#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>   
#include <time.h>     
#include <stdio.h>
#include <bits/stdc++.h> 
using std::vector;
using std::string;
using std::endl;
using std::cout;
#include <algorithm> 
#include "Functions.h"

// Functies voor het printen en mooi krijgen van de file, kleine overlap met algorithms

/*Globale settings voor het hele programma, waar veel naar gekeken gaat worden. 
g_* ter verduidelijking dat het een global is. 
Dit is voor de syntax niet nodig maar wel fijn, aangezien je anders het verschil waarschijnlijk niet ziet.*/
int g_amountOfColumns ;
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
                cout<<"|"<<i<<j<<"|";
            }
            cout<<"|";
            
            for(int i = 0; i<g_amountOfColumns; i++){
                cout<<" ";


            // hints print
            }
            cout<<"|";
            cout<<"W"<<newestCode[0]<<"B"<<newestCode[1];
            for(int i = 0; i<g_amountOfColumns-(newestCode.size()+2); i++){
                cout<<"=";
            }
            cout<<"|                                                                                                                  \n\n";    
        }
}
