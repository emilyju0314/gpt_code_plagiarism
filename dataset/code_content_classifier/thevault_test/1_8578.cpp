inline void AdaptiveStringColumn::insert(std::size_t row_ndx, std::size_t num_rows, bool is_append)
{
    StringData value = StringData();
    do_insert(row_ndx, value, num_rows, is_append); // Throws
}