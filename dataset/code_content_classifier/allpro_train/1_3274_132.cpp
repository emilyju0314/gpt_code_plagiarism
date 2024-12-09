#include<cstdio>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<algorithm> 
using namespace std;
map<string,int> table;
int nex[4]={-4,4,-1,1};
void bfs(string str)
{
    queue<string> que;
    table[str]=1;
    que.push(str);
    while(!que.empty()){
        str=que.front();
        que.pop();
        int num=str.find('0');
        for(int i=0;i<4;i++){
            int tx=num+nex[i];
            if(tx<0||tx>7||(num==3&&nex[i]==1)||(num==4&&nex[i]==-1))
                continue;
            string ss=str;
            swap(ss[num],ss[tx]);
            if(!table[ss]){
                table[ss]=table[str]+1;
                que.push(ss);
            }
        }
    }
}
int main()
{
	int t;
    string st("01234567");
    bfs(st);
    while(scanf("%d",&t)!=EOF){
        st[0]='0'+t;
        for(int i=1;i<8;i++){
            scanf("%d",&t);
            st[i]='0'+t;
        }
        printf("%d\n",table[st]-1);
    }
    return 0;
}