Definition Definition::deep_copy(
        std::map<IntrusivePtr<FunctionContents>, IntrusivePtr<FunctionContents>> &copied_map) const {
    internal_assert(contents.defined()) << "Cannot deep-copy undefined Definition\n";

    Definition copy;
    copy.contents->is_init = contents->is_init;
    copy.contents->predicate = contents->predicate;
    copy.contents->values = contents->values;
    copy.contents->args = contents->args;
    copy.contents->schedule = contents->schedule.deep_copy(copied_map);

    // Deep-copy specializations
    for (const Specialization &s : contents->specializations) {
        Specialization s_copy;
        s_copy.condition = s.condition;
        s_copy.definition = s.definition.deep_copy(copied_map);
        copy.contents->specializations.push_back(std::move(s_copy));
    }
    return copy;
}