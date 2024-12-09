inline void MixedColumn::erase_rows(size_t row_ndx, size_t num_rows_to_erase,
                                    size_t prior_num_rows, bool)
{
    do_erase(row_ndx, num_rows_to_erase, prior_num_rows); // Throws
}