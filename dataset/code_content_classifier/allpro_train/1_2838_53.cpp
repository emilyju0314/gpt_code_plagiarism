#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stdlib.h>
#define inf 0x3f3f3f
using namespace std;
int main()
{
    string a;
    while(getline(cin,a))
    {
        while(a.find("the")==-1&&a.find("this")==-1&&a.find("that")==-1)
        {
            for(int i=0;i<a.size();i++)
            {
                if('a'<=a[i]&&a[i]<'z')
                    a[i]++;
                else if(a[i]=='z')
                    a[i]='a';
            }
        }
         cout<<a<<endl;
    }
   return 0;
}

