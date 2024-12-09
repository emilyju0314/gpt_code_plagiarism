inline void SubtableColumnBase::insert_rows(size_t row_ndx, size_t num_rows_to_insert,
                                            size_t prior_num_rows, bool insert_nulls)
{
    REALM_ASSERT_DEBUG(prior_num_rows == size());
    REALM_ASSERT(row_ndx <= prior_num_rows);
    REALM_ASSERT(!insert_nulls);
    static_cast<void>(insert_nulls);

    size_t row_ndx_2 = (row_ndx == prior_num_rows ? realm::npos : row_ndx);
    int_fast64_t value = 0;
    do_insert(row_ndx_2, value, num_rows_to_insert); // Throws
}