#include<iostream>

using namespace std;
/*

memory assignment

0:  !"#$%&'()* 33-42
1:  +,-./01234 43-52
2:  56789:;<=> 53-62
3:  ?@ABCDEFGH 63-72
4:  IJKLMNOPQR 73-82
5:  STUVWXYZ[\ 83-92
6:  ]^_`abcdef 93-102
7:  ghijklmnop 103-112
8:  qrstuvwxyz 112-122
9:  {|}~       123-126
*/


const int SIZE = 10;
int bound[] = {42,52,62,72,82,92,102,112,122};
int idx = 0;
int mem[SIZE];


int boundfor(char c){
  for(int i = 0; i < 9; i++)
    if((int)c < bound[i]) return i;
  return 9;
}

void print(char c){
  int pos = boundfor(c);

  if(pos > idx) while(idx!=pos){cout << ">"; idx++;}
  if(pos < idx) while(idx!=pos){cout << "<"; idx--;}

  if(mem[idx] > (int)c) while(mem[idx]!=c){cout << "-"; mem[idx]--;}
  if(mem[idx] < (int)c) while(mem[idx]!=c){cout << "+"; mem[idx]++;}
  cout << ".";
}

int main(){
  string s;  
  cin >> s;
  for(int i = 0; i < (int)s.length(); i++) print(s[i]);
  return 0;
}