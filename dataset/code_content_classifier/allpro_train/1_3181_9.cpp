#include <iostream>

int main(){
	int A,B,C;
	std::cin>>A>>B>>C;
	if(A+B >= C){
		std::cout<<(B+C);
	}else{
		std::cout<<(A+2*B+1);
	}
	return 0;
}
