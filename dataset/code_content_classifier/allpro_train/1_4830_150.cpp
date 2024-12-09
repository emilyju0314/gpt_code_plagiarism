#include <bits/stdc++.h>
int main(){
	char a[4],b[4];
	scanf("%s %s", a,b);
	printf("%s\n", a[0] == b[2] && a[2] == b[0] &&  a[1] == b[1]? "YES":"NO");
}
