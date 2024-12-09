#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
double a,b;
while(cin >> a >> b){
string ans="NA";
if(a<70.0&&b<148.0)ans="E";
if(a<55.0&&b<116.0)ans="D";
if(a<50.0&&b<105.0)ans="C";
if(a<43.0&&b<89.0)ans="B";
if(a<40.0&&b<83.0)ans="A";
if(a<37.5&&b<77.0)ans="AA";
if(a<35.5&&b<71.0)ans="AAA";
cout << ans << "\n";
}
return 0;
}