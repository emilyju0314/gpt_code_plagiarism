#include<iostream>
int main() {
	int n;
	while (std::cin >> n){
		if (n == 0)break;
		int l[11][11];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)
				std::cin >> l[i][j];
			l[i][n] = 0;
			for (int j = 0; j < n; j++)
				l[i][n] += l[i][j];
		}
		for (int i = 0; i < n + 1; i++){
			l[n][i] = 0;
			for (int j = 0; j < n; j++){
				l[n][i] += l[j][i];
			}
		}
		for (int i = 0; i < n + 1; i++){
			for (int j = 0; j < n + 1; j++){
				std::cout.width(5);
				std::cout << l[i][j];
			}
			std::cout << std::endl;
		}
	}
}