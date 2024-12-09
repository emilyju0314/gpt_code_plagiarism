bool tld_email_list::next(tld_email *e) const
{
    if(f_pos >= static_cast<int>(f_email_list.size()))
    {
        return false;
    }

    e->f_group               = f_email_list[f_pos].f_group.c_str();
    e->f_original_email      = f_email_list[f_pos].f_original_email.c_str();
    e->f_fullname            = f_email_list[f_pos].f_fullname.c_str();
    e->f_username            = f_email_list[f_pos].f_username.c_str();
    e->f_domain              = f_email_list[f_pos].f_domain.c_str();
    e->f_email_only          = f_email_list[f_pos].f_email_only.c_str();
    e->f_canonicalized_email = f_email_list[f_pos].f_canonicalized_email.c_str();
    ++f_pos;

    return true;
}