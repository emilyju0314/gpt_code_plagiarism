Trie() {
        for (long unsigned int i = 0; i < sizeof(next) / sizeof(Trie *); i++) {
            next[i] = NULL;
        }
        word_exists = false;
    }