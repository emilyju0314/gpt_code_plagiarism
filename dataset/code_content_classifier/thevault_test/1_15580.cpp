int HashTable::hashing(string s)
{
    ////HASHING FUNCTION - ADDITION
    //unsigned int hashVal = 0;
    //
    //for (int i = 0; s[i]; ++i)
    //    hashVal += int(s[i]);
    //
    //return hashVal % capacity;


    
    ////HASHING FUNCTION - POLYNOMIAL
    //const int HASH_PRIME = 37;
    //int hashVal = 0;
    //
    //for (int i = 0; s[i]; ++i)
    //    hashVal = (hashVal * HASH_PRIME + int(s[i])) % capacity;
    //
    //return hashVal;



    //HASHING FUNCTION - XOR BIT SHIFT
    unsigned int hashVal = 0;
    
    for (int i = 0; s[i]; ++i)
    {
        unsigned int temp = (hashVal << 5) ^ int(s[i]);
        hashVal = temp ^ hashVal;
    }
    
    return hashVal % capacity;



    /***********************************************************************************************
    Why I Chose What I Chose
    ------------------------
    I used 3 hashing algorithms (as seen above) for the extra credit on this assignment.  I tested
    out a simple addition type, a polynomial type, and an XOR bit shift type.  The numbers I
    report are the total number of collisions for the entire vector, and the maximum number of
    collisions in any given element of the vector.  For a small list (the stopWords file) the
    numbers broke down as follows:
    
          In all instances, there were 319 objects put into 200 elements.
    
                          Total Collisions        Max Collisions
          Addition              182                     6
          Polynomial            157                     5
          XOR Bit Shift         150                     5
    
    For a VERY large list (a list of 319378 words) the numbers broke down as follows:
    
          In all instances, there were 195318 objects put into 200 elements.
    
                          Total Collisions        Max Collisions
          Addition             195118                  1485
          Polynomial           195118                  1081
          XOR Bit Shift        195118                  1066
    
    The difference between the polynomial hashing algorithm and the XOR bit shift algorithm was
    not that substantial, even in the large test set, but the XOR bit shift WAS slightly more
    effective than the polynomial, which is why I chose to use it.
    ***********************************************************************************************/

}