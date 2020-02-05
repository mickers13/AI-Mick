#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
//Ik heb écht geprobeerd zelf een sorteer methode te maken, maar dat was te moeilijk. Daarom heb ik van een quicksort-pseudocode deze code gemaakt.
//bron pseudocode : https://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/7-Sort/quick-sort1.html
using namespace std;

vector<int> sorteer(vector<int> cijfers){
	int draaipunt = 0;
	int lencijfers = cijfers.size();
	cout<<lencijfers<<"is de waarde van len cijfers"<<endl;
	vector<int> gesorteerd= {};
	vector<int> links = {};
	vector<int> rechts = {};

	if(lencijfers<= 1){
		return cijfers;
	}else{
		draaipunt = cijfers.back();
		cout<<draaipunt<<"is het draaipunt van een nieuwe sorteer call"<<endl;
		for(int i = 0; i<lencijfers;i++){
			if (draaipunt > cijfers[i]){
				
				links.push_back(cijfers[i]);
				cout<<cijfers[i]<<"is het cijfer wat we verplaatsen "<<draaipunt<<" is het cijfer dat we omheen willen draaien daarom links want het is kleiner dan of gelijk aan het draaipunt"<<endl;
				
			}else{
				rechts.push_back(cijfers[i]);
				cout<<cijfers[i]<<"is het cijfer wat we verplaatsen"<<draaipunt<<"is het cijfer dat we omheen willen draaien daarom rechts want het is groter dan het draaipunt"<<endl;
				
			}
			
		}
		links.pushback()
		sorteer(links);
		sorteer(rechts);
		gesorteerd.insert(gesorteerd.end(), links.begin(), links.end() );
		gesorteerd.insert(gesorteerd.end(), rechts.begin(), rechts.end() );
		cout<<gesorteerd.front()<<gesorteerd.back()<<"zijn eerste en laatste in de vector";
		return gesorteerd;
		
	}


}

int main(){
	cout<<"START PROGRAMMA!%%%###############################################################################";
	vector<int> cijfers= {1,3,6,8,98,2};
	vector<int> sorted_cijfers =sorteer(cijfers);
	int lensortedcijfers = sorted_cijfers.size();
	for(int i = 0; i<lensortedcijfers;i++){
	cout<<sorted_cijfers[i];
	}

}

