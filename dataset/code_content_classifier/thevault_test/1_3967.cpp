Handles* HeapTable::select(Handles *current_selection, const ValueDict* where) {
    Handles* handles = new Handles();
    for (auto const& handle: *current_selection)
        if (selected(handle , where))
            handles->push_back(handle);
    return handles;
}