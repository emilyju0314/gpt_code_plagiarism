string Grammar::replaceFirst(const string & s, const string & re, const string & replacement)
{
    regex reg (re);
    return regex_replace(s, reg, replacement, regex_constants::format_first_only);
}