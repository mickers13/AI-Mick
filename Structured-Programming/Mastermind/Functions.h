    #pragma once
    #include <vector>
    #include <string>
    using std::vector;
    using std::string;

    extern int g_amountOfColumns ;
    extern vector<string> g_possibleGuesses;

// FUNCTIONS.CPP ( PRINT RELATED )
void startSetup(int columns);

void colorprint(string character,char color);
  
void startoutrow(vector<vector<char>>data);

char checkcode(char code);

void dashcodes(char code);

char inputcode();

char getData(vector<vector<char>> data, int index, int index2);

void printrow(vector<vector<char>> &data,vector<char> newestCode);


// ALGORITHMS.CPP ( MAINLY ALGORITHM RELATED)
int checkWhite(string code, string secret);

int checkBlack(string code, string secret);

int convertStringToInt(string code);

int berekenGemGuess();

string covertToLen(int n, int arr[], int len, int L, int j );

vector<string> generateLetter(int arr[],int len,int L);

vector<string> generateAllCodes();

vector<char> feedback(string code,string secret,vector<vector<char>> &data,bool write);

vector<string> generatePossibleGuesses(vector<vector<char>> &data, bool full);

string determineGuess(vector<vector<char>> data, vector<char>newestfeedback);

string writeNewData(vector<vector<char>> &data, vector<char>newestfeedback,  bool ai);