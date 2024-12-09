inline void SubtableColumnBase::erase_rows(size_t row_ndx, size_t num_rows_to_erase,
                                           size_t prior_num_rows,
                                           bool broken_reciprocal_backlinks)
{
    IntegerColumn::erase_rows(row_ndx, num_rows_to_erase, prior_num_rows,
                       broken_reciprocal_backlinks); // Throws

    const bool fix_ndx_in_parent = true;
    bool last_entry_removed =
        m_subtable_map.adj_erase_rows<fix_ndx_in_parent>(row_ndx, num_rows_to_erase);
    typedef _impl::TableFriend tf;
    if (last_entry_removed)
        tf::unbind_ptr(*m_table);
}