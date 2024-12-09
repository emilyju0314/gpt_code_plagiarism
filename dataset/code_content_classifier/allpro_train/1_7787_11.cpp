#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int NOPAIR = -1;
const int ONEPAIR = 0;
const int TWOPAIR = 1;
const int THREECARD = 2;
const int STRAIGHT = 3;
const int FLUSH = 4;
const int FULLHOUSE = 5;
const int FOURCARD = 6;
const int STRAIGHTFLUSH = 7;
const int ROYALSTRAIGHTFLUSH = 8;

int N,C[4][13],P[9];

struct card{
  int n;
  char s;
  bool operator < (const card& c) const {return n < c.n;}
};


void input(){
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 13; j++) cin >> C[i][j];

  for(int i = 0; i < 9; i++) cin >> P[i];
}

int getMaxSameNum(const vector<card>& V){
  
  int ret = 0;

  for(int i = 0; i < (int)V.size(); i++){
    int tmp = 0;
    for(int j = i; j < (int)V.size(); j++)
      if(V[i].n == V[j].n) tmp++;
    ret = max(ret,tmp);
  }
  return ret;
}


bool isStraight(const vector<card>& V){
  for(int i = 0; i < (int)V.size()-1; i++)
    if(V[i].n+1 != V[i+1].n) return false;
  return true;
}

bool isSameSuit(const vector<card>& V){
  char c = V[0].s;
  for(int i = 0; i < (int)V.size(); i++)
    if(c != V[i].s) return false;
  return true;
}

vector<int> getPair(const vector<card>& V){
  int tmp[13] = {0};
  vector<int> res;
  for(int i = 0; i < (int)V.size(); i++) tmp[V[i].n-1]++;
  
  for(int i = 0; i < 13; i++)
    if(tmp[i] > 0) res.push_back(tmp[i]);
  sort(res.begin(),res.end());
  return res;
}

int getRank(int knum, bool straight, bool samesuit, vector<int> pnum, int minnum){
  if(samesuit && straight && minnum == 10) return ROYALSTRAIGHTFLUSH;
  if(straight && samesuit) return STRAIGHTFLUSH;
  if(knum == 4) return FOURCARD;
  if(pnum.size() == 2 && pnum[0] == 2 && pnum[1] == 3) return FULLHOUSE;
  if(samesuit) return FLUSH;
  if(straight) return STRAIGHT;
  if(knum == 3) return THREECARD;
  if(pnum.size() == 3 && pnum[0] == 1 && pnum[1] == 2 && pnum[2] == 2) return TWOPAIR;
  if(pnum.size() == 4 && pnum[0] == 1 && pnum[1] == 1 && pnum[2] == 1 && pnum[3] == 2) return ONEPAIR;
  return NOPAIR;
}

void solve(){

  while(N--){
    vector<card> V(5);
    for(int i = 0; i < 5; i++){
      char num;
      cin >> num >> V[i].s;
      if(num == 'T') V[i].n = 10;
      else if(num == 'J') V[i].n = 11;
      else if(num == 'Q') V[i].n = 12;
      else if(num == 'K') V[i].n = 13;
      else if(num == 'A') V[i].n = 1;
      else V[i].n = num-'0';
    }
    
    sort(V.begin(),V.end());
    
    int rank = getRank(getMaxSameNum(V),isStraight(V),isSameSuit(V),getPair(V),V[0].n);

    if(V[0].n == 1){
      V[0].n = 14;
      sort(V.begin(),V.end());
      rank = max(rank,getRank(getMaxSameNum(V),isStraight(V),isSameSuit(V),getPair(V),V[0].n));
    }


    int res = 0;
    
    //  cout << "knum " << getMaxSameNum(V) << endl;
    // cout << "rank " << rank << endl;

    if(V[4].n == 14) V[4].n = 1;

    if(rank >= 0){
      for(int i = 0; i < 5; i++){
	int suit;
	if(V[i].s == 'S') suit = 0;
	if(V[i].s == 'C') suit = 1;
	if(V[i].s == 'H') suit = 2;
	if(V[i].s == 'D') suit = 3;
	res += C[suit][V[i].n-1];
      }
      res *= P[rank];
    }
    cout << res << endl;
  }
}

int main(){
  bool f = false;

  while(cin >> N){
    if(f) cout << endl;
    else f = true;
    input();
    solve();
  }
  return 0;
}