#include <cstdio>
#include <vector>
using namespace std;

char buf[1009];

bool solve(){
	vector<int> st;
	for(int i=0; buf[i]; i++){
		st.push_back(buf[i]&15);
	}

	bool ret = false;
	while((int)st.size() > 1){
		int x = st.back(); st.pop_back();
		int y = st.back(); st.pop_back();
		int z = x + y;
		if(z <= 9){
			st.push_back(z);
		}
		else{
			st.push_back(1);
			st.push_back(z%10);
		}
		ret = !ret;
	}
	return ret;
}

int main(){
	int T;
	scanf("%d\n", &T);
	while(T--){
		scanf("%[^\n]%*c", buf);
		printf("%s wins.\n",solve()?"Fabre":"Audrey");
	}
	return 0;
}