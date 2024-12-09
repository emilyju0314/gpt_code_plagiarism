#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void setPos(string &buff,int &pos){
    for(int i = 0; i < buff.size(); i++){
        if(buff[i]=='^'){
            pos=i;
            return;
        }
    }
}

int main(){
    int n;
    cin>>n;
    string gb;
    getline(cin,gb);
    while(n--){
        string buff;
        getline(cin,buff);
        int m;
        cin>>m;
        getline(cin,gb);
        int pos=0;
        buff='^'+buff;
        while(m--){
            string op;
            getline(cin,op);
            if(op=="forward char"){
                if(pos!=buff.size()-1){
                    swap(buff[pos],buff[pos+1]);
                    pos++;
                    setPos(buff,pos);
                }
            }
            else if(op=="forward word"){
                // ツ右ツづ可閉カツ篠堋づーツ探ツつオツづ可つ「ツつォツ、ツ個ゥツづつつゥツづつスツづァツつサツづ個閉カツ篠堋療アツづ個催渉可づ個暗環置ツづ慊づカツーツソツδ仰づーツ暗堋督ョ
                if(pos!=buff.size()-1){
                    int initPos=pos;
                    pos++;
                    while(pos<buff.size()&&buff[pos]==' ')pos++;
                    while(pos<buff.size()&&buff[pos]!=' ')pos++;
                    buff=buff.substr(0,initPos)+buff.substr(initPos+1);
                    if(pos-1==buff.size())
                        buff+='^';
                    else{
                        pos--;
                        buff=buff.substr(0,pos)+'^'+buff.substr(pos);
                    }
                    setPos(buff,pos);
                }
            }
            else if(op=="backward char"){
                if(pos!=0){
                    swap(buff[pos],buff[pos-1]);
                    setPos(buff,pos);
                }
            }
            else if(op=="backward word"){
                if(pos!=0){
                    int initPos=pos;
                    pos--;
                    while(pos>=0&&buff[pos]==' ')pos--;
                    bool ok=false;
                    while(pos>=0&&buff[pos]!=' '){
                        ok=true;
                        pos--;
                    }
                    buff=buff.substr(0,initPos)+buff.substr(initPos+1);
                    if(pos==-1)
                        buff='^'+buff;
                    else{
                        pos++;
                        buff=buff.substr(0,pos)+'^'+buff.substr(pos);
                    }
                    setPos(buff,pos);
                }
            }
            else if(op=="delete char"){
                if(pos!=buff.size()-1)
                    buff=buff.substr(0,pos+1)+buff.substr(pos+2);
                setPos(buff,pos);
            }
            else if(op=="delete word"){
                int initPos=pos;
                if(pos!=buff.size()-1){
                    pos++;
                    while(pos<buff.size()&&buff[pos]==' ')pos++;
                    bool f=false;
                    while(pos<buff.size()&&buff[pos]!=' '){
                        f=true;
                        pos++;
                    }
                    // ツ単ツ古ェツづーツづ青づづつづづv è
                    if(!f){

                    }
                    else{
                        if(pos==buff.size())
                            buff=buff.substr(0,initPos+1);
                        else
                            buff=buff.substr(0,initPos+1)+buff.substr(pos);
                    }
                    setPos(buff,pos);
                }
            }
            else if(op.substr(0,6)=="insert"){
                string ins=op.substr(7);
                ins=ins.substr(1);
                ins=ins.substr(0,ins.size()-1);
                buff=buff.substr(0,pos)+ins+'^'+buff.substr(pos+1);
                setPos(buff,pos);
            }
        }
        cout<<buff<<endl;
    }
    return 0;
}