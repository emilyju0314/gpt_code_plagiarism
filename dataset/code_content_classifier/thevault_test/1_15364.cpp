shared_ptr<ApplyLambda> makeApplyLambdaFromHoist(const Hoist& hoist) {
    /*
     * Create an "input" TupleSpec that corresponds to hoist.inputColumn;
     *
     * For example, if the original TCAP assignment was:
     *
     *     C(student, examAverage, hwAverage) = hoist "homeworkAverage" from B[student] retain
     * student, examAverage
     *
     * input would be:
     *
     *    setName: "B"
     *    atts: ["student"]
     */
    TupleSpec input;
    {
        AttList inputColumn;
        inputColumn.appendAttribute(hoist.inputColumn.columnId);
        input = TupleSpec(hoist.inputColumn.tableId, inputColumn);
    }

    /*
     * Create an "output" TupleSpec that corresponds the result of the operation.
     *
     * For example, if the original TCAP assignment was:
     *
     *     C(student, examAverage, hwAverage) = hoist "homeworkAverage" from B[student] retain
     * student, examAverage
     *
     * output would be:
     *
     *    setName: "C"
     *    atts: ["student", "examAverage", "hwAverage"]
     */
    TupleSpec output;
    {
        AttList attributes = makeAttributeList(*hoist.columnsToCopyToOutputTable.get());
        attributes.appendAttribute(hoist.outputColumn.columnId);
        output = TupleSpec(hoist.outputColumn.tableId, attributes);
    }

    /*
     * Create a "projection" TupleSpec that describes which columns are to be copied from the input
     * to the output.
     * (these will be a subset of the output TupleSpec created above)
     *
     * For example, if the original TCAP assignment was:
     *
     *     C(student, examAverage, hwAverage) = hoist "homeworkAverage" from B[student] retain
     * student, examAverage
     *
     * output would be:
     *
     *    setName: "B"
     *    atts: ["student", "examAverage"]
     *
     */
    TupleSpec projection;
    {
        AttList attributes = makeAttributeList(*hoist.columnsToCopyToOutputTable.get());
        projection = TupleSpec(hoist.inputColumn.tableId, attributes);
    }

    return make_shared<ApplyLambda>(input, output, projection, hoist.executorId);
}