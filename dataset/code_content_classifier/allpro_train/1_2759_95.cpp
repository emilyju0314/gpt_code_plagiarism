#include <stdio.h>
int main(){
	int m,fand,year,n,ri,com;
	int max,tmp,in;
	double nen;
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&fand,&year,&n);
		max=0;
		while(n--){
			tmp=fand;
			in=0;
			scanf("%d%lf%d",&ri,&nen,&com);
			for(int i=0;i<year;i++){
				if(ri==1)	tmp+=(int)((double)tmp*nen);
				else		in+=(int)((double)tmp*nen);
				tmp-=com;
			}
			tmp+=in;
			//printf("tmp%d:%d\n",n,tmp);
			//printf("in%d:%d\n",n,in);
			if(max<tmp) max=tmp;
		}
		printf("%d\n",max);
	}
	return 0;
}