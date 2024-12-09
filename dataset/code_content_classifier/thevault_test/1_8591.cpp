inline void MixedColumn::insert_rows(size_t row_ndx, size_t num_rows_to_insert,
                                     size_t prior_num_rows, bool insert_nulls)
{
    REALM_ASSERT_DEBUG(prior_num_rows == size());
    REALM_ASSERT(row_ndx <= prior_num_rows);
    REALM_ASSERT(!insert_nulls);
    static_cast<void>(insert_nulls);

    size_t row_ndx_2 = (row_ndx == prior_num_rows ? realm::npos : row_ndx);

    int_fast64_t type_value = mixcol_Int;
    m_types->insert_without_updating_index(row_ndx_2, type_value, num_rows_to_insert); // Throws

    // The least significant bit indicates that the rest of the bits form an
    // integer value, so 1 is actually zero.
    int_fast64_t data_value = 1;
    m_data->do_insert(row_ndx_2, data_value, num_rows_to_insert); // Throws
}