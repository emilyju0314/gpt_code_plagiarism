#include <cstdio>
#include <cstdlib>
using namespace std;

int ExGCD(int a, int b, int &x, int &y){
    int d=a;
    x=1; y=0;
    if(b!=0){ d=ExGCD(b, a%b, y, x); y-=a/b*x; }
    return d;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a,b;
        scanf("%d%d", &a, &b);
        int x,y,d;
        d = ExGCD(a, b, x, y);
        if(d <= 50000){
            printf("3\n0 0\n%d %d\n%d %d\n", a, b, abs(y), abs(x));
        }else{
            printf("4\n0 0\n%d %d\n%d %d\n%d %d\n", a-1, b, a/d, b/d, a, b-1);
        }
    }
    return 0;
}

