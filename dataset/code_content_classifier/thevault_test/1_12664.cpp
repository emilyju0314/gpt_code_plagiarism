shared_ptr<Rule> Grammar::getRule(const string & ruleName) const
{
    for(shared_ptr<Rule> r : rules)
    {
        if(r->getRuleName() == ruleName)
        {
            return r;
        }
    }
    return nullptr;
}