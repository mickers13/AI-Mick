#include <vector>
#include <iostream>
#include <string>
#include <windows.h>
using std::vector;
using std::string;
using std::endl;
using std::cout;
/*Ik doe een paar gekke dingen, die ik zelf erg leuk vond om uit te zoeken om een leuke Commandline game versie van mastermind te maken ( kleurtjes in CMD enzo. ). paar voorbeelden voor de bronnen:
https://en.wikipedia.org/wiki/ANSI_escape_code ik heb deze bron gedeeld met Ayoub.



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

void printinrow(vector<vector<char>>data){
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

// void printrow(vector<vector<char>>data){
//     void SetVector(int position, int value) {
//    try
//     {
//        testVector.at(position) = value;
//     }
//    catch (const std::out_of_range& oor) {
//       testVector.resize(position + 1);
//       testVector[position] = value;
//    }
// }
    
    
//     cout<<"\r|";

//     for(int k = 0; k<g_amountOfColumns; k++){
        
//         if (data[k][k] != '' ){
//             colorprint("X",data[i-1][k]);
//         }else{
//             colorprint("X",'R');
//         }
//     }
//     cout<<"|";
//     for(int i = 0; i<g_amountOfColumns; i++){
//         cout<<" ";
//     }cout<<"|";
//     for(int i = 0; i<g_amountOfColumns; i++){
//         cout<<" ";
//     }cout<<"|\n";
// }
        


void startoutrow(vector<vector<char>>data){
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

    

}

void overwrite(string phrase){
    //overschrijf de vorige lijn met een nieuwe zin. handig voor text ( + veel spaties om volledig te overschrijven)
    cout<<"\033[F\r"<<phrase<<"                                                                                     \n";
}

void writeNewData(vector<vector<char>>data,char newdata){
for(int i = 0 ; i<data.size(); i++){
    data[i].push_back(newdata); 
    cout<<"\n test";
    }
}
void dashcodes(char code){
    if (code == '*'){
            cout<<"\r These are all useable colours: \033[40;101m r, \033[40;102m g, \033[40;104m b, \033[40;106m c, \033[40;105m m and \033[40;103m y \033[39;49m";
    }
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

char inputcode(){
    char code;
    cout<<"Enter the colour (use * for a list of colours.): ";
    std::cin>>code;
    dashcodes(code);
    char vec_code;
    vec_code = checkcode(code);
    while (vec_code =='0' ){
        
        checkcode(code);
    }
    
    return vec_code;
    
}

int main() {
    system("CLS");
    char test;
    vector<vector<char>> data;
    startSetup(4,6);
    startoutrow(data);
    writeNewData(data,'R');
    //printrow(data);
    

    
}

