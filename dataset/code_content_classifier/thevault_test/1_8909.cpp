tld_result tld_email_list::parse(std::string const & emails, int flags)
{
    f_input = emails;
    f_flags = flags;
    f_result = TLD_RESULT_SUCCESS;
    f_last_group.clear();
    f_pos = 0; // always rewind too
    f_email_list.clear();

    parse_all_emails();
    if(f_result != TLD_RESULT_SUCCESS)
    {
        f_email_list.clear();
    }

    return f_result;
}