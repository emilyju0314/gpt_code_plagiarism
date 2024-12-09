#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,k;
struct Num{
    char arr[20];
    char cnt;
    Num(int x){
        for(int i=0;i<20;i++)
            arr[i]=0;
        cnt=0;
        while(x>0){
            arr[cnt]=x%k;
            cnt++;
            x/=k;
        }
    }
    Num(const Num& t){
        for(int i=0;i<20;i++)
            arr[i]=0;
        cnt=t.cnt;
        for(int i=0;i<t.cnt;i++)
            arr[i]=t.arr[i];
    }
    Num Xor(const Num &t){
        Num ans(0);
        ans.cnt = max(cnt,t.cnt);
        for(int i=0;i<ans.cnt;i++){
            ans.arr[i]=(arr[i]+t.arr[i])%k;
        }
        return ans;
    }
    Num dec(const Num &t){
        Num ans(0);
        ans.cnt = max(cnt,t.cnt);
        for(int i=0;i<ans.cnt;i++){
            ans.arr[i]=(arr[i]-t.arr[i]+k)%k;;
        }
        return ans;
    }
    int out(void){
        int ans=0;
        int base=1;
        for(int i=0;i<cnt;i++){
            ans+=base*arr[i];
            base=base*k;
        }
        return ans;
    }
};
void work(){
    scanf("%d %d",&n,&k);
    //int last=0;
    int f=0;//0 a-b 1 b-a
    Num last(0);
    for(int i=0;i<n;i++){
        Num now(i);
        Num ans(0);
        if(!f)
            ans=now.dec(last);
        else
            ans=last.dec(now);
        f^=1;
        printf("%d\n",(ans).out());
        fflush(stdout);
        last=now;
        int r;
        scanf("%d",&r);
        if(r==1){
            return;
        }
        else if(r==0){
            continue;
        }
        else{
            return;
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}