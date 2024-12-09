#include <bits/stdc++.h>

using namespace std;

int main()
{
  int m;
  while(cin >> m, m){
    vector< vector<int> > cubes;
    for(int i = 0; i < m; i++){
      vector<int> cube;
      cube.push_back(i+1);
      cubes.push_back(cube);
    }
    int I, J;
    while(cin >> I >> J, I || J){
      int Ip = -1, Ii = -1, Jp = -1, Ji = -1;
      for(int i = 0; i < (int)cubes.size(); i++){
	for(int j = 0; j < (int)cubes[i].size(); j++){
	  if(cubes[i][j] == I) Ip = i, Ii = j;
	  if(cubes[i][j] == J) Jp = i, Ji = j;
	}
      }
      if(Ip == Jp && Ii >= Ji) continue;
      if(J == 0 && Ii == 0) continue;
      while(cubes[Ip].back() != I){
	vector<int> cube;
	cube.push_back(cubes[Ip].back());
	cubes[Ip].pop_back();	  
	cubes.push_back(cube);
      }
      for(int i = 0; i < (int)cubes.size(); i++){
	for(int j = 0; j < (int)cubes[i].size(); j++){
	  if(cubes[i][j] == J) Jp = i, Ji = j;
	}
      }
      if(J == 0){
	vector<int> cube;
	cube.push_back(cubes[Ip].back());
	cubes[Ip].pop_back();
	cubes.push_back(cube);
      } else {
	cubes[Jp].push_back(cubes[Ip].back());
	cubes[Ip].pop_back();
      }
    }
    vector<int> out;
    for(int i = 0; i < (int)cubes.size(); i++){
      if((int)cubes[i].size() != 0) out.push_back((int)cubes[i].size());
    }
    sort(out.begin(), out.end());
    for(int i = 0; i < (int)out.size(); i++) cout << out[i] << endl;
    cout << "end" << endl;
  }
  return 0;
}