    #pragma once
    #include <vector>
    #include <string>
    using std::vector;
    using std::string;

    extern int g_amountOfColumns ;
    extern vector<string> g_possibleGuesses;

    
void startSetup(int columns);

void colorprint(string character,char color);
  
void startoutrow(vector<vector<char>>data);

char checkcode(char code);

void dashcodes(char code);

char inputcode();

char getData(vector<vector<char>> data, int index, int index2);

void printrow(vector<vector<char>> &data,vector<char> newestCode);
