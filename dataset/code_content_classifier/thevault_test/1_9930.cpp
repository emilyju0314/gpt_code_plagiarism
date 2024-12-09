inline uint512_divison_result
UInt512Division(uint512 A, uint512 B)
{
    assert(B != 0);
    if (A < B) { 
        uint512_divison_result Result = { 0, A };
        return Result;
    }

    uint512 C = B;
    while (A - C >= C) C = C + C; // Largest doubling of B
    uint512 N = 1;
    A = A - C;

    while (C != B)
    {
        C = C >> 1; // Half(C);
		N = N + N;
        if (C <= A) { A = A - C; N = N + 1; }
    }

    uint512_divison_result Result = { N, A };
    return Result;
}