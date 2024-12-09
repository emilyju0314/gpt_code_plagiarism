ValueDict* DbRelation::project(Handle handle, const ValueDict* where) {
    ColumnNames t;
    for (auto const& column: *where)
        t.push_back(column.first);
    return this->project(handle, &t);
}