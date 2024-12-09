ValueDicts* DbRelation::project(Handles *handles) {
    ValueDicts *ret = new ValueDicts();
    for (auto const& handle: *handles)
        ret->push_back(project(handle));
    return ret;
}