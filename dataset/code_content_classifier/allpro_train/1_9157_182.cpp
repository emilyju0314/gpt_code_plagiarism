#include <cstdio>

const int LIMIT=500;

int main(){
  int K;
  scanf("%d",&K);
  if(K<=LIMIT){
    printf("%d\n",K);
    for(int i=0;i<K;i++){
      for(int j=0;j<K;j++){
	if(j) printf(" ");
	printf("%d",j+1);
      }
      printf("\n");
    }
  }else{
    printf("%d\n",LIMIT);
    for(int i=0;i<LIMIT;i++){
      for(int j=0;j<LIMIT;j++){
	if(j) printf(" ");
	int l=(i+j)%LIMIT;
	if((j&1)&&l<K-LIMIT){
	  printf("%d",l+LIMIT+1);
	}else{
	  printf("%d",l+1);
	}
      }
      printf("\n");
    }
  }
  return 0;
}
