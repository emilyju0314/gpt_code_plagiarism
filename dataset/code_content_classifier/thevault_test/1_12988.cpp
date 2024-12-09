int PROCESSOR::hashfull() {
    int count = 0;
    PHASH addr = processors[0]->hash_tab[0];
    for(int i = 0; i < 1000; i++) {
        if(addr[i].check_sum != 0 && 
            (addr[i].flags >> 4) == PROCESSOR::age)
            count++;
    }
    return count;
}