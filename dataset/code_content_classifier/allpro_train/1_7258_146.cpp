#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

	int n,start,goal;

	scanf("%d",&n);

	for(int i=0; i < n; i++){
		scanf("%d %d",&start,&goal);

		if(start <= 5){
			if(start < goal){
				printf("%d",start);
				for(int k = start+1; k <= goal; k++){
					printf(" %d",k);
				}
				printf("\n");
			}else{
				printf("%d",start);
				for(int k = start-1; k >= goal; k--){
					printf(" %d",k);
				}
				printf("\n");
			}
		}else{ //start > 6
			if(goal >= 5){  //??´??????????????????
				if(start < goal){
					printf("%d",start);
					for(int k= start+1; k <= goal; k++)printf(" %d",k);

					printf("\n");

				}else{ //start > goal
					printf("%d",start);
					for(int k= start+1; k <= 9; k++)printf(" %d",k);
					if(goal != 5){
						printf(" 5 4 3 2 1 0 1 2 3 4");
					}
					for(int k=5; k <= goal; k++)printf(" %d",k);
					printf("\n");
				}

			}else{ //goal <= 4
				printf("%d",start);
				for(int k=start+1; k <= 9; k++)printf(" %d",k);
				for(int k=5; k >= goal; k--)printf(" %d",k);
				printf("\n");
			}

		}

	}

    return 0;
}

