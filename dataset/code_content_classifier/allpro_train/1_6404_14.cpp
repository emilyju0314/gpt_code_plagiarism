#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	int answer = 0;
	for(int i = 0, last = 0; i + 3 <= n; ++i){
		if(a[i] > a[i + 1] && a[i + 1] > a[i + 2]){
			if(last != 0){
				swap(a[i], a[i + 1]);
				swap(a[i + 1], a[i + 2]);
			}else{
				swap(a[i + 1], a[i + 2]);
				++answer;
			}
			last = -1;
		}else if(a[i] < a[i + 1] && a[i + 1] < a[i + 2]){
			if(last != 0){
				swap(a[i], a[i + 1]);
				swap(a[i + 1], a[i + 2]);
			}else{
				swap(a[i + 1], a[i + 2]);
				++answer;
			}
			last = 1;
		}else{
			last = 0;
		}
	}
	cout << answer << endl;
	return 0;
}


