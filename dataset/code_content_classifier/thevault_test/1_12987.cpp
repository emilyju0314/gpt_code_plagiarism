void PROCESSOR::reset_hash_tab(int id,size_t size) {
    if(id != 0)
        return;

    if(size) hash_tab_mask = size - 1;
    else size = size_t(hash_tab_mask) + 1;
    /*page size*/
#if defined(__ANDROID__) || defined(_WIN32)
    static const int alignment = 4096;
#else
    static const int alignment = 2 * 1024 * 1024;
#endif
    aligned_free<HASH>(hash_tab[white]);
    aligned_reserve<HASH,alignment,true>(hash_tab[white],2*size);
    hash_tab[black] = hash_tab[white] + size;
}