#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[2][n];
	for(int j=0;j<2;j++){
		for(int i=0;i<n;i++){
			cin >> a[j][i];
		}
	}
	int temp=a[0][0];
	for(int i=0;i<n;i++){
		temp+=a[1][i];
	}

	int max=temp;
	for(int i=0;i<n-1;i++){
		temp=temp+a[0][i+1]-a[1][i];
		if(temp>max)max=temp;
	}
	cout << max << endl;
}
