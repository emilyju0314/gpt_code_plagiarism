#include <iostream>

using namespace std;

int prime(int n)
{
	if(n < 2){
		return 0;
	} else if(n == 2){
		return 1;
	}
	
	if(n % 2 == 0){
		return 0;
	}
	
	for(int i = 3; i*i <= n; i+= 2){
		if(n % i == 0){
			return 0;
		}
	}
	
	return 1;
}

int main(int argc, char **argv)
{
	int n, s;
	
	while(1){
		cin >> n;
		if(n == 0){
			break;
		}
		s = 0;
		for(int i = 2, c = 0; c < n; i++){
			if(prime(i) == 1){
				s += i;
				c++;
			}
		}
		
		cout << s << endl;
	}
	
	return 0;
}