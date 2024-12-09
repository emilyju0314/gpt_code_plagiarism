   #include <bits/stdc++.h>

//    #include <boost/multiprecision/cpp_int.hpp>
 #define int long long
 #define inf  1000000007
  #define  mp make_pair
  #define  pb push_back
 #define ppa pair<int,pair<int,int>>
   using namespace std;         
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};

	int a,b,c,d;

int yaru(int sx,int sy,int gx,int gy){
	
	int d1=abs(gx-sx)+abs(gy-sy);
	
	int d2=0;
	if(sx<a){
		if(sy<b)d2+=a-sx+b-sy-1;
		else if(sy<=d) d2+=a-sx-1;
		else d2+=a-sx+sy-d-1;
	}
	else if(sx<=c){
		if(sy<b)d2+=b-sy-1;
		else if(sy<=d) d2+=0;
		else d2+=sy-d-1;
	}
	else{
		if(sy<b)d2+=sx-c+b-sy-1;
		else if(sy<=d) d2+=sx-c-1;
		else d2+=sx-c+sy-d-1;
	}
	
	if(gx<=a){
		if(gy<=b)d2+=a-gx+b-gy;
		else if(gy<=d) d2+=a-gx;
		else d2+=a-gx+gy-d;
	}
	else if(gx<=c){
		if(gy<=b)d2+=b-gy;
		else if(gy<=d) d2+=0;
		else d2+=gy-d;
	}
	else{
		if(gy<=b)d2+=gx-c+b-gy;
		else if(gy<=d) d2+=gx-c;
		else d2+=gx-c+gy-d;
	}
	return min(d1,d2);
}


int solve(){
	int n;
	cin>>n;
	if(n==0) exit(0);
	cin>>a>>b>>c>>d;
	int sx,sy;
	cin>>sx>>sy;
	int gx,gy;
	
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>gx>>gy;
		
		ans+=yaru(sx,sy,gx,gy);
		sx=gx;
		sy=gy;
	}
	
	return ans;
}



 signed main(){
 	
 
    	       cin.tie(0);
   			ios::sync_with_stdio(false);
	
 	
 	while(1){
 		cout<<solve()<<endl;
 	}
 	
 	return 0;
 
  }
 
