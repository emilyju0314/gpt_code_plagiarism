int32_t gglMulDivi(int32_t a, int32_t b, int32_t c)
{
	int32_t result;
	int32_t sign = a^b^c;

	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (c < 0) c = -c;

    if (a < b) {
        swap(a, b);
    }
    
	if (b <= c) result = quick_muldiv(a, b, c);
	else        result = slow_muldiv((uint32_t)a, (uint32_t)b, (uint32_t)c);
	
	if (sign < 0)
		result = -result;
	  
    return result;
}