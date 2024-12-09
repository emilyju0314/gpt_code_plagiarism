void trim(std::string& value)
{
    if(!value.empty())
    {
        size_t i(value.length());
        for(; i > 0; --i)
        {
            const char c(value[i - 1]);
            if(c != ' ' && c != '\r' && c != '\n' && c != '\t')
            {
                break;
            }
        }
        value.resize(i);
    }
}