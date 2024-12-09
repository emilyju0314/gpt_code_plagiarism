std::string SHA1::final()
{
    auto str = final_bin();

    std::ostringstream result;

    for (size_t i = 0; i < str.size(); i++)
    {
        char b[3];
        sprintf(b, "%02x", static_cast<unsigned char>(str[i]));
        result << b;
    }

    return result.str();
}