#include <vector>
#include <iostream>
#include <string>
#include <windows.h>
using std::vector;
using std::string;
using std::endl;
using std::cout;
/*Ik doe een paar gekke dingen, die ik zelf erg leuk vond om uit te zoeken om een leuke Commandline game te maken ( kleurtjes in CMD enzo. ). paar voorbeelden voor de bronnen:
https://en.wikipedia.org/wiki/ANSI_escape_code



*/




/*Globale settings voor het hele programma, waar veel naar gekeken gaat worden. 
g_* ter verduidelijking dat het een global is. 
Dit is voor de syntax niet nodig maar wel fijn, aangezien je soms de :: over het hoofd ziet.*/
int g_amountOfColumns;
int g_amountOfColours;


void startSetup(int columns = 4, int colours = 6){
    ::g_amountOfColumns = columns;
    ::g_amountOfColours = colours;

}

void colorprint(string character,char color){
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

void printinrow(vector<vector<int>>data){
    cout<<"\033[F|";
        for(int i = 0; i<g_amountOfColumns; i++){
            
            colorprint("O",'R');
        }
        cout<<"|";
        for(int i = 0; i<g_amountOfColumns; i++){
            cout<<" ";
        }cout<<"|";
        for(int i = 0; i<g_amountOfColumns; i++){
            cout<<" ";
        }cout<<"|";
}

void outrow(vector<vector<int>>data){
    // Print text.
        cout<<"|Code:";
        
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
    printinrow(data);

    

}
void overwrite(string phrase){
    //overschrijf de vorige lijn, met een nieuwe + veel spaties om volledig te overschrijven
    cout<<"\033[F\r"<<phrase<<"                                                                  \n";
}

int main() {
    system("CLS");
    char test;
    vector<vector<int>> data;
    startSetup(4,6);
    outrow(data);

    
    
}

