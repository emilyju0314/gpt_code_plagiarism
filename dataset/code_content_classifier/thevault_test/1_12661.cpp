std::string Grammar::getMatchingPublicRule(std::string test) const {
    test = Grammar::trimString(test);
    test = Grammar::replaceAll(test, " {2,}", " ");
    for(shared_ptr<Rule> r : rules) {
        if(r->isPublic()) {
        Matchvector m = matchesRule(r, test);
            if(m.size() != 0) {
                return r->getRuleName();
            }
        }
    }
    return "";
}