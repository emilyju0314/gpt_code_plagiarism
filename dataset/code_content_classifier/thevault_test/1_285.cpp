int mod_inverse(int a, int m){
    if ((a < 2)) return a;
    int res = (((1LL - (long long)m * mod_inverse(m % a, a)) / (a % m)) + m) % m;
    return res;
}