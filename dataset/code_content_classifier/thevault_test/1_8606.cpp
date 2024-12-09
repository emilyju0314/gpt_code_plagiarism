sd::graph::ResultWrapper* GraphExecutioner::executeFlatBuffer(Nd4jPointer pointer) {
    uint8_t *buffer = reinterpret_cast<uint8_t *>(pointer);

    // nd4j_debug("Trying to restore graph\n", 0);

    auto restoredGraph = GetFlatGraph(buffer);

    // nd4j_debug("Graph restored\n", 0);

    // converting FlatGraph to internal representation
    auto nativeGraph = new Graph(restoredGraph);

    if (Environment::getInstance()->isDebugAndVerbose()) {
        nativeGraph->printOut();
    }

    FlowPath flowPath;
    nativeGraph->getVariableSpace()->setFlowPath(&flowPath);


    // nd4j_debug("Going to execute graph\n", 0);

    // executing internal representation
    auto status = GraphExecutioner::execute(nativeGraph);
    if (status != ND4J_STATUS_OK) {
        nd4j_printf("Graph execution failed with status: [%i]\n", status)
        return nullptr;
    }

    // nd4j_debug("Building output...\n", 0);

    flatbuffers::FlatBufferBuilder builder(1024);

    // fetching time reports
    std::vector<flatbuffers::Offset<FlatTiming>> timings_vector;
    for (int e = 0; e < (int) nativeGraph->getAllNodes()->size(); e++) {
        Node *node = nativeGraph->getAllNodes()->at(e);

        if (node->getContextPrototype() == nullptr)
            continue;

        auto pair = CreateLongPair(builder, flowPath.outerTime(node->id()), flowPath.innerTime(node->id()));
        if (node->getName() != nullptr) {
            auto name = builder.CreateString(node->getName()->c_str());
            auto fr = CreateFlatTiming(builder, node->id(), name, pair);
            timings_vector.push_back(fr);
        } else {
            auto fr = CreateFlatTiming(builder, node->id(), 0, pair);
            timings_vector.push_back(fr);
        }
    }


    // now, we'll prepare output, depending on given outputmode
    auto outputs = nativeGraph->fetchOutputs();
    auto size = static_cast<int>(outputs->size());
    int arrays = 0;
    std::vector<flatbuffers::Offset<FlatVariable>> variables_vector;
    for (int e = 0; e < size; e++) {
        auto var = outputs->at(e);

        // FIXME: we want to export multi-output nodes as well
        // FIXME: we want to export NDArrayList and skip nodes without outputs
        if (!var->hasNDArray())
            continue;


        auto array = var->getNDArray();

        auto fArray = FlatUtils::toFlatArray(builder, *array);

        auto fName = builder.CreateString(*(var->getName()));
        auto id = CreateIntPair(builder, var->id(), var->index());

        auto fv = CreateFlatVariable(builder, id, fName, static_cast<sd::graph::DType>(array->dataType()), 0, fArray);

        variables_vector.push_back(fv);
        arrays++;
    }

    nd4j_debug("Returning %i variables back\n", arrays);

    auto varTimings = builder.CreateVector(timings_vector);
    auto varVectors = builder.CreateVector(variables_vector);
    auto result = CreateFlatResult(builder, restoredGraph->id(), varVectors, varTimings);
    builder.Finish(result);

    // we might want to keep this graph for future
    delete outputs;
    delete nativeGraph;

    char* res = new char[builder.GetSize()];
    memcpy(res, builder.GetBufferPointer(), builder.GetSize());

    nd4j_debug("Buffer size: %lld\n", static_cast<Nd4jLong>(builder.GetSize()));

    return new ResultWrapper(builder.GetSize(), reinterpret_cast<Nd4jPointer>(res));
}