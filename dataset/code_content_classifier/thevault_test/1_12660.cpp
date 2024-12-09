string Grammar::getText() const
{
    string s = "grammar " + name + ";\n";

    for(shared_ptr<Rule> r : rules)
    {
        s += r->getRuleString() + "\n";
    }

    return s;
}