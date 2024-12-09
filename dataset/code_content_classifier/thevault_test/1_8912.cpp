std::string tld_definition::get_name() const
{
    std::string name;

    for(auto const & segment : f_tld)
    {
        std::string const s(f_strings.get_string(segment));
        if(s.empty())
        {
            throw std::logic_error("a segment string is not defined");
        }
        name += '.';
        name += s;
    }

    return name;
}