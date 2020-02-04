#include <iostream>
#include <string>
using namespace std;
int main() {
    string noleet;
    string is1337;
    string temp;

    getline(cin,noleet);
    for(int c = 0; c < noleet.length(); c++){
        if(int(noleet[c])>='A' and int(noleet[c])<='Z'){
            if(int(noleet[c]) == 'E'){
                is1337.append(string("3"));
            } else if(int(noleet[c]) == 'T'){
                is1337.append("1");
            } else if(int(noleet[c]) == 'L'){
                is1337.append("7");
            } else if(int(noleet[c]) == 'O'){
                is1337.append("0");
            } else{
                is1337+=(noleet[c]);
            }
        }
         else if(int(noleet[c])>=97 and int(noleet[c])<=122){
            if (int(noleet[c]) == 'e'){
                is1337.append("3");
            } else if(int(noleet[c]) == 't'){
                is1337.append("1");
            } else if(int(noleet[c]) == 'l'){
                is1337.append("7");
            } else if(int(noleet[c]) == 'o'){
                is1337.append("0");
            } else{
                is1337+=toupper(noleet[(c)]);
            }
        
        } else{
            is1337+=noleet[int(c)];
        }
    }

    cout<<is1337;
};