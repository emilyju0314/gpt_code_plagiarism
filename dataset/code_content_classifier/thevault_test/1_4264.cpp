int makeAnagram(string a, string b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int count = 0;

    size_t ia = 0;
    size_t ib = 0;
    while (ia < a.size() && ib < b.size())
    {
        auto &ca = a[ia];
        auto &cb = b[ib];
        if (ca == cb)
        {
            ++ia;
            ++ib;
        }
        else if (ca < cb)
        {
            ++count;
            ++ia;
        }
        else if (cb < ca)
        {
            ++count;
            ++ib;
        }
    }

    return count + (a.size() - ia) + (b.size() - ib);
}