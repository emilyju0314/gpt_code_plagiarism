std::vector<char> rtrim(const std::vector<char>& in)
    {
      std::vector<char> ret(in);
      size_t len = ret.size();
      while (len && !*ret.rbegin()) {
        ret.resize(--len);
      }
      return ret;
    }