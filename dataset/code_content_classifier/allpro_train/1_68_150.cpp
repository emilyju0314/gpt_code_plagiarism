#include<iostream>

int main(){
	const int MAX_N = 100;
	int n, a[MAX_N];
	while(std::cin >> n, n){
		for(int i=0;i<n;i++){
			std::cin >> a[i];
		}

		int t = 0;
		while(true){
			bool update = false;
			for(int i=0;i<n-1;i++){
				if(a[i] > a[i+1]){
					std::swap(a[i], a[i+1]);
					t++;
					update = true;
				}
			}
			
			if(!update){
				break;
			}
		}

		std::cout << t << std::endl;
	}
}