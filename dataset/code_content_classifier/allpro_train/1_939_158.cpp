#include <iostream>
#include <string>
 
using namespace std;
 
typedef unsigned long long ull;
 
#define loop(i,a,b) for(int i=(a); i<(int)(b); i++)
#define rep(i,b) loop(i,0,b)
 
int main(){
    int n; cin>>n;
    cin.ignore();
    while(n--){
        string s; getline(cin,s);
        size_t beg;
        while(beg=s.find("Hoshino"), beg!=string::npos){
            s[beg+6]='a';
        }
        cout<<s<<endl;
    }
}