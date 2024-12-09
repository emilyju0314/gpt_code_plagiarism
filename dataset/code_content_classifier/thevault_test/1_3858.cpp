int Solution::isPalindrome(int A) {
    if(A<0)
        return 0;
    //We use long long because the reverse of the original
    //number can overflow
    int reverse = 0;
    int copy = A;
    while(copy!=0) {
        //Extract the least significant digit
        int dig = copy%10;
        //Append the extracted digit to the reverse
        //number we are constructing
        reverse = reverse*10 + dig;
        copy/=10;
    }
    if (reverse == A)
        return 1;
    else
        return 0;
}