inline bool save(const ArrayContainer& A, const std::string& fileName, bool append = Overwrite, Error* error = nullptr, const TagList& hints = TagList())
{
    Error e = Exporter(fileName, append, hints).writeArray(A);
    if (error)
        *error = e;
    return (e == ErrorNone);
}