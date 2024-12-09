inline void AdaptiveStringColumn::move_last_over(std::size_t row_ndx, std::size_t last_row_ndx,
                                                 bool)
{
    do_move_last_over(row_ndx, last_row_ndx); // Throws
}