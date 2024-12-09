vector<shared_ptr<MatchInfo>> Grammar::matchesRule(const shared_ptr<Rule> rule, const string & test) const {
    vector<string> words = Grammar::splitString(test, " ");
    string* wordArray = &words[0];
    vector<shared_ptr<MatchInfo>> m1 = getMatchingExpansions(rule->getRuleExpansion(), wordArray, words.size(), 0);
    unsigned int matchCount = 0;
    for (shared_ptr<MatchInfo> mi2 : m1) {
	//std::cout << "MI: " << mi2->getMatchingSection() << ", " << matchCount << ", " << printExpansionType(mi2->getExpansion().get()) << std::endl;

        if (mi2->getMatchingSection() != "") {
            matchCount++;
        }
    }
    if(matchCount != words.size()) { // Must match all the words!
        m1.clear();
    }

    return m1;
}