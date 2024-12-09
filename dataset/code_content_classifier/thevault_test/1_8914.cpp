void tld_compiler::find_max_level()
{
    f_tld_max_level = 0;

    auto it(std::max_element(
              f_definitions.begin()
            , f_definitions.end()
            , [](auto const & a, auto const & b)
              {
                  return a.second->get_segments().size()
                                        < b.second->get_segments().size();
              }));
    if(it == f_definitions.end())
    {
        f_errno = EINVAL;
        f_errmsg = "error: could not find a definition with a larger level.";
        return;
    }

    f_tld_max_level = it->second->get_segments().size();
}