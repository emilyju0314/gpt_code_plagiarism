std::string tld_object::country() const
{
    // std::string doesn't like NULL as a parameter
    //
    if(f_info.f_country == nullptr)
    {
        return std::string();
    }
    return f_info.f_country;
}