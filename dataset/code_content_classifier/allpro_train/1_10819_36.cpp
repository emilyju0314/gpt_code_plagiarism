#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;


vector<string> split(string v,char del){
	vector<string> strs;
	int head=0;
	for(int j = 0; j < v.size(); j++){
		if(v[j]==del){
			strs.push_back(v.substr(head,j-head));
			head=j+1;
		}
		else if(j==v.size()-1){
			strs.push_back(v.substr(head,j-head+1));
		}
	}
	return strs;
}


int main(){
    map<string,int> dict;
    dict["yotta"]=24;
    dict["zetta"]=21;
    dict["exa"]=18;
    dict["peta"]=15;
    dict["tera"]=12;
    dict["giga"]=9;
    dict["mega"]=6;
    dict["kilo"]=3;
    dict["hecto"]=2;
    dict["deca"]=1;
    dict["deci"]=-1;
    dict["centi"]=-2;
    dict["milli"]=-3;
    dict["micro"]=-6;
    dict["nano"]=-9;
    dict["pico"]=-12;
    dict["femto"]=-15;
    dict["ato"]=-18;
    dict["zepto"]=-21;
    dict["yocto"]=-24;
    int n;
    cin>>n;
    string str;
    getline(cin,str);
    while(n--){
        string num;
        string pref;
        string tani;
        //cin>>num>>pref>>tani;

        getline(cin,str);
        vector<string> strs=split(str,' ');
        num=strs[0];
        int sum=0;

        int initNotZero=-1;
        int commma=-1;
        // êÔÅÉ0ÈOªoÄ­éêÆAcommaÌÊuðT·
        for(int i = 0; i < num.size(); i++){
            if(num[i]=='.')
                commma=i;
            else if(num[i]!='0'&&initNotZero==-1)
                initNotZero=i;
        }
        if(initNotZero==0){
            int diff;
            if(commma!=-1){
                diff=commma-1;
                num=num.substr(0,commma)+num.substr(commma+1);
            }
            else
                diff=num.size()-1;
            num=num.substr(0,1)+'.'+num.substr(1);
            sum+=diff;
        }
        else{
            int diff=initNotZero-commma;
            num=num.substr(initNotZero);
            num=num.substr(0,1)+'.'+num.substr(1);
            sum-=diff;
        }
        if(num[num.size()-1]=='.'){
            num=num.substr(0,num.size()-1);
        }
        if(strs.size()==2){
            tani=strs[1];
            cout<<num<<" * "<<"10^"<<sum<<" "<<tani<<endl;
        }
        else{
            pref=strs[1];tani=strs[2];
            int t=dict[pref];
            sum+=t;
            cout<<num<<" * "<<"10^"<<sum<<" "<<tani<<endl;
        }
    }

    return 0;
}