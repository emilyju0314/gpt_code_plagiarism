#include<stdio.h>

// input(a,b) 
// output(x,y) ax+by=gcd(a,b)
template <typename T>
void extendedEuclidAlgo(T a,T b,T& x,T &y) {
    T a0,a1,a2;
    T b0,b1,b2;
    T q1;
    T r0,r1,r2;

    a0 = 1;
    b0 = 0;
    a1 = 0;
    b1 = 1;

    r0 = a;
    r1 = b;

    while(r1 != 0) {
        r2 = r0 % r1;
        q1 = r0 / r1;
        a2 = a0 - q1 * a1;
        b2 = b0 - q1 * b1;

        r0 = r1;
        r1 = r2;

        a0 = a1;
        a1 = a2;
        b0 = b1;
        b1 = b2;
    }

    x = a0;
    y = b0;


}


int main() {
    int a,b;
    int x,y;

    scanf("%d %d",&a,&b);
    extendedEuclidAlgo(a,b,x,y);
    printf("%d %d\n",x,y);


    return 0;

}