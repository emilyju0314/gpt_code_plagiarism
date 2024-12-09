#include <stdio.h>
#include <math.h>

#define SQ(X) \
  ( (X) * (X) )
#define LEN(AX,AY,BX,BY) \
  ( sqrt ( SQ( (BX) - (AX) ) + SQ( (BY) - (AY) ) ) )

/** Application main entry point. */
int main (
  int     argc,
  char  * argv[ ]
  )
{
  double ax, ay, bx, by, cx, cy;
  double res = 0.;

  scanf ( "%lf,%lf %lf,%lf", &ax, &ay, &bx, &by );

  while ( scanf ( " %lf,%lf", &cx, &cy ) == 2 )
  {
    double a = LEN( ax, ay, bx, by )
         , b = LEN( bx, by, cx, cy )
         , c = LEN( cx, cy, ax, ay );
    double z = ( a + b + c ) / 2.;
    
    res += sqrt ( z * ( z - a ) * ( z - b ) * ( z - c ) );
    bx = cx; by = cy;
  }

  printf ( "%.6f\n", res );

  return ( 0 );
}