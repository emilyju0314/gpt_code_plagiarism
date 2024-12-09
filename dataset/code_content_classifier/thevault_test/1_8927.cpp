void bin(unsigned num){
    if(num > 1){
        bin(num / 2);
    }
    cout<< num % 2;
}