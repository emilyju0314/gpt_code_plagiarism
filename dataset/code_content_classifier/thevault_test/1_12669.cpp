vector<shared_ptr<MatchInfo>> Grammar::matchesRule(const string & ruleName, const string & test) const {
    shared_ptr<Rule> r = getRule(ruleName);
    if(!r) { // Check to make sure rule exists
        vector<shared_ptr<MatchInfo>> m;
        return m;
    }
    return matchesRule(r, test);
}