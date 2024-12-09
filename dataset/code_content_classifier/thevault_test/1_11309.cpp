hopscotch_table(size_t len,
                    Hash hashfun = Hash(),
                    KeyEqual equalfun = KeyEqual()):
                                              data(next_powerof2(len) + 32),
                                              hashfun(hashfun),
                                              equalfun(equalfun),
                                              numel(0),
                                              mask(data.size() - 32 - 1) {
    }