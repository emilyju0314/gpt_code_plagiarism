#include<stack>
#include<cstdio>
#include<cstdlib>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int f[128];

struct card{
	char rank,suit;
	int strength()const{ return 4*f[rank]+f[suit]; }
	bool neighbor(const card &c)const{
		if(rank=='A'){
			return c.rank=='2' || c.rank=='K';
		}
		else if(c.rank=='A'){
			return rank=='2' || rank=='K';
		}
		else{
			return abs(f[rank]-f[c.rank])==1;
		}
	}
};

card parse(const char *s){ return (card){s[1],s[0]}; }

struct action{
	int type,i; // 0: deck からカードを引く, 1: 右の table にカード i を置く, 2: 左の table にカード i を置く, 3: 位置 i にカードを戻す
	int t; // この動作を終える時刻
};

bool gameover(const stack<card> &S1,const stack<card> &S2,const bool *b1,const bool *b2,const card &last1,const card &last2){
	bool end1=S1.empty(),end2=S2.empty();
	rep(i,4){
		if(b1[i]) end1=false;
		if(b2[i]) end2=false;
	}

	if(end1 && end2){
		puts(last1.strength()>last2.strength()?"A wins.":"B wins.");
		return true;
	}
	if(end1){
		puts("A wins.");
		return true;
	}
	if(end2){
		puts("B wins.");
		return true;
	}
	return false;
}

void cold_move(stack<card> &S,bool *b,card *tab,card &R){
	if(!S.empty()) R=S.top(), S.pop();
	else{ // rightmost card
		rep(i,4) if(b[i]) { R=tab[i]; b[i]=false; break; }
	}
}

bool get_next_action(int t,const stack<card> &S,const bool *b,const card *tab,const card &R,const card &L,action &res){
	// type 0
	if(!S.empty()){
		rep(i,4) if(!b[i]) { res.type=0; res.t=t+3; return true; }
	}
	// type 1
	int i0=-1;
	rep(i,4) if(b[i] && R.neighbor(tab[i])) if(i0==-1 || tab[i].strength()<tab[i0].strength()) i0=i;
	if(i0!=-1){ res.type=1; res.t=t+5; res.i=i0; return true; }
	// type 2
	i0=-1;
	rep(i,4) if(b[i] && L.neighbor(tab[i])) if(i0==-1 || tab[i].strength()<tab[i0].strength()) i0=i;
	if(i0!=-1){ res.type=2; res.t=t+7; res.i=i0; return true; }
	// type 3 or wait
	return false;
}

void do_action(const action &a,int &t,stack<card> &S,bool *b,card *tab,card &R,card &L){
	t=a.t;
	if(a.type==0){
		b[a.i]=true;
		tab[a.i]=S.top();
		S.pop();
	}
	else if(a.type==1){
		R=tab[a.i];
		b[a.i]=false;
	}
	else if(a.type==2){
		L=tab[a.i];
		b[a.i]=false;
	}
}

int main(){
	const int list[]={77,2,3,4,5,6,7,8,9,10,11,12,13,3,2,1,0};
	rep(i,17) f["A23456789XJQKSHDC"[i]]=list[i];

	while(1){
		stack<card> S1,S2; // deck
		card L,R; // table の一番上のカード
		bool b1[4]={},b2[4]={}; // tableau の i 番目にカードがあるかどうか
		card tab1[4],tab2[4]; // tableau ( 手札 )

		// input
		char tmp[52][3];
		int n1; scanf("%d",&n1);
		rep(i,n1) scanf("%s",tmp[i]);
		for(int i=n1-1;i>=0;i--) S1.push(parse(tmp[i]));
		int n2; scanf("%d",&n2);
		rep(i,n2) scanf("%s",tmp[i]);
		for(int i=n2-1;i>=0;i--) S2.push(parse(tmp[i]));
		if(n1==0) break;

		// draw 4 cards
		rep(i,4){
			if(!S1.empty()){ card c=S1.top(); S1.pop(); b1[i]=true; tab1[i]=c; }
			if(!S2.empty()){ card c=S2.top(); S2.pop(); b2[i]=true; tab2[i]=c; }
		}

		// gao
		while(1){
			// cold
			cold_move(S1,b1,tab1,R);
			cold_move(S2,b2,tab2,L);
			if(gameover(S1,S2,b1,b2,R,L)) goto END;

			// jakajaka
			int t=0;
			action a1,a2;
			bool ok1=get_next_action(t,S1,b1,tab1,R,L,a1);
			bool ok2=get_next_action(t,S2,b2,tab2,L,R,a2);
			card last1,last2; // 最後に置いたカード
			while(ok1 || ok2){
				if(ok1 && (a1.type==1 || a1.type==2)) last1=tab1[a1.i];
				if(ok2 && (a2.type==1 || a2.type==2)) last2=tab2[a2.i];

				if(ok1 && ok2){
					if(a1.t<a2.t){
						do_action(a1,t,S1,b1,tab1,R,L);
						if(a1.type==1 && a2.type==2 || a1.type==2 && a2.type==1) a2.type=3, a2.t=t+5;
						ok1=get_next_action(t,S1,b1,tab1,R,L,a1);
					}
					else if(a2.t<a1.t){
						do_action(a2,t,S2,b2,tab2,L,R);
						if(a1.type==1 && a2.type==2 || a1.type==2 && a2.type==1) a1.type=3, a1.t=t+5;
						ok2=get_next_action(t,S2,b2,tab2,L,R,a2);
					}
					else{ // a1.t==a2.t
						if(a1.type==1 && a2.type==2){
							do_action(a2,t,S2,b2,tab2,L,R);
							a1.type=3;
							a1.t=t+5;
							ok2=get_next_action(t,S2,b2,tab2,L,R,a2);
						}
						else if(a1.type==2 && a2.type==1){
							do_action(a1,t,S1,b1,tab1,R,L);
							a2.type=3;
							a2.t=t+5;
							ok1=get_next_action(t,S1,b1,tab1,R,L,a1);
						}
						else{
							do_action(a1,t,S1,b1,tab1,R,L);
							do_action(a2,t,S2,b2,tab2,L,R);
							ok1=get_next_action(t,S1,b1,tab1,R,L,a1);
							ok2=get_next_action(t,S2,b2,tab2,L,R,a2);
						}
					}
				}
				else if(ok1){
					do_action(a1,t,S1,b1,tab1,R,L);
					ok1=get_next_action(t,S1,b1,tab1,R,L,a1);
					ok2=get_next_action(t,S2,b2,tab2,L,R,a2);
				}
				else if(ok2){
					do_action(a2,t,S2,b2,tab2,L,R);
					ok1=get_next_action(t,S1,b1,tab1,R,L,a1);
					ok2=get_next_action(t,S2,b2,tab2,L,R,a2);
				}
				if(gameover(S1,S2,b1,b2,last1,last2)) goto END;
			}
		}

		END:;
	}

	return 0;
}