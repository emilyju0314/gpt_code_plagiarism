std::string tld_definition::get_inverted_name() const
{
    std::string name;

    for(auto it(f_tld.rbegin()); it != f_tld.rend(); ++it)
    {
        std::string const s(f_strings.get_string(*it));
        if(s.empty())
        {
            throw std::logic_error("a segment string is not defined");
        }
        name += '!';
        name += s;
    }

    return name;
}