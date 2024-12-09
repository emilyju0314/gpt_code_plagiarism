inline int128_t int128_t::MultiplyDouble(int128_t *A,const int128_t &B)
{
    int128 ret;
    int64  tmp=0;
    int64  col3=0;

    // a 128 bit multiply works like when you were in grade school except that instead of the max value per column being
    // a 9 the max value is 2^64. 

    //   ab
    //*  cd
    //------
    //   bd
    //  ad
    //  bc
    //+ac
    //-------
    // wxyz
    int64 a=A->Hi;
    int64 b=A->Lo;
    int64 c=B.Hi;
    int64 d=B.Lo;
    int64 w=0;
    int64 x=0;
    int64 y=0;
    int64 z=0;
    int   carry=0;
    int   carry2=0;
    int64 xp=0;
    
    y=Multiply64(&b,&d);
    z=b; b=A->Lo;
    x=Multiply64(&a,&d);
    carry=Add64(&y,&a,0);// y+=a; 
    a=A->Hi;
    xp=Multiply64(&b,&c); 
    carry=Add64(&x,&xp,carry); //x+=xp+carry;
    carry2=Add64(&y,&b,0);   //y+=b; 
    w=Multiply64(&a,&c); 
    carry2=Add64(&x,&a,carry2);//x+=a; 
    // final w fixup
    int64 longcarry=carry2;
    Add64(&w,&longcarry,carry2);


    A->Lo=z;
    A->Hi=y;
    ret.Lo=x;
    ret.Hi=w;

    return ret;
}