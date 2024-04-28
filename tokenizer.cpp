#include <stdlib.h>
#include<ctype.h>
#include <iostream>
#include <cstring>
#include <boost/tokenizer.hpp>
#include<vector>
using namespace std;
int cSize=0;
vector<string> ans;
vector<string> comm_token;
string origin_code;
string origin_comm;
bool Alldigit(string a){
    for(int i=0;i<a.length();i++)
        if(isdigit(a[i])==false) return false;
    return true;
}
extern "C"{
bool token(string str){
try{
  //string str ;//="//12345\n \'single quotes\' \"double quotes\" + ++ += - -- -= -> ->* * *= & && &= | || |= ! != % %= = == : :: ^ ^= # ## > >= >> >>= < <= << <<=  /= /* */ . .. ... 0.123 .12. .abc. ";
  boost::char_separator<char> sep(""," \n\r\t\v\f#,!+-/=~*(){};&|!%*\\:^><.\"\'");
  //for(int i=0;i<argv.size();i++){
  //str=argv[i];
  boost::tokenizer< boost::char_separator<char> > tokens(str, sep);
  boost::tokenizer< boost::char_separator<char> >::iterator tok_iter;
   boost::tokenizer< boost::char_separator<char> >::iterator re;
   /*for( tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter){
       cout<<*tok_iter<<endl;
   }*/
  for( tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter){
    string temp=*tok_iter;
    //cout<<temp<<endl;
    re=tok_iter;
    if(temp=="\""){
        ++tok_iter;
        for(;*tok_iter!="\""&&tok_iter!=tokens.end();++tok_iter)
            temp+=*tok_iter;
        temp+="\"";
    }
    if(temp=="\'"){
        ++tok_iter;
        for(;*tok_iter!="\'"&&tok_iter!=tokens.end();++tok_iter)
            temp+=*tok_iter;
        temp+="\'";
    }
    if(temp=="+"){
        ++tok_iter;
        if(*tok_iter=="+" or *tok_iter=="=")
            temp+=*tok_iter;
        else tok_iter=re;
    }
    if(temp=="-"){
        ++tok_iter;
        if(*tok_iter=="-" or *tok_iter=="=")
            temp+=*tok_iter;
        else if(*tok_iter==">"){
            temp+=*tok_iter;
            re=tok_iter;
            ++tok_iter;
            if(*tok_iter=="*")
                temp+=*tok_iter;
            else tok_iter=re;
        }else tok_iter=re;
    }
    if(temp=="*"){
        tok_iter++;
        if(*tok_iter=="=")
            temp+=*tok_iter;
        else tok_iter=re;
    }
    if(temp=="&"){
        tok_iter++;
        if(*tok_iter=="&" or *tok_iter=="=")
            temp+=*tok_iter;
        else tok_iter=re;
    }
    if(temp=="|"){
        tok_iter++;
        if(*tok_iter=="|" or *tok_iter=="=")
            temp+=*tok_iter;
        else tok_iter=re;
    }
    if(temp=="!"){
        tok_iter++;
        if(*tok_iter=="=")
            temp+=*tok_iter;
        else tok_iter=re;
    }
    if(temp=="%"){
        tok_iter++;
        if(*tok_iter=="=")
            temp+=*tok_iter;
        else tok_iter=re;
    }
    if(temp=="="){
        tok_iter++;
        if(*tok_iter=="=")
            temp+=*tok_iter;
        else tok_iter=re;
    }
    if(temp==":"){
        tok_iter++;
        if(*tok_iter==":")
            temp+=*tok_iter;
        else tok_iter=re;
    }
    if(temp=="^"){
        tok_iter++;
        if(*tok_iter=="=")
            temp+=*tok_iter;
        else tok_iter=re;
    }
    if(temp=="#"){
        tok_iter++;
        if(*tok_iter=="#")
            temp+=*tok_iter;
        else tok_iter=re;
    }
    if(temp==">"){
        tok_iter++;
        if(*tok_iter=="=")
            temp+=*tok_iter;
        else if(*tok_iter==">"){
            temp+=*tok_iter;
            re=tok_iter;
            tok_iter++;
            if(*tok_iter=="=")
                temp+=*tok_iter;
            else tok_iter=re;
        }else tok_iter=re;
    }
    if(temp=="<"){
        tok_iter++;
        if(*tok_iter=="=")
            temp+=*tok_iter;
        else if(*tok_iter=="<"){
            temp+=*tok_iter;
            re=tok_iter;
            tok_iter++;
            if(*tok_iter=="=")
                temp+=*tok_iter;
            else tok_iter=re;
        }else tok_iter=re;
    }
    if (temp == "/") {
        ++tok_iter;
        if (*tok_iter == "/") {
            while (tok_iter != tokens.end() && *tok_iter != "\n") {
                temp+=*tok_iter,++tok_iter;
            }
        } else if (*tok_iter == "*") {
            bool comment_closed = false;
            while (tok_iter != tokens.end() && !comment_closed) {
                //cout<<*tok_iter<<endl;
                temp+=*tok_iter;
                ++tok_iter;
                if (*tok_iter == "*") {
		   temp+=*tok_iter;
                    ++tok_iter;
                    if (tok_iter != tokens.end() && *tok_iter == "/") {
                        comment_closed = true;
                        temp+="/";
                    }
                }
            }
            if (!comment_closed)
                cerr << "Unclosed multi-line comment" << endl;
        }
        else {
            tok_iter=re; 
        }
    }

    if(temp=="."){
        tok_iter++;
        if(Alldigit(*tok_iter)&&Alldigit(ans.back())){
            temp=ans.back()+temp+*tok_iter;
            ans.pop_back();
        }
        else if(*tok_iter=="."){
            temp+=*tok_iter;
            re=tok_iter;
            tok_iter++;
            if(*tok_iter==".")
                temp+=*tok_iter;
            else tok_iter=re;
        }
        else if(*tok_iter=="*")
            temp+=*tok_iter;
        else tok_iter=re;
    }
    if(temp[0]=='/' and temp[1]=='/')
        origin_comm+=temp+" ";
    else if(temp[0]=='/' and temp[1]=='*')
        origin_comm+=temp+" ";
    else ans.push_back(temp);

    if(tok_iter==tokens.end()) break;
  }
  return 1;
}catch(exception &e){
  cout<<"error"<<e.what()<<endl;
  return 0;
}
}

const char** return_code(){
  cSize=ans.size();
  for(int i=0;i<ans.size();i++){
    if(ans[i]==" " or ans[i]=="\n" or ans[i]=="\t" or ans[i]=="\r")
        cSize--;
  }
  const char** arr = new const char*[cSize];
  for(int i=0,j=0;i<ans.size();i++){
    origin_code+=ans[i];
    if(ans[i]==" " or ans[i]=="\n" or ans[i]=="\t" or ans[i]=="\r")
	continue;
    arr[j]=ans[i].c_str();
    j++;
  }
  //cout<<origin_code<<endl;
  return arr;
}
int code_size(){
  return cSize;
}
const char** return_comm(){
  boost::char_separator<char> sep(" \n");
  boost::tokenizer<boost::char_separator<char>>  token(origin_comm,sep);
  boost::tokenizer<boost::char_separator<char>>::iterator it;
  for(it=token.begin();it!=token.end();++it){
    comm_token.push_back(*it);
  }
  const char** arr= new const char*[comm_token.size()];
  for(int i=0;i<comm_token.size();i++){
    //origin_comm+=comm_token[i];
    arr[i]=comm_token[i].c_str();
  }
  return arr;
}
int comm_size(){
  return comm_token.size();
}
char* code(){
  char* s=new char[origin_code.length()+1];
  strcpy(s,origin_code.c_str());
  return s;
}
char* comm(){
  char* s=new char[origin_comm.length()+1];
  strcpy(s,origin_comm.c_str());
  return s;
}
//}
}
int main(int argc,char** argv)
{
  origin_code="";
  origin_comm="";
  for(int i=1;i<argc;i++){
    bool a=token(argv[i]);
    if(a==0) return 1;
  }
}
