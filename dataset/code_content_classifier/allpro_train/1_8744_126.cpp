#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top, S[1000];

void push(int x){
	S[++top] = x;
}
int pop(){
	top--;
	return S[top+1];
}

int main(){
	int a,b;
	top = 0;
	char str[100];
	while( scanf("%s",str) != EOF) {
		if(str[0] == '+'){
			a = pop();
			b = pop();
			push(a+b);
		}else if(str[0] == '-'){
			b = pop();
			a = pop();
			push(a-b);
		}else if(str[0] == '*'){
			a = pop();
			b = pop();
			push(a*b);
		}else{
			push(atoi(str));
		}
	}
	printf("%d\n",pop());
	return 0;
}