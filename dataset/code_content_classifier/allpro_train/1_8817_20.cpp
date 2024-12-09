// 18:30~

#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

#define dump(n) cerr<<"# "<<#n<<'='<<(n)<<endl

map<string,int> getstates(string board,int maxturn)
{
	map<string,int> m;
	queue<pair<string,int>> q;
	q.emplace(board,0);
	while(q.size()){
		string cb=q.front().first;
		int cc=q.front().second;
		q.pop();
		if(m.count(cb))
			continue;
		m.insert(make_pair(cb,cc));
		
		if(cc==maxturn)
			continue;
		for(int i=0;i<5;i++)
			for(int j=abs(i-2);j<5-abs(i-2);j++){
				if(cb[i*5+j]!='.')
					continue;
				for(int k=0;k<4;k++){
					int ni=i+"\xff\x1\0\0"[k],nj=j+"\0\0\xff\x1"[k];
					if(ni<0 || 5<=ni || nj<abs(ni-2) || 5-abs(ni-2)<=nj || cb[ni*5+nj]=='.')
						continue;
					swap(cb[i*5+j],cb[ni*5+nj]);
					q.emplace(cb,cc+1);
					swap(cb[i*5+j],cb[ni*5+nj]);
				}
			}
	}
	return m;
}

int main()
{
	for(;;){
		string board(25,'#');
		for(int i=0;i<5;i++)
			for(int j=abs(i-2);j<5-abs(i-2);j++){
				int x; scanf("%d",&x);
				board[i*5+j]=x?x-1+'a':'.';
			}
		if(feof(stdin)) break;
		
		map<string,int> m1=getstates(board,10);
		map<string,int> m2=getstates("##.###abc#defgh#ijk###.##",10);
		
		int res=999;
		for(auto kv:m1)
			if(m2.count(kv.first))
				res=min(res,kv.second+m2[kv.first]);
		
		if(res==999)
			cout<<"NA"<<endl;
		else
			cout<<res<<endl;
	}
	
	return 0;
}