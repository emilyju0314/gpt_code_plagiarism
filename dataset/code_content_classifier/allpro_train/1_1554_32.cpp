#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int main(){

	int N,pre_left_or_right;
	bool isBroken;
	char left,right,pre;
	char* buf = new char[100001];

	scanf("%d",&N);

	for(int loop = 0; loop < N; loop++){
		scanf("%s",buf);

		pre_left_or_right = -1;
		isBroken = false;
		left = 0,right = 0;

		pre = buf[0];
		if(pre == 'L'){
			pre_left_or_right = 0;
		}else if(pre == 'R'){
			pre_left_or_right = 1;
		}

		for(int i = 1; buf[i] != '\0'; i++){
			if(pre == buf[i]){
				isBroken = true;
				break;
			}

			switch(buf[i]){
			case 'U':
				if(pre_left_or_right  == 0){
					right = 'U';
					pre_left_or_right = 1;
				}else if(pre_left_or_right == 1){
					left = 'U';
					pre_left_or_right = 0;
				}
				break;
			case 'D':
				if(pre_left_or_right  == 0){
					right = 'D';
					pre_left_or_right = 1;
				}else if(pre_left_or_right == 1){
					left = 'D';
					pre_left_or_right = 0;
				}
				break;
			case 'L':
				if(pre_left_or_right == -1){
					right = pre;
				}else{
					if(pre_left_or_right == 0){
						isBroken = true;
						break;
					}
				}
				left = buf[i];
				pre_left_or_right = 0;
				break;
			case 'R':
				if(pre_left_or_right == -1){
					left = pre;
				}else{
					if(pre_left_or_right == 1){
						isBroken = true;
						break;
					}
				}

				right = buf[i];
				pre_left_or_right = 1;
				break;
			}
			pre = buf[i];
		}

		if(!isBroken)printf("Yes\n");
		else{
			printf("No\n");
		}

	}


	return 0;
}