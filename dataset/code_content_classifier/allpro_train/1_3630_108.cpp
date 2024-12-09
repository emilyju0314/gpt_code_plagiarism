#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string qoo1[220],qoo2[220];
string nom1[220],nom2[220];

void pro(string qoo[],string nom[],string s,int &j,int &k){
    int len = s.length();
    bool ok = false,fg = false;
    for(int i=0; i<len; i++){
        if(ok==false&&s[i]!='\"'&&fg==false){
            fg = true;
            nom[++k]+=s[i];
            continue;
        }
        if(ok==false&&s[i]!='\"'&&fg){
            nom[k]+=s[i];
            continue;
        }
        if(ok==false&&s[i]=='\"'){
            ok = true;
            continue;
        }
        if(ok&&s[i]!='\"'){
            qoo[j]+=s[i];
            continue;
        }
        if(ok&&s[i]=='\"'){
            ok = false;
            fg = false;
            j++;
            continue;
        }
    }
    /*cout<<"qoo: "<<endl;
    for(int i=0; i<j; i++){
        cout<<qoo[i]<<" ";
    }cout<<endl;
    cout<<"nom: "<<endl;
    for(int i=0; i<=k; i++){
        cout<<nom[i]<<" ";
    }cout<<endl;*/

}
void ini(){
    for(int i=0; i<210; i++){
        qoo1[i] = "";
        qoo2[i] = "";
        nom1[i] = "";
        nom2[i] ="";
    }
}

int main(){
	string s1,s2;
	while(true){
        ini();
		cin>>s1;
		if(s1[0]=='.') break;
		cin>>s2;
		if(s1==s2){
			cout<<"IDENTICAL"<<endl;
			continue;
		}
		int len1 = s1.length(),len2 = s2.length();
		int j1=0,j2=0;
		int k1=-1,k2 =-1;
        pro(qoo1,nom1,s1,j1,k1);
        pro(qoo2,nom2,s2,j2,k2);
        if(k1!=k2||j1!=j2){
            cout<<"DIFFERENT"<<endl;
            continue;
        }
        bool ok = true;
        int cnt = 0;
        for(int i=0; i<j1; i++){
            if(qoo1[i]!=qoo2[i]) cnt++;
        }
        if(cnt>1){
            ok = false;
        }
        for(int i=0; i<=k1; i++){
            if(nom1[i]!=nom2[i]) ok = false;
        }
        if(ok){
            cout<<"CLOSE"<<endl;
            continue;
        }
        cout<<"DIFFERENT"<<endl;


	}
    return 0;
}

