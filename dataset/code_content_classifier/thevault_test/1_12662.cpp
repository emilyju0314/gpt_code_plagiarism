MatchResult Grammar::match(std::string test) const {
    test = Grammar::trimString(test);
    test = Grammar::replaceAll(test, " {2,}", " ");
    for(shared_ptr<Rule> r : rules) {
        Matchvector m = matchesRule(r, test);
        if(m.size() != 0) {
            return MatchResult(r, m);
        }
    }
    return MatchResult();
}