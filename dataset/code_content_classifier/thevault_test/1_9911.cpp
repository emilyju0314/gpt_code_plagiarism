void Test64BitBase(void)
{
    int64 a,b,c;
    int carry;
    int64 overflow;

    // 64 bit add...
    a=0x10;
    b=0x2;
    carry=0;
    for (int x=0;x<100;x++)
    {
        b=a;
        printf("Carry=%X, a=%llX b=%llX\n",carry,a,b);
        carry=Add64(&a,&b,carry);
    }

    // 64 bit sub...
    a=0x10000;
    b=0x2;
    carry=0;
    for (int x=0;x<20;x++)
    {
        b*=2;
        printf("Borrow=%X, a=%llX b=%llX\n",carry,a,b);
        carry=Sub64(&a,&b,carry);
    }

    // 64 bit multiply
    a=0x10;
    b=0x1234;
    overflow=0;
    for (int x=0;x<10;x++)
    {
        printf("overflow=%llX, a=%llX b=%llX\n",overflow,a,b);
        overflow=Multiply64(&a,&b);
    }


    // 64 bit divide
	// Pick these constants carefully
	// if the result cannot fit into a 64-bit 
	// register then this will sigfpe (or throw)
	a=0x10000;
    b=0x1; //b=0x10 will sigfpe
    c=0x03;
    overflow=0;
    for (int x=0;x<20;x++)
    {
        printf("remainder=%llX, a=%llX b=%llX c=%llX\n",overflow,a,b,c);
        overflow=Divide64(&a,&b,&c);
    }
}