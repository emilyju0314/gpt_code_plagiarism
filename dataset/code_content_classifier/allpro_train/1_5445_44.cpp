#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef pair<P,P> Edge;
typedef long long ll;

const double PI=4*atan(1.0);

//#define RED_FILE

#ifdef RED_FILE
ifstream ifs("input.txt");
ofstream ofs("output.txt");
#define cin ifs
#define cout ofs
#endif

map<char,map<int,int> > mcmii;
map<char,int> arraySize;

bool ok;

int rvalAnalysis(string s){
    bool isNum=true;
    for(int i = 0; i < s.size(); i++){
        if(!(s[i]>='0'&&s[i]<='9')){
            isNum=false;
            break;
        }
    }
    if(isNum){
        int num=atoi(s.c_str());
        return num;
    }
    char head=s[0];
    int idx=rvalAnalysis(s.substr(2,s.size()-3));
    if(arraySize.find(head)==arraySize.end()){
        ok=false;
        return 0;
    }
    if(mcmii.find(head)==mcmii.end()){
        ok=false;
        return 0;
    }
    if(mcmii[head].find(idx)==mcmii[head].end()){
        ok=false;
        return 0;
    }
    return mcmii[head][idx];
}

pair<char,int> lvalAnalysis(string s){
    // ツ参ツ湘嘉督渉環づーツパツーツズ
    char head=s[0];
    int idx=rvalAnalysis(s.substr(2,s.size()-3));
    return pair<char,int>(head,idx);
}


bool analysis(string s){
    for(int i = 0; i < s.size(); i++){
        // ツ妥」ツ禿シツ閉カ
        if(s[i]=='='){
            pair<char,int> l=lvalAnalysis(s.substr(0,i));
            int r=rvalAnalysis(s.substr(i+1));
            if(!ok)return false;
            if(arraySize.find(l.first)==arraySize.end())
                return false;
            else if(arraySize[l.first]<=l.second)
                return false;
            else{
                // ツ妥」ツ禿シ
                mcmii[l.first][l.second]=r;
                return true;
            }
        }
    }
    // ツ妥」ツ禿シツ閉カツづづ按つ「ツ湘ェツ債づ債、ツ静ゥツ個セ
    pair<char,int> info=lvalAnalysis(s);
    if(!ok)return false;
    if(arraySize.find(info.first)!=arraySize.end())return false;
    arraySize[info.first]=info.second;
    return true;
}

int main(){
    string first;
    while(cin>>first&&!(first==".")){
        vector<string> vs;
        vs.push_back(first);
        ok=true;
        mcmii.clear();
        arraySize.clear();
        string str;
        while(cin>>str&&!(str=="."))
            vs.push_back(str);
        for(int i = 0; i < vs.size(); i++){
            bool res=analysis(vs[i]);
            if(!res||!ok){
                cout<<i+1<<endl;
                ok=false;
                break;
            }
        }
        if(ok)cout<<0<<endl;
    }

    return 0;
}