
// C++ implementation 
#include <bits/stdc++.h> 
#include <vector>
#include <string>
using namespace std; 
using std::vector;
vector<string> ja = {};
// Convert the number to Lth 
// base and print the sequence 
void convert_To_Len_th_base(int n, int arr[], int len, int L, int j) 
{ 
        ja.push_back(j);
    // Sequence is of length L 
    for (int i = 0; i < L; i++) { 
        // Print the ith element 
        // of sequence 
        switch(arr[n % len]){
                case 1 :
                ja[j].append("R") ; 
                break;
                case 2 :
                cout << "G" ; 
                break;
                case 3 :
                cout << "B" ; 
                break;
                case 4 :
                cout << "C" ; 
                break;
                case 5 :
                cout << "M" ; 
                break;
                case 6 :
                cout << "Y" ; 
                break;
        
                }

        n /= len; 
    } 
    
    cout << endl; 
} 
  
// Print all the permuataions 
void print(int arr[], 
           int len, 
           int L) 
{ 
    // There can be (len)^l 
    // permutations 
    for (int i = 0; i < (int)pow(len, L); i++) { 
        // Convert i to len th base 
        convert_To_Len_th_base(i, arr, len, L, i); 
    } 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 1, 2, 3 ,4 , 5, 6}; 
    int len = sizeof(arr) / sizeof(arr[0]); 
    int L = 4; 
  
    // function call 
    print(arr, len, L); 
        for (int i = 0; i < ja.size()-1;i++){
                cout<<ja[i];
        }
    return 0; 
} 
