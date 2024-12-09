#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValid(vector<int> array, int add, int pairNum){
	array[add]++;
	// cannot use same number over 4 times
	for (int i = 1; i < 10; i++) {
		if (array[i] > 4) {
			return false;
		}
	}
	if(array[pairNum] < 2) return false;
	else array[pairNum] -= 2;
	// main
	for (int i = 1; i < 10; i++) {
		if (array[i] < 3 && i < 8) { // find straight
			if(array[i+1] < array[i] || array[i+2] < array[i]) return false;
			array[i+2] -= array[i];
			array[i+1] -= array[i];
			array[i] = 0;
		}else if(array[i] >= 3){ // find 3 same numbers
			array[i] -= 3;
			i--;
		}else if (array[i] > 0) {
			return false;
		}
	}
	return true;
}

bool solve(vector<int> array, int add){
	// setPair
	for (int i = 1; i < 10; i++) {
		if(isValid(array, add, i)) return true;
	}
	return false;
}

int main(){
	string str;
	bool hasAns;
	vector<int> array;
	while(cin >> str){
		// initialize
		hasAns = false;
		array.clear();
		for (int i = 0; i < 10; i++) {
			array.push_back(0);
		}
		for (int i = 0; i < str.size(); i++) {
			array[str[i] - '0']++;
		}
		for (int i = 1; i < 10; i++) {
			if (solve(array, i)) {
				if (hasAns) {
					cout << " " << i;
				}else {
					hasAns = true;
					cout << i;
				}
			}
		}
		if (hasAns) {
			cout << endl;
		}else {
			cout << "0" << endl;
		}
	}
	return 0;
}