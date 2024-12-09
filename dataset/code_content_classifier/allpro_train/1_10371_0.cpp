#include <iostream>

int main(void) {
	int A, B;
	std::cin >> A >> B;
	std::cout << std::max(0, A-2*B) << std::endl;
	return 0;
}
