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

int checkwhite(string code, string secret){
    
}

vector<char> feedback(string code,string secret){
    int white = 0;
    char cwhite;
    int black = 0;
    char cblack;
    for(signed int i = 0; i < code.length(); i++){
        for(signed int j = 0; i < code.length(); j++){
            if (code[i] ==secret[j]){
                if (i == j){
                    white++;
                    break;
                }else

                    black++;
                    break;
            }
        }
    }
    cout<<white<<"<wit"<<black<<"<zwart";
    if (white != 0) {
        cwhite = white+ '0';
    }else{ cwhite = '0' ;}

    if (black != 0){
    cblack = black+ '0';
    }else{ cblack = '0' ;}
    vector<char> feedbk { cwhite, cblack };
    return feedbk;
}   

char inputcodeAI(char a, char b, char c, char d){
    char code;
    return code;
    
}

string writeNewData(vector<vector<char>> &data){
    data.push_back(vector <char> ());
    string newestCode;
    int length = data.size()-1;
    for(signed int i = 0 ; i<g_amountOfColumns; i++){
        char newdata =  inputcode();
        if (length<4){
            data[length].push_back(newdata);
            newestCode.push_back(newdata);
        }
        }
        cout<<newestCode;
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





int main() {
    // test secret
    string secret = "RBBR";
    //USER PLAYS MODUS:
    startSetup(4,6);
    system("CLS");
    char test;
    vector<vector<char>> data;
    string newestCode;
    startoutrow(data);
    newestCode = writeNewData(data);
    printrow(data, feedback(newestCode, secret));
    while(1){
        newestCode = writeNewData(data);
        printrow(data, feedback(newestCode, secret));
    }
    //AI PLAYS MODUS
    

    
}

