float32 BigEndian2float16corrected(const char* Liste)
{
    //sign          1 bit
    //exponent      5 bit
    //significand  10 bit

    //Retrieving data
    int16u Integer=BigEndian2int16u(Liste);

    //Retrieving elements
    bool   Sign    =(Integer&0x8000)?true:false;
    int32u Exponent=(Integer>>10)&0xFF;
    int32u Mantissa= Integer&0x03FF;

    //Some computing
    if (Exponent==0 || Exponent==0xFF)
        return 0; //These are denormalised numbers, NANs, and other horrible things
    Exponent-=0x0F; //Bias
    float64 Answer=(((float64)Mantissa)/8388608+1.0)*std::pow((float64)2, (int)Exponent); //(1+Mantissa) * 2^Exponent
    if (Sign)
        Answer=-Answer;

    return (float32)Answer;
}