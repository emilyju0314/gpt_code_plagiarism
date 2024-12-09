shared_ptr<ApplyLambda> makeApplyLambdaFromApplyBase(const ApplyBase& apply) {
    /*
     * Create an "input" TupleSpec that corresponds to ApplyBase.inputColumns;
     *
     * For example, if the original TCAP assignment was:
     *
     *     B(student, teacher, fooResult) = apply func "foo" to A[student,class] retain student,
     * teacher
     *
     * input would be:
     *
     *    setName: "A"
     *    atts: ["student", "class"]
     */
    TupleSpec input;
    {
        AttList attributes = makeAttributeList(apply.inputColumns);
        string inputTable = apply.inputColumns.tableName;
        input = TupleSpec(inputTable, attributes);
    }

    /*
     * Create an "output" TupleSpec that corresponds to the result of the apply operation
     *
     * For example, if the original TCAP assignment was:
     *
     *     B(student, teacher, fooResult) = apply func "foo" to A[student,class] retain student,
     * teacher
     *
     * output would be:
     *
     *    setName: "B"
     *    atts: ["student", "teacher", "fooResult"]
     */
    TupleSpec output;
    {
        AttList attributes = makeAttributeList(*apply.columnsToCopyToOutputTable.get());
        attributes.appendAttribute(apply.outputColumnId);
        output = TupleSpec(apply.outputTableId, attributes);
    }

    /*
     * Create a "projection" TupleSpec that describes which columns are to be copied from the input
     * to the output.
     * (these will be a subset of the output TupleSpec created above)
     *
     * For example, if the original TCAP assignment was:
     *
     *     B(student, teacher, fooResult) = apply func "foo" to A[student,class] retain student,
     * teacher
     *
     * output would be:
     *
     *    setName: "A"
     *    atts: ["student", "teacher"]
     *
     */
    TupleSpec projection;
    {
        AttList attributes = makeAttributeList(*apply.columnsToCopyToOutputTable.get());
        projection = TupleSpec(apply.inputColumns.tableName, attributes);
    }

    return make_shared<ApplyLambda>(input, output, projection, apply.executorId);
}