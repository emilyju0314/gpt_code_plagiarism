#include<iostream>
#include<cstdio>
int cnt,s[16][16],n;
void func(int y,int x){
	if(cnt==n*n+1)
	;
	else if(s[y][x]==0){
		s[y++][x++]=cnt++;
		if(y>n)
			y-=n;
		if(x>n)
			x-=n;
		func(y,x);
	}
	else {
		y++;x--;
		if(y>n)
			y-=n;
		if(x<1)
			x+=n;
		func(y,x);
	}
}
int main(){
	while(1){
		std::cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			s[i][j]=0;
		if(n==0)
			break;
		cnt=1;
		func(n/2+2,n/2+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
			std::printf("%4d",s[i][j]);
			std::cout<<std::endl;
		}
	}
	return 0;
}