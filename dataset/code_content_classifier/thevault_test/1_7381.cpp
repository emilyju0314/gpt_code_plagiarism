inline std::string to_camel_case(std::string str)
{
    auto in       = str.begin();
    auto out      = in;
    auto last     = str.end();
    auto new_word = false;
    for (; in != last; ++in) {
        auto c = *in;
        if (std::isdigit(c)) {
            *out++ = c;
        } else if (!std::isalpha(c)) {
            new_word = true;
        } else if (new_word) {
            *out++   = std::toupper(*in);
            new_word = false;
        } else {
            *out++ = std::tolower(*in);
        }
    }
    str.resize(out - str.begin());
    return str;
}