#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
void verschuiven(char charac, int n){
    for(int i= 0; i < n ; i++){
        charac << charac ;
    
    }
    cout<< charac;
}
int main () {
    char charac = 'c';
    verschuiven(charac, 2);

    return 0;
}