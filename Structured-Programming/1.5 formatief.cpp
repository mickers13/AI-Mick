#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void sorteer(vector<int> &list);
void sorteer_hulp(vector<int> &list, size_t i, size_t j);
size_t split(vector<int>&, size_t, size_t, size_t);

int main() {
	vector<int> cijfers = {5, 3, 8, 4, 6, 1, -2};
	sorteer(cijfers);
	for(int i = 0; i < cijfers.size(); i++)
		cout << cijfers[i] << endl;
	return 0;
}

void sorteer(vector<int>& list) {
	sorteer_hulp(list, 0, list.size());
}

void sorteer_hulp(vector<int> &list, size_t i, size_t j){
	if (j - i <= 1)
		return;
	size_t piv = split(list, i, j, i);
	sorteer_hulp(list, i, piv);
	sorteer_hulp(list, piv + 1, j);
}

size_t split(vector<int> &list, size_t i, size_t j, size_t piv) {
	j -= 1;
	while(j - i > 0) {
		if (list[i + 1] <= list[i]) {
			swap(list[i], list[i + 1]);
			i++;
		} else {
			swap(list[j], list[i + 1]);
			j--;
		}
	} 
	return i;
}
