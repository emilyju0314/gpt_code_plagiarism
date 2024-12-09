#include <iostream>

int main()
{
	int n; std::cin >> n;
	int* A = new int[n];
	
	for (int i=0; i<n; i++) std::cin >> A[i];
	
	int q; std::cin >> q;
	for (int i=0; i<q; i++) {
		int b, e, k;
		std::cin >> b >> e >> k;
		int count = 0;
		for (int j=b; j<e; j++) {
			count += A[j]==k ? 1 : 0;
		}
		std::cout << count << std::endl;
	}
	
	delete[] A;
	
	return 0;
}
		

