ValueDicts* DbRelation::project(Handles *handles, const ValueDict* where) {
    ColumnNames t;
    for (auto const& column: *where)
        t.push_back(column.first);
    ValueDicts *ret = new ValueDicts();
    for (auto const& handle: *handles)
        ret->push_back(project(handle, &t));
    return ret;
}