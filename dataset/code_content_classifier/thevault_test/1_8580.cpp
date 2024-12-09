inline void StringEnumColumn::insert_rows(size_t row_ndx, size_t num_rows_to_insert,
                                          size_t prior_num_rows, bool insert_nulls)
{
    REALM_ASSERT_DEBUG(prior_num_rows == size());
    REALM_ASSERT(row_ndx <= prior_num_rows);
    REALM_ASSERT(!insert_nulls || m_nullable);
    static_cast<void>(insert_nulls);

    StringData value = m_nullable ? realm::null() : StringData("");
    bool is_append = (row_ndx == prior_num_rows);
    do_insert(row_ndx, value, num_rows_to_insert, is_append); // Throws
}