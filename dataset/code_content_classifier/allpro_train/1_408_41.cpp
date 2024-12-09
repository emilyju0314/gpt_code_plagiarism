#include<iostream>
#include<string>
using namespace std;

int main(){
  string str;
  cin >> str;
  int count[3] = {0,0,0};

  for(int i = 0 ; i < str.size() ; i++){
    count[str[i]-'a']++;
  }

  int mini = 1e9;
  for(int i = 0 ; i < 3 ; i++){
    mini = min(mini,count[i]);
  }

  for(int i = 0 ; i < 3 ; i++){
    count[i] = count[i] - mini;
  }

  bool flag = true;
  for(int i = 0 ; i < 3 ; i++){
    if(count[i] >= 2){
      flag = false;
    }
  }
  cout << (flag ? "YES" : "NO") << endl;
  return 0;
}
