void Grammar::parseGrammarFromString(const string & s, Grammar & grammar)
{
    //string noComments = Grammar::replaceAll(s, "(\\#+.*[\\n|\\r|\\v])|([//]+.*[\\n|\\r|\\v])", ""); // Remove all commented out lines
    //vector<string> statements = Grammar::splitString(s, ";"); // Split into statements with each semicolon, NOTE: semicolons within quotes are not protected! Lookbehinds are not supported in C++11 https://stackoverflow.com/questions/14538687/using-regex-lookbehinds-in-c11#14539500
    string statement;
    stringstream ss(s);
    ///https://www.reddit.com/r/cpp_questions/comments/931zq5/any_way_to_simulate_multi_line_regex_with_c11/
    ///Why can't C++11 just have multiline regex? Ugh.

    while(getline(ss, statement, ';')) { /// Note: Semicolons are not protected!
        statement = Grammar::trimString(statement);
        //Remove extra whitespace between characters
        statement = Grammar::replaceAll(statement, " {2,}", " ");

        if (Grammar::stringStartsWith(statement, "#"))
        {
            continue; // Line is a comment, skip it.
        }
        else if (Grammar::stringStartsWith(statement, "grammar "))
        {
            vector<string> parts = Grammar::splitString(statement, " ");
            grammar.setName(parts[1]);
        }
        else if (Grammar::stringStartsWith(statement,"public <"))
        {
            statement = Grammar::replaceFirst(statement, "public ", "");
			vector<string> parts = Grammar::splitString(statement, "=");
            string ruleName = Grammar::replaceAll(parts[0],"<|>", "");
            ruleName = Grammar::trimString(ruleName);
            Expansion * exp = Grammar::parseExpansionsFromString(parts[1]);
            grammar.addRule(std::make_shared<Rule>(ruleName, true, shared_ptr<Expansion>(exp)));
        }
        else if (Grammar::stringStartsWith(statement,"<"))
        {
            vector<string> parts = Grammar::splitString(statement, "=");
            string ruleName = Grammar::replaceAll(parts[0],"<|>", "");
            ruleName = Grammar::trimString(ruleName);
            Expansion * exp = Grammar::parseExpansionsFromString(parts[1]);
            grammar.addRule(std::make_shared<Rule>(ruleName, false, shared_ptr<Expansion>(exp)));
        }
    }
}