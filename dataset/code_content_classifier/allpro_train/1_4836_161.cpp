#include <iostream>
#include <algorithm>
template <class T> void dwrite(T o){
	std::cout << o << std::endl;
}

struct place{int num;int votes;};

bool psort(const place& l, const place& r){
	if(l.votes == r.votes)return l.num < r.num;
	return l.votes > r.votes;
}

int main(){
	int n, m;
	while(std::cin >> n >> m, n && m){
		place p[100] = {{0,0}};
		int f;
		while(n--){
			for(int i=0;i<m;i++){
				std::cin >> f;
				p[i].num = i + 1;
				p[i].votes += f;
			}
		}
		std::sort(p,p+100,psort);
		std::cout << p[0].num;
		for(int i=1;i<m;i++){
			std::cout << " " << p[i].num;
		}
		std::cout << "\n";
	}
}