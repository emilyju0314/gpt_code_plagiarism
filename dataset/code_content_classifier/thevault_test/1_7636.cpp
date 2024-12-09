void add(int color){
    ff[f[color]]--;
    f[color]++;
    ff[f[color]]++;
    if(f[color] > big){
        big = f[color];
    }
}