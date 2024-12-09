inline size_t Column::find_gte(int64_t target, size_t start) const
{
    // fixme: slow reference implementation. See Array::FindGTE for faster version
    size_t ref = 0;
    size_t idx;
    for (idx = start; idx < size(); ++idx) {
        if (get(idx) >= target) {
            ref = idx;
            break;
        }
    }
    if (idx == size())
        ref = not_found;

    return ref;
}