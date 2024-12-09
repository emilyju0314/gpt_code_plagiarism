#include<stdio.h>
#include<string.h>
typedef long long ll;
int len,fin;
char x[100020];
int main(){
    scanf(" %s",x);
    len=strlen(x);
    for(fin=1;fin<=len;fin++){
        int l=len-fin,r=fin-1;
        if(l>r) continue;
        if(x[len/2]!=x[l]||x[len/2]!=x[r]) break;
    }
    printf("%d\n",fin-1);
}
