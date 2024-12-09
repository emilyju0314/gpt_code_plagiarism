ValueDicts* DbRelation::project(Handles *handles, const ColumnNames *column_names) {
    ValueDicts *ret = new ValueDicts();
    for (auto const& handle: *handles)
        ret->push_back(project(handle, column_names));
    return ret;
}