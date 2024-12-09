void division(int dividend[], int divisor[], int quotient[], int remainder[],
              int dividendSize, int divisorSize, int & quotientSize, int & remainderSize) {
    
    //If Dividend == 0
    if (isZero(dividend, dividendSize)) {
        quotientSize = 1;
        remainderSize = 1;
        quotient[0] = 0;
        remainder[0] = 0;
        return;
    }
    
    //Set Default Remainder to Divisor
    remainderSize = dividendSize;
    for (int i = 0; i < dividendSize; i++) {
        remainder[i] = dividend[i];
    }
    
    //If Dividend < Divisor
    if (less(dividend, divisor, dividendSize, divisorSize)) {
        quotientSize = 1;
        quotient[0] = 0;
    } else {
        
        //Calculate Divisor Shift Unit
        int n = dividendSize - divisorSize;
        
        //Create Buffer
        int bufferSize = dividendSize;
        int * buffer = new int[bufferSize - 1];
        for (int i = 0; i < n; i++) {
            buffer[i] = 0;
        }
        for (int i = n; i < bufferSize; i++) {
            buffer[i] = divisor[i - n];
        }
        
        //Setting Default Quotient Size
        quotientSize = dividendSize - divisorSize;
        
        //If Dividend < Buffer
        if (less(dividend, buffer, dividendSize, bufferSize)) {
            
            //Shift Buffer if Buffer is Too Big
            divideBy10(buffer, bufferSize);
            
        } else {
            
            //Calculate New Quotient Size
            quotientSize++;
            
        }
        
        //Set Quotient to Zero
        for (int i = 0; i < quotientSize; i++) {
            quotient[i] = 0;
        }
        
        //Calculate Remainder One Unit at One Time
        for (int k = quotientSize - 1; k >= 0; k--) {
            
            //While Buffer <= Remainder
            while (less(buffer, remainder, bufferSize, remainderSize) || equal(buffer, remainder, bufferSize, remainderSize)) {
                
                //Calculate Unit Remainder
                for (int i = bufferSize - 1; i >= 0; i--) {
                    remainder[i] = remainder[i] - buffer[i];
                }
                for (int i = 0; i < remainderSize - 1; i++) {
                    if (remainder[i] < 0) {
                        remainder[i] += 10;
                        remainder[i + 1]--;
                    }
                }
                
                //Calculate New Remainder Size
                while (remainder[remainderSize - 1] == 0) {
                    remainderSize--;
                }
                
                //Calculate Unit Quotient
                quotient[k]++;
                
                //If Remainder == 0
                if (isZero(remainder, remainderSize)) {
                    return;
                }
                
            }
            
            //Shift Buffer for Next Calculation
            divideBy10(buffer, bufferSize);
            
        }
    }
    
}