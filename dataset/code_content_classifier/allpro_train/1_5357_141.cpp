#include<cstdio>
#include<algorithm>
#define rep(i,a) for(int i=0;i<(a);++i)

int a[6];

int main()
{
  rep( i, 6 )
    scanf( "%d", a+i );

  std::sort( a, a+4 );
  
  printf( "%d\n", a[1]+a[2]+a[3]+std::max( a[4], a[5] ) );
  
  return 0;
}