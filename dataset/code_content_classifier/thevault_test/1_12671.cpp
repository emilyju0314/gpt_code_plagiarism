string Grammar::replaceAll(const string & s, const string & re, const string & replacement)
{
    regex reg (re);
    return regex_replace(s, reg, replacement);
}