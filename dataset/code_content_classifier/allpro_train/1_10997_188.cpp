#include <iostream>
using namespace std;

int insertionSort( int a[], int N, int g){
	int cnt = 0;
	for ( int i = g; i < N; i++ ){
		int v = a[i];
		int j = i - g;
		while ( j >= 0 && a[j] > v){
			a[j+g] = a[j];
			j -= g;
			cnt++;
		}
		a[j+g] = v;
	}
	return cnt;
}

void shellSort(int a[], int N){
	int cnt = 0;
	int G[100];
	int m = 0;
	int num = N;
	if (num < 3){
		G[0] = 1;
		m++;
	}
	else{
	    while ( num > 1 ){
		    num = num/3+1;
		    G[m] = num;
		    m++;
    	}
	}
	cout << m << endl;
	for ( int i = 0; i < m; i++){
		cout << G[i] << " ";
		cnt += insertionSort(a, N, G[i]);
	}
	cout << endl;
	cout << cnt << endl;
	for ( int i = 0; i < N; i++) cout << a[i] << endl;
}

int main(){
	int N;
	int a[1000000];
	cin >> N;
	for ( int i = 0; i < N; i++) cin >> a[i];

	shellSort(a, N);

	return 0;
}
