#include<iostream>
#include<vector>

using namespace std;

const int MAX_D = 11;
int m,c,n,ans;
vector<int> req;
vector<int> D[MAX_D];

void input(){
  vector<int> tmp[n];
  int sum = 0;

  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    sum += num;
    for(int j = 0; j < num; j++){
      int in;
      cin >> in;
      tmp[i].push_back(in);
    }
  }
  
  int pos = 0;
  while(sum){
    for(int i = 0; i < n; i++)
      if(tmp[i].size() > pos){
	req.push_back(tmp[i][pos]);
	sum--;
      }
    pos++;
  }

  D[m] = req;
}

void init(){
  req.clear();
  for(int i = 0; i < MAX_D; i++)
    D[i].clear();
  ans = 0;
}

int find(int num){

  vector<int>::iterator ite;

  for(int i = 0; i <= m; i++)
    for(ite = D[i].begin(); ite < D[i].end(); ite++)
      if(*ite == num){
	D[i].erase(ite);
	return i+1;
      }
}

int ret(int num){
  int cost = 0;

  if(D[0].size() < c){
    D[0].push_back(num);
    return 1;
  }else{
    int minpos = m;
    for(int i = 0; i < m; i++)
      if(D[i].size() < c){
	minpos = i;
	break;
      }

    //from counter to minpos+1
    cost += minpos+1;

    int tmppos = m;
    for(int i = 0; i < m; i++)
      if(i == minpos){
	if(D[i].size()+1 < c){
	  tmppos = i;
	  break;
	}
      }else if(D[i].size() < c){
	tmppos = i;
	break;
      }
    //from 1 to (tmppos+1)
    cost+=tmppos+2;

    D[tmppos].push_back(D[0][0]);
    D[0].erase(D[0].begin());


    D[0].push_back(num);

    //from (minpos+1) to 1
    cost += minpos+2;
  }
  return cost;
}
void solve(){

  for(int i = 0; i < req.size(); i++){
    int fpos = find(req[i]);
    int rcos = ret(req[i]);
    ans += fpos+rcos;
  }
  cout << ans << endl;
}

int main(){

  while(cin >> m >> c >> n && m+c+n){
    init();
    input();
    solve();
  }
  return 0;
}