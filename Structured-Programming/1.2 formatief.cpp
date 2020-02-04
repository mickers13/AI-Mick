#include <iostream>
#include <string>
using namespace std;
string input_text(){
    string a;
    getline(cin,a);
    return a;
}
int main() {
    string texta = input_text();
    string textb = input_text();

    for( int i=0; i<=texta.length() ; i++ ){
        if(texta[i] != textb[i]){
            cout<<"ohje, vanaf de "<<i-1<<"de character zijn volgende zinnen niet hetzelfde! :"<<endl;
            cout<<texta<<endl;
            cout<<textb<<endl;
        }

    }

}

