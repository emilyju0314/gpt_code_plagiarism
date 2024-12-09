#include <iostream>

using namespace std;

int main(void)
{
  int A,B,tmp;
  string S;

  cin>>A>>B;
  cin>>S;

  tmp=A+B;
  
  for(int i=0;i<S.length();i++){
    if(S[i]>='0' && S[i]<='9')
      tmp--;
  }

  cout<<((S[A]=='-' && tmp==0) ? "Yes" : "No")<<endl;

  return 0;
}
