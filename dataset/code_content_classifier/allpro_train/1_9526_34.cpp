#include <stdio.h>

int main(void) {
	char s[50];
	int i = 0,br = 0,m1 = 1;
	scanf("%s",s);
		while (br == 0){
			while (s[i] != 'A'){
				i = i + 1;
				if(i == 49){
					br = 1;
					break;
				}
			}
			if (br == 1){
				break;
			}
			while (s[i] != 'Z'){
				i = i + 1;
				if(i == 49){
					br = 1;
					break;
				}
			}
			if (br == 1){
				break;
			}
			m1 = 0;
			printf("AZ");
	}
	if (m1){
		printf("%d", -1);
	}
	printf ("\n");
	return 0;
}