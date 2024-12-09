std::pair<size_t, uint16_t> trie::find(const std::string &s, size_t start)
const noexcept
{
    size_t current = 0, longest = 0, steps = 0;
    uint16_t escape = 0;
    for (; start != s.size(); ++start)
    {
        size_t add = data[current].next[static_cast<byte>(s[start])];
        if (add != INF)
        {
            current = add;
            ++steps;
            if (data[current].is_terminal)
            {
                longest = steps;
                escape = data[current].escape;
            }
        }
        else
            break;
    }
    return {longest, escape};
}