inline void Column::insert(std::size_t row_ndx, std::size_t num_rows, bool is_append)
{
    std::size_t row_ndx_2 = is_append ? realm::npos : row_ndx;
    int_fast64_t value = 0;
    do_insert(row_ndx_2, value, num_rows); // Throws
}