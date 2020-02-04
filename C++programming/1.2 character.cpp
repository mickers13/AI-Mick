#include <iostream>
using namespace std;
int main() {
    char a = 'a';
    char b = 'b';
    char c = 'c';
    char h = 'h';
    char z = 'z';
    char ca = 'A';
    char cb = 'B';
    char cc = 'C';
    char ch = 'H';
    char cz = 'Z';
    int aminA = int(a)-int(ca);
    
    cout << "ASCII Value of " << a << " is " << int(a);
    cout << "ASCII Value of " << b << " is " << int(b);
    cout << "ASCII Value of " << c << " is " << int(c);
    cout << "ASCII Value of " << h << " is " << int(h);
    cout << "ASCII Value of " << z << " is " << int(z);
    cout << "ASCII Value of " << ca << " is " << int(ca);
    cout << "ASCII Value of " << cb << " is " << int(cb);
    cout << "ASCII Value of " << cc << " is " << int(cc);
    cout << "ASCII Value of " << ch << " is " << int(ch);
    cout << "ASCII Value of " << cz << " is " << int(cz);

    cout << "The value of g minus the result of a - A = " << ('g'- aminA) << endl; 

    cout << "The vales of 0 and 8 are: "<<int('0') <<" and "<< int('8');
    cout << "4 - 0 "<< int('4') - int('0');
    cout << "omdat je dan hoofdletters uit kan rekenen en cijfers kan berekenen in bijv arrays"
}