int summingFactors(int i) {
    
    int Sum=0;
    
    for (int Factor=1; Factor < i; Factor++) {
        if (i%Factor == 0) {
            Sum += Factor;
        }
    }
    
    return Sum;
    
}