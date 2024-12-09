#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cassert>
#include<set>
#include<cstdio>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define inf (1<<29)

using namespace std;

typedef pair<int,int> ii;

const string roulette = "abcdef";
int dx[] = {-1,-1,+0,+1,+1,+0};
int dy[] = {+1,+0,-1,-1,+0,+1};
string line1,line2;
int N;
vector<int> Index[2];

bool check(vector<ii> v1,vector<ii> v2)
{
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  rep(i,N)if(v1[i] != v2[i])return false;
  return true;
}

void compute()
{
  if(line1.size() != line2.size())
    {
      cout << "false" << endl;
      return;
    }
  N = line2.size();
  
  vector<ii> ori;
  int mx,my;
  ori.push_back(ii(0,0));
  
    int x = 0, y = 0;
    mx = my = 0;
    rep(i,N)
      {
	x += dx[line1[i]-'a'];
	y += dy[line1[i]-'a'];
	mx = min(mx,x);
	my = min(my,y);
	ori.push_back(ii(x,y));
      }
  

  rep(i,ori.size())ori[i].first -= mx, ori[i].second -= my;


  rep(j,7)//dir
    {
      vector<ii> cont;
      cont.push_back(ii(0,0));
      x = y = 0;
      mx = x, my = y;
      rep(i,N)
	{
	  x += dx[(line2[i]-'a'+j)%6];
	  y += dy[(line2[i]-'a'+j)%6];
	  mx = min(mx,x);
	  my = min(my,y);
	  cont.push_back(ii(x,y));
	}
      
      rep(i,cont.size())cont[i].first -= mx,cont[i].second -= my;
      
      if(check(ori,cont))
	{
	  cout << "true" << endl;
	  return;
	}
      
    }
      
    
  
  
  cout << "false" << endl;
}


int main()
{
  int n; 
  while(cin >> n)
    {
      cin.ignore();
      string blank;
      while(n--)
	{
	  line1.clear();
	  line2.clear();
	  char c;
	  while((c = getchar()) != '\n')line1 += c;
	  while((c = getchar()) != '\n')line2 += c;
	  cin >> blank;
	  cin.ignore();
	  compute();
	}
    }
  return 0;
}