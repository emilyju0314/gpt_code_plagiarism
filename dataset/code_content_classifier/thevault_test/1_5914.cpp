void
  UVarTable::clean(const UVar& uvar)
  {
    iterator i = find(uvar.get_name());
    if (i != end())
    {
      for (mapped_type::iterator j = i->second.begin();
           j != i->second.end();)
        if (*j == &uvar)
          j = i->second.erase(j);
        else
          ++j;

      if (i->second.empty())
        erase(i);
    }
  }