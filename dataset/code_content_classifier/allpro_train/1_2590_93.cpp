#include <iostream>

using namespace std;

int n;
bool bit[600000];
int lb, lim;

int main(void)
{
	cin >> n;
	
	for(int i = 0; i < 600000; i++) bit[i] = false;
	lb = 0, lim = -1;
	
	int x;
	for(int in = 0; in < n; in++){
		cin >> x;
		
		if(bit[0]){
			cout << "No" << endl;
			continue;
		}
		if(x <= lb && x < lim){
			cout << "No" << endl;
			continue;
		}
		
		if(x >= 600000){
			lim = x;
			cout << "Yes" << endl;
			continue;
		}
		
		if(x == lb+1){
			bit[x] = true;
			lim = max(lim, x);
			for(int i = x; i < 600000; i++){
				if(bit[i]) lb = i;
				else break;
			}
		}
		else{
			for(int i = x; i >= 0; i--){
				if(!bit[i]){
					bit[i] = true;
					if(i == lb+1) lb++;
					lim = max(lim, i);
					break;
				}
				bit[i] = false;
				if(i == lim) lim--;
			}
		}
		cout << "Yes" << endl;
		
	}
	
	return 0;
}