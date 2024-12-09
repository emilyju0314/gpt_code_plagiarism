inline std::string pad_number(const size_t number,
                                const size_t npad,
                                const char pad_value = '0') {
    std::stringstream strm;
    strm << std::setw((int)npad) << std::setfill(pad_value)
         << number;
    return strm.str();
  }