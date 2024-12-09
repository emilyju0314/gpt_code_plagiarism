#include<bits/stdc++.h>
using namespace std;

const int INF=1001001001;

int W,H,F,M,O;
int fld[15][15];

struct data{
    int y,x,s,o,f;
    data(int y,int x,int s,int o,int f)
        :y(y),x(x),s(s),o(o),f(f){}

    bool operator<(const data &d)const{
        return f>d.f;
    }
};

int dist[15][15][1<<10][50];

void solve(){
    fill_n(***dist,15*15*(1<<10)*50,INF);
    priority_queue<data>que;
    for(int i=0;i<W;i++){
        dist[0][i][1<<i][O]=0;
        que.push(data(0,i,1<<i,O,0));
    }

    while(que.size()){
        data d=que.top();que.pop();
        if(dist[d.y][d.x][d.s][d.o]<d.f)continue;
        if(d.o==0)continue;
        for(int i=-1;i<=1;i+=2){
            int ny=d.y,nx=d.x+i;
            if(nx<0||nx>=W)continue;
            int ns,no,nf;
            if(d.s>>nx&1){
                ns=d.s;no=d.o-1;nf=d.f;
            }
            else{
                ns=d.s|(1<<nx);
                no=min(M,d.o-1+(fld[ny][nx]>=0?fld[ny][nx]:0));
                nf=d.f+(fld[ny][nx]>=0?0:-fld[ny][nx]);
            }
            if(no<0)continue;
            if(dist[ny][nx][ns][no]<=nf)continue;
            dist[ny][nx][ns][no]=nf;
            que.push(data(ny,nx,ns,no,nf));
        }

        int ny=d.y+1,nx=d.x;
        if(ny>H)continue;
        int ns,no,nf;
        ns=1<<nx;
        no=min(M,d.o-1+(fld[ny][nx]>=0?fld[ny][nx]:0));
        nf=d.f+(fld[ny][nx]>=0?0:-fld[ny][nx]);
        if(no<0)continue;
        if(dist[ny][nx][ns][no]<=nf)continue;
        dist[ny][nx][ns][no]=nf;
        que.push(data(ny,nx,ns,no,nf));
    }

    int mi=INF;
    for(int j=0;j<W;j++){
        for(int o=0;o<=M;o++){
            mi=min(mi,dist[H][j][1<<j][o]);
        }
    }

    if(mi>F)cout<<"NA"<<endl;
    else cout<<mi<<endl;
}

int main(){
    while(cin>>W>>H,W||H){
        cin>>F>>M>>O;M--;O--;
        for(int i=1;i<=H;i++){
            for(int j=0;j<W;j++){
                cin>>fld[i][j];
            }
        }
        solve();
    }
    return 0;
}