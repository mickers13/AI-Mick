#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//bron char append https://stackoverflow.com/questions/34055713/how-to-add-a-char-int-to-an-char-array-in-c
// Helaas niet helemaal de bedoeling, ik kwam niet verder dan dit. ik vraag maanda gvoor hulp tijdens C++ programming.

void append(string woorden, char c) {
        int len = woorden.size();
        woorden[len] = c;
        woorden[len+1] = '\0';
}


char writeWoorden(string woorden){
    ofstream ofile;
        string woordencomp;
        ofile.open("teveeltabs.txt");
        cout << "Voer een zin in die je wilt 'compressen': "; 
        getline(cin,woorden);
        int lengte= woorden.size() ;
        cout << woorden << std::endl;
        cout << lengte << endl;
        for( int letterslocatie = 0 ; letterslocatie < lengte ; letterslocatie++){
            cout << woorden[letterslocatie] << endl;
            if (woorden[letterslocatie]=='\t'|| woorden[letterslocatie] == '\n'){
                cout<<"niet compressed" << std::endl;
                continue;
            }else{
                cout<<"compressed" << std::endl;
                append(woordencomp,woorden[letterslocatie]);
            }
        }
        cout<<"de zin zonder tabs enzo: "<< woordencomp << std::endl;
        ofile << woordencomp << endl;
        ofile.close();

        
        
}
 
int main () {
    string data;

    writeWoorden(data);

    ifstream file; 
    file.open("teveeltabs.txt"); 
        cout << "Reading from the file" << endl; 
        file >> data; 
        cout << data << endl;
        file.close();

    return 0;
}