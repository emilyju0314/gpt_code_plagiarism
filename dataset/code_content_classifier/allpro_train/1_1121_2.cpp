#include<iostream>
#include<cassert>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

#define N 0
#define E 1
#define S 2
#define W 3

int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int curdir[]={S,W,N,E};

int sd[2][4]={//S default:0 -
  -1,W,-1,E,
  S,-1,N,-1,
};

int cd[4][4]={//C default:0 -^
  W,-1,-1,N,
  E,N,-1,-1,
  -1,S,E,-1,
  -1,-1,W,S,
};

int ld[4][2][4]={//if switch == 0 ld[i][0], switch == 1 ld[i][1] 
  //ST        //CURVE
  W,W,-1,E, W,W,-1,N,
  S,N,N,-1, E,N,N,-1,
  -1,W,E,E, -1,S,E,E,
  S,-1,N,S, S,-1,W,S
  /*
  {W,W,-1,E},{W,W,-1,N},
  {S,N,N,-1},{E,N,N,-1},
  {-1,W,E,E},{-1,S,E,E},
  {S,-1,N,S},{S,-1,W,S}
  */
};


int rd[4][2][4]={//if switch == 0 ld[i][0], switch == 1 ld[i][1] 
  //ST        //CURVE
  -1,W,W,E, -1,W,W,S,
  S,-1,N,N, W,-1,N,N,
  E,W,-1,E, E,N,-1,E,
  S,S,N,-1, S,S,E,-1
  /*
  {-1,W,W,E},{-1,W,W,S},
  {S,-1,N,N},{W,-1,N,N},
  {E,W,-1,E},{E,N,-1,E},
  {S,S,N,-1},{S,S,E,-1}
  */
};

int switchid[6][6];
int rot[6][6];
char m[6][6];

int    cost[6][6][4][(1<<6)];
int visited[6][6][4][(1<<6)];
int ans;

void dfs(int r,int c,int y,int x,int d,int state,int visnow,int length){
  if (length != 0)d=curdir[d];

  if (x == -1||y == -1||x==c||y==r)return;

  if (visited[y][x][d][state] == -1){
    
  }else if (visited[y][x][d][state] == visnow){
    ans=max(ans,length-cost[y][x][d][state]);
    return;
  }else {
    return;
  }
  visited[y][x][d][state]=visnow;
  cost[y][x][d][state]   =length;

  int nextd;
  int curgrid=rot[y][x];
  if (m[y][x] == 'S'){
    nextd=sd[curgrid][d];
    dfs(r,c,y+dy[nextd],x+dx[nextd],nextd,state,visnow,length+1);
  }else if( m[y][x] == 'C'){
    nextd=cd[curgrid][d];
    dfs(r,c,y+dy[nextd],x+dx[nextd],nextd,state,visnow,length+1);
  }else if (m[y][x] == 'L'){
    bool isswitch=(((1<<switchid[y][x])&state)!=0);
    nextd=ld[curgrid][isswitch][d];
    if ((rot[y][x]+3)%4 == d){
      if (isswitch)state-=(1<<switchid[y][x]);
      else         state+=(1<<switchid[y][x]);
    }
    dfs(r,c,y+dy[nextd],x+dx[nextd],nextd,state,visnow,length+1);
  }else if (m[y][x] == 'R'){
    bool isswitch=(((1<<switchid[y][x])&state)!=0);
    nextd=rd[curgrid][isswitch][d];
    if ((rot[y][x]+3)%4==d){
      if (isswitch)state-=(1<<switchid[y][x]);
      else         state+=(1<<switchid[y][x]);
    }
    dfs(r,c,y+dy[nextd],x+dx[nextd],nextd,state,visnow,length+1);
  }
}

void solve(int r,int c,int index){
  rep(i,r){
    rep(j,c){
      rep(k,4){
	rep(l,(1<<index)){
	  visited[i][j][k][l]=-1;
	}
      }
    }
  }
  
  int visnow=0;
  rep(i,r){
    rep(j,c){
      if (m[i][j] == 'R'||m[i][j] == 'L'){
	if (rot[i][j] == 0){
	  dfs(r,c,i,j,W,0,visnow,0);
	}else if (rot[i][j] == 1){
	  dfs(r,c,i,j,N,0,visnow,0);
	}else if (rot[i][j] == 2){
	  dfs(r,c,i,j,E,0,visnow,0);
	}else if (rot[i][j] == 3){
	  dfs(r,c,i,j,S,0,visnow,0);
	}
	/*
	rep(ii,r){
	  rep(jj,c){
	    rep(kk,4){
	      rep(ll,(1<<index)){
		visited[ii][jj][kk][ll]=-1;
	      }
	    }
	  }
	}

	if (rot[i][j] == 0){
	  dfs(r,c,i,j,W,1<<switchid[i][j],visnow,0);
	}else if (rot[i][j] == 1){
	  dfs(r,c,i,j,N,1<<switchid[i][j],visnow,0);
	}else if (rot[i][j] == 2){
	  dfs(r,c,i,j,E,1<<switchid[i][j],visnow,0);
	}else if (rot[i][j] == 3){
	  dfs(r,c,i,j,S,1<<switchid[i][j],visnow,0);
	}
	rep(ii,r){
	  rep(jj,c){
	    rep(kk,4){
	      rep(ll,(1<<index)){
		visited[ii][jj][kk][ll]=-1;
	      }
	    }
	  }
	}
	*/
	visnow++;
      }
    }
  }
}


//if rot[i][j] == -1 unvisited
void search(int r,int c,int index,int now,int num,//num -> 3 position of L or R
	    int y,int x,int d,int *posx,int *posy,bool tonext){

  if (tonext && num == 0 && index == now+1){
    solve(r,c,index);
    return;
  }


  if (tonext){
    
    if (num == 0){//straight
      now++;
      y = posy[now];
      x = posx[now];

      d = (rot[y][x]+3)%4;
      search(r,c,index,now,1,posy[now]+dy[d],posx[now]+dx[d],
	     d,posx,posy,false);
    }else if (num == 1){
      y = posy[now];
      x = posx[now];
      d=(rot[y][x]+1)%4;
      search(r,c,index,now,2,posy[now]+dy[d],posx[now]+dx[d],
	     d,posx,posy,false);
    }else if (num == 2){//curve
      y = posy[now];
      x = posx[now];
      if (m[y][x] == 'R'){
	d=(rot[y][x]+2)%4;
      }else if (m[posy[now]][posx[now]]=='L'){
	d=rot[y][x];
      }
      search(r,c,index,now,0,posy[now]+dy[d],posx[now]+dx[d],
	     d,posx,posy,false);
      
    }
    return;
  }

  if (x == -1 || y == -1||x==c||y==r)return;
  d=curdir[d];

  if (m[y][x] == 'S'){
    if (rot[y][x] == -1){
      if      (d == E || d == W)rot[y][x]=0;
      else if (d == S || d == N)rot[y][x]=1;
      search(r,c,index,now,num,y+dy[sd[rot[y][x]][d]],x+dx[sd[rot[y][x]][d]],
	     sd[rot[y][x]][d],posx,posy,false);
      rot[y][x]=-1;
      return;
    }else if (rot[y][x] != -1){
      if (sd[rot[y][x]][d] == -1)return;
      else search(r,c,index,now,num,-1,-1,-1,posx,posy,true);
    }
  }else if(m[y][x] == 'C'){
    if (rot[y][x] == -1){
      if      (d == E)rot[y][x]=1;
      else if (d == W)rot[y][x]=3;
      else if (d == S)rot[y][x]=2;
      else if (d == N)rot[y][x]=0;
      search(r,c,index,now,num,y+dy[cd[rot[y][x]][d]],x+dx[cd[rot[y][x]][d]],
	     cd[rot[y][x]][d],posx,posy,false);
      if      (d == E)rot[y][x]=2;
      else if (d == W)rot[y][x]=0;
      else if (d == S)rot[y][x]=3;
      else if (d == N)rot[y][x]=1;
      search(r,c,index,now,num,y+dy[cd[rot[y][x]][d]],x+dx[cd[rot[y][x]][d]],
	     cd[rot[y][x]][d],posx,posy,false);
      rot[y][x]=-1;
    }else if (rot[y][x] != -1){
      if (cd[rot[y][x]][d] == -1)return;
      else search(r,c,index,now,num,-1,-1,-1,posx,posy,true);
    }
  }else if (m[y][x] == 'L'){
    if (ld[rot[y][x]][0][d] == -1)return;
    search(r,c,index,now,num,-1,-1,-1,posx,posy,true);
  }else if (m[y][x] == 'R'){
    if (rd[rot[y][x]][0][d] == -1)return;
    search(r,c,index,now,num,-1,-1,-1,posx,posy,true);
  }
}


void decide(int r,int c,int index,int now,int *posx,int *posy){
  if (now == index){
    search(r,c,index,-1,0,-1,-1,-1,posx,posy,true);
    return;
  }
  rep(i,4){
    rot[posy[now]][posx[now]]=i;
    decide(r,c,index,now+1,posx,posy);
  }
}

int main(){
  int r,c;
  while(cin>>c>>r && c){
    int index =0;
    int posx[6],posy[6];
    rep(i,r){
      rep(j,c){
	cin>>m[i][j];
	rot[i][j]=-1;
	if (m[i][j] == 'R'||m[i][j]=='L'){
	  switchid[i][j]=index;
	  posy[index]=i;
	  posx[index]=j;
	  index++;
	}
      }
    }

    ans = 0;
    decide(r,c,index,0,posx,posy);
    cout << ans << endl;
  }

}