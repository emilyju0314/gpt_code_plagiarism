shared_ptr<ApplyLambda> makeApplyLambdaFromGreaterThan(const GreaterThan& gt) {
    if (gt.leftHandSide.tableId != gt.rightHandSide.tableId)
        throw "cross table comparison not supported by ApplyLambda";  // TupleSpec allows only one
                                                                      // setNameIn in constructor

    string inputTableId = gt.leftHandSide.tableId;

    /*
     * Create an "input" TupleSpec that corresponds the left and right hand sides of gt while
     * preserving order.
     *
     * For example, if the original TCAP assignment was:
     *
     *     D(student, isExamGreater) = C[examAverage] > C[hwAverage] retain student
     *
     * input would be:
     *
     *    setName: "C"
     *    atts: ["examAverage", "hwAverage"]
     */
    TupleSpec input;
    {
        AttList inputColumn;
        inputColumn.appendAttribute(gt.leftHandSide.columnId);
        inputColumn.appendAttribute(gt.rightHandSide.columnId);
        input = TupleSpec(inputTableId, inputColumn);
    }

    /*
     * Create an "output" TupleSpec that corresponds the result of the operation.
     *
     * For example, if the original TCAP assignment was:
     *
     *    D(student, isExamGreater) = C[examAverage] > C[hwAverage] retain student
     *
     * output would be:
     *
     *    setName: "C"
     *    atts: ["student", "isExamGreater"]
     */
    TupleSpec output;
    {
        AttList attributes = makeAttributeList(*gt.columnsToCopyToOutputTable.get());
        attributes.appendAttribute(gt.outputColumn.columnId);
        output = TupleSpec(gt.outputColumn.tableId, attributes);
    }

    /*
     * Create a "projection" TupleSpec that describes which columns are to be copied from the input
     * to the output.
     * (these will be a subset of the output TupleSpec created above)
     *
     * For example, if the original TCAP assignment was:
     *
     *     D(student, isExamGreater) = C[examAverage] > C[hwAverage] retain student
     *
     * output would be:
     *
     *    setName: "C"
     *    atts: ["student"]
     *
     */
    TupleSpec projection;
    {
        AttList attributes = makeAttributeList(*gt.columnsToCopyToOutputTable.get());
        projection = TupleSpec(inputTableId, attributes);
    }

    return make_shared<ApplyLambda>(input, output, projection, gt.executorId);
}