void Grammar::walkGrammar(void (* callback)(Expansion *)) {
    for(shared_ptr<Rule> r : rules) {
        walkExpansion(r->getRuleExpansion().get(), callback);
    }
}