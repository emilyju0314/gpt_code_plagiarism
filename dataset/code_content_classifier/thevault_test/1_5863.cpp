std::string Slice::ToString(bool hex) const
{
    std::string result; // RVO/NRVO/move
    if (hex)
    {
        result.reserve(2 * size_);
        for (size_t i = 0; i < size_; ++i)
        {
            unsigned char c = data_[i];
            result.push_back(toHex(c >> 4));
            result.push_back(toHex(c & 0xf));
        }
        return result;
    }
    else
    {
        result.assign(data_, size_);
        return result;
    }
}