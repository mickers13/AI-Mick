#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

//bron char append https://stackoverflow.com/questions/34055713/how-to-add-a-char-int-to-an-char-array-in-c
// Helaas niet helemaal de bedoeling, ik kwam niet verder dan dit. ik vraag maanda gvoor hulp tijdens C++ programming.

void append(char* woorden, char c) {
        int len = std::char_traits<char>::length(woorden);
        woorden[len] = c;
        woorden[len+1] = '\0';
}

using namespace std;
char writeWoorden(char woorden[100]){
    ofstream ofile;
        char woordencomp[100];
        int lengte= std::char_traits<char>::length(woorden) ;
        ofile.open("teveeltabs.txt");
        cout << "Voer een zin in die je wilt 'compressen': "; 
        cin.getline(woorden, 100);
        for( int letterslocatie = 0 ; letterslocatie < lengte ; letterslocatie++){
        if (woorden[letterslocatie]=='\t'|| woorden[letterslocatie] == '\n'){
            cout<<"niet compressed";
            continue;

        }else{
            cout<<"compressed";
            append(woordencomp,woorden[letterslocatie]);

        }
        cout<<"de zin zonder tabs enzo: "<< woordencomp;
        ofile << woordencomp << endl;
        ofile.close();

        }
        
}
 
int main () {
    char data[100];

    writeWoorden(data);

    ifstream file; 
    file.open("teveeltabs.txt"); 
        cout << "Reading from the file" << endl; 
        file >> data; 
        cout << data << endl;
        file.close();

    return 0;
}