#include<iostream>
#include<algorithm>
#include<map>
#include<cassert>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define inf (1<<29)
#define MAX 500001

using namespace std;

map<string,int> getIndex;
int t,s;
bool found;
int T[MAX],S[MAX];
string type[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
int dc[] = {+0,+1,-1};
int dx[] = {-1,-2,+1};

void dfs(int cur_t,int cur_s)
{
  if(cur_s < 0)
    {
      if(cur_t == -1)found = true;
      return;
    }

  rep(i,3)
    {
      int music = (T[cur_t] + dc[i] + 12)%12;
      if(t <= cur_t+dx[i])continue;

      if(music == S[cur_s])dfs(cur_t+dx[i],cur_s-1);
    }
}

bool compute()
{
  found = false;
  dfs(t-1,s-1);
  if(!found)dfs(t-2,s-1);
  return found;
}

int main()
{
  rep(i,12)getIndex[type[i]] = i;
  int N;
  while(cin >> N)
    {
      while(N--)
	{

	  cin >> t >> s;
	  string input;
	  rep(i,t)
	    {
	      cin >> input;
	      T[i] = getIndex[input];
	    }
	  rep(i,s)
	    {
	      cin >> input;
	      S[i] = getIndex[input];
	    }
	  cout << (compute()?"Yes":"No") << endl;
	}
    }
  return 0;
}