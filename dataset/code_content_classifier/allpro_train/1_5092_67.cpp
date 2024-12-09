#include "iostream"
using namespace std;

int main(){
	int target;
	while(cin >> target){
		int ans = 2;
		for(int i = 2; i <= target; i ++){
			ans += i;	
		}
		cout << ans << endl;
	}
}