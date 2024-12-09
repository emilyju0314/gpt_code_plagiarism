#include<stdio.h>
int main(void)
{
		int n,i,h[101],k,j,t[101],w[101],flg;
	while(1) {
	flg=0;
		scanf("%d",&n);
		if(n==0)  break;
		for(i=0;i<n+1;i++){
		 scanf("%d",&h[i]);
		 }
		for(i=0;i<n+1;i++){
			for(j=0;j<n;j++){
			if(j>=i){
				t[j]=h[j+1];
				}
			else{
				t[j]=h[j];
				}
			}	
		for(j=0;j<n-1;j++){
			w[j]=t[j+1]-t[j];
			}
		for(j=0;j<n-2;j++){
			if(w[j]!=w[j+1]){
			flg=0;	break;
			}
			if(w[j]==w[j+1]){
			flg=1;
			}
		}
	if(flg==1){
		k=h[i];
		i=110;
		}
	}	
	printf("%d\n",k);
}	
		return 0;
	}	