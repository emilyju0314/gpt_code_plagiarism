#include <iostream> 
#include <stack>
using namespace std;

int main(){
	int d;
	while(cin>>d){
		int ans=0;
		for(int i=d;i<600;i+=d){
			ans+=i*i*d;
		}
		cout<<ans<<endl;
	}
    return 0;
}