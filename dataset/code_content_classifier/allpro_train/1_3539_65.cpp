#include<iostream>
#include<queue>
#define MAX_N 50

using namespace std;

int n;
int data[MAX_N];

queue<int> que;

void countPages(){
	int start, end;
	for (int i = 0; i < n; i++)
	{
		if (i == 0){
			start = data[0];
		}
		else{
			if (data[i - 1] + 1 != data[i]){
				end = data[i - 1];
				if (start == end){
					cout << start << " ";
				}
				else{
					cout << start << "-" << end << " ";
				}
				start = data[i];
			}
		}
		if (i == n - 1){
			if (start == data[i]){
				cout << start;
			}
			else{
				cout << start << "-" << data[i];
			}
		}
	}
	cout << endl;
}

int main(){
	while (1){
		int x;
		cin >> x;
		que.push(x);
		if (x == 0)break;
	}
	while (1){
		n = que.front();
		que.pop();
		if (n == 0)break;
		for (int i = 0; i < n; i++){
			data[i] = que.front();
			que.pop();
		}
		countPages();
	}
	return 0;
}