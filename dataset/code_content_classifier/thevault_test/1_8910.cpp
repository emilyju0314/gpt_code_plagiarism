bool tld_email_list::next(tld_email_t& e) const
{
    if(f_pos >= static_cast<int>(f_email_list.size()))
    {
        return false;
    }

    e = f_email_list[f_pos];
    ++f_pos;

    return true;
}