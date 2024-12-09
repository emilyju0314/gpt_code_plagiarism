bool isPrime(Int n, int k) {
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    Int d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }
 
    for (int i = 0; i < k; i++) {
        if (miillerTest(d, n) == false) {
              return false;
        }
    }
 
    return true;
}