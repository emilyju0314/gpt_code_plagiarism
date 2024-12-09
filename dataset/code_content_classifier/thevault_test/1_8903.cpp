std::string tld_object::tld_only() const
{
    if(!is_valid())
    {
        throw invalid_domain();
    }
    return f_info.f_tld;
}