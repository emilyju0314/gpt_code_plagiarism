inline bool ArrayBinary::legacy_array_type() const noexcept
{
    if (Array::size() == 3)
        return false;               // New database file
    else if (Array::size() == 2)
        return true;                // Old database file
    else
        REALM_ASSERT(false);        // Should never happen
    return false;
}