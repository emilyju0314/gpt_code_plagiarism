inline void SubtableColumnBase::move_last_row_over(size_t row_ndx, size_t prior_num_rows,
                                                   bool broken_reciprocal_backlinks)
{
    IntegerColumn::move_last_row_over(row_ndx, prior_num_rows, broken_reciprocal_backlinks); // Throws

    const bool fix_ndx_in_parent = true;
    size_t last_row_ndx = prior_num_rows - 1;
    bool last_entry_removed =
        m_subtable_map.adj_move_over<fix_ndx_in_parent>(last_row_ndx, row_ndx);
    typedef _impl::TableFriend tf;
    if (last_entry_removed)
        tf::unbind_ptr(*m_table);
}