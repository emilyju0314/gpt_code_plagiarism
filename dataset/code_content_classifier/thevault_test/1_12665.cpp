bool Grammar::removeRule(const string & ruleName) {
    for(vector<shared_ptr<Rule>>::iterator r = rules.begin(); r != rules.end(); r++) {
        if((*r)->getRuleName() == ruleName) {
            rules.erase(r);
            return true;
        }
    }
    return false;
}