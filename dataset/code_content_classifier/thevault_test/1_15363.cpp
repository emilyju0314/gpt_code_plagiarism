shared_ptr<ApplyFilter> makeApplyFilterFromFilter(const Filter& filter) {
    /*
     * Create an "input" TupleSpec that corresponds to hoist.inputColumn;
     *
     * For example, if the original TCAP assignment was:
     *
     *     E(student, teacher) = filter D by isExamGreater retain student, teacher
     *
     * input would be:
     *
     *    setName: "D"
     *    atts: ["isExamGreater"]
     */
    TupleSpec input;
    {
        AttList filterColumn;
        filterColumn.appendAttribute(filter.filterColumnId);
        input = TupleSpec(filter.inputTableId, filterColumn);
    }

    /*
     * Create an "output" TupleSpec that corresponds the result of the operation.
     *
     * For example, if the original TCAP assignment was:
     *
     *     E(student, teacher) = filter D by isExamGreater retain student, teacher
     *
     * output would be:
     *
     *    setName: "E"
     *    atts: ["student", "teacher"]
     */
    TupleSpec output;
    {
        AttList attributes = makeAttributeList(*filter.columnsToCopyToOutputTable.get());
        output = TupleSpec(filter.outputTableId, attributes);
    }

    /*
     * Create a "projection" TupleSpec that describes which columns are to be copied from the input
     * to the output.
     * (these will be a subset of the output TupleSpec created above)
     *
     * For example, if the original TCAP assignment was:
     *
     *    E(student, teacher) = filter D by isExamGreater retain student, teacher
     *
     * output would be:
     *
     *    setName: "D"
     *    atts: ["student", "teacher"]
     *
     */
    TupleSpec projection;
    {
        AttList attributes = makeAttributeList(*filter.columnsToCopyToOutputTable.get());
        projection = TupleSpec(filter.inputTableId, attributes);
    }

    return make_shared<ApplyFilter>(input, output, projection);
}