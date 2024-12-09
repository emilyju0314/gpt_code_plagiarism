Nd4jStatus GraphExecutioner::executeFlatNode(Graph *graph, Node *node, VariableSpace *variableSpace) {
    OpType opType = node->opType();
    int opNum = node->opNum();
//    std::string opName = *(node->getCustomOp()->getOpName());

    if (opType == OpType_BOOLEAN) {
        nd4j_debug("Executing boolean graph node_%i", node->id());
    } else if (opType == OpType_LOGIC) {
        nd4j_debug("Executing logic graph node_%i", node->id());
    } else if (opType == OpType_GRAPH) {
        nd4j_debug("Executing embedded graph node_%i", node->id());
    } else if (opType != OpType_CUSTOM) {
        nd4j_debug("Executing node_%i{%i}\n", node->id(), opNum);
    } else {
        nd4j_debug("Executing node_%i{%s}\n", node->id(), node->getCustomOp()->getOpName()->c_str());
    }

    Context context(node->getContextPrototype(), variableSpace);

    if (sd::Environment::getInstance()->isDebugAndVerbose()) {
        //nd4j_debug("Input variables: %i\n", node->input()->size());
        printf("       Inputs: {");
        for (int e = 0; e < node->input()->size(); e++) {
            printf("[%i:%i]", node->input()->at(e).first, node->input()->at(e).second);

            if (e < node->input()->size() - 1)
                printf(", ");
        }
        printf("}\n");
        fflush(stdout);
    }

    if (node->id() == 13)
        nd4j_debug("","");

    // if true - this is special case: Graph-in-Graph.
    if (node->hasGraphEmbedded()) {
        auto embedded = node->getGraph();

        /**
         * basically, we should do following things here:
         * 1) fill embedded graph with input variables from this graph, if anything should be filled in
         * 2) invoke embedded graph
         * 3) announce its results as corresponding output variables in current VariableSpace
         */

        // enforcing IMPLICIT mode. or not... should we try to be smarter then user?
        //embedded->getExecutorConfiguration()->_outputMode = OutputMode_IMPLICIT;

        if (node->input()->size() != embedded->numberOfPlaceholders()) {
            nd4j_debug("Placeholders amount mismatch: %i expected, and %i available\n",node->input()->size(), embedded->numberOfPlaceholders());
            return ND4J_STATUS_BAD_INPUT;
        }

        // we need to propagate required variables to the embedded graph
        ResultSet deletables;
        int cnt = 0;
        for (Variable* v: *embedded->getPlaceholders()) {
            if (v->getName() != nullptr && v->getName()->size() > 0) {

                // trying symbolic lookup first
                if (variableSpace->hasVariable(v->getName())) {
                    // symbolic feeder
                    auto array = variableSpace->getVariable(v->getName())->getNDArray();
                    auto vr = new NDArray(array->dup());
//                    deletables.push_back(vr);
                    v->setNDArray(vr);
                } else {
                    nd4j_debug("Can't find variable [%s] in parent graph...", v->getName()->c_str());
                    return ND4J_STATUS_BAD_INPUT;
                    //throw "Can't find desired variable";
                }
            } else {
                // if we're not using symbolic lookup - we'll use sequential approach then
                auto p = node->input()->at(cnt);
                auto array = variableSpace->getVariable(p)->getNDArray();
                auto vr = new NDArray(array->dup());
                //deletables.push_back(vr);
                v->setNDArray(vr);
            }

            cnt++;
        }

        // executing embedded graph as independent one
        Nd4jStatus status = GraphExecutioner::execute(embedded);
        if (status != ND4J_STATUS_OK)
            return status;

        //  now we should migrate its results to this node, as its own outputs
        cnt = 0;
        auto  outputs = embedded->fetchOutputs();

        for (auto v: *outputs){
            NDArray *array = v->getNDArray();
            v->setNDArray(nullptr);

            std::pair<int,int> pair(node->id(), cnt++);

            auto var = variableSpace->getVariable(pair);

            //nd4j_printf("HasArray: [%i]; Removable: [%i]\n", var->hasNDArray(), var->isRemovable());
            var->setNDArray(array);
            var->markRemovable(true);
        }
        deletables.size();
        delete outputs;
        nd4j_debug("Embedded graph execution finished. %i variable(s) migrated\n", cnt);

    } else if (node->hasCustomOp()) {
        // now, if we have something to execute - lets just execute it.
        auto status = node->getCustomOp()->execute(&context);
        if (status != ND4J_STATUS_OK)
            return status;

        // propagate variables
        if (node->hasExternalOutputs()) {
            for (auto v: *node->output()) {
                if (variableSpace->hasExternalVariable(v.first)) {
                    variableSpace->getVariable(v.first)->getNDArray()->assign(variableSpace->getVariable(node->id())->getNDArray());
                }
            }
        }

        return status;
    }
    return ND4J_STATUS_OK;
}