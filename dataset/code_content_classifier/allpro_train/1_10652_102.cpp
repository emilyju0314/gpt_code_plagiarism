#include<iostream>
int main(){
	int na,nb;
	while(1){
		std::cin>>na;
		if(na == 0) break;
		std::cout<<"Case "<<++nb<<": "<<na<<std::endl;
	}
	return 0;
}