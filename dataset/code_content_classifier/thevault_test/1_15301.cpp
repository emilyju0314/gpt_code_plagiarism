NvDlaError engine_ast::Graph::annotateNodes(NvS16& lastUsedAnnId)
{
    NvDlaError e = NvDlaSuccess;

    bool isEMUGraphlet = false;

    vector< Graphlet* >::iterator gli;
    for ( gli = graphlets().begin(); gli != graphlets().end(); ++gli )
    {
        isEMUGraphlet = (*gli)->nodeList()[0]->isEMUEngineType();
        NodeSequence& graphletNodes = (*gli)->nodeList();
        for ( NodeSequenceIterator ni = graphletNodes.begin(); ni != graphletNodes.end(); ++ni )
        {
            Node *node = *ni;
            if (isEMUGraphlet != node->isEMUEngineType())
            {
                ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter, "All nodes in a graphlet should be either all CPU or all DLA");
            }

            if (!node->isDLAEngineType() && !node->isEMUEngineType())
            {
                ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter, "Non-DLA and non-CPU nodes shouldn't be part of any graphlet");
            }
            else
            {
                PROPAGATE_ERROR_FAIL(node->selfAnnotate(lastUsedAnnId));
            }
        }
        // reset annotation id for next graphlet/task
        lastUsedAnnId = -1;
    }

    /* Determine annotation node-id's of the producers/consumers for 1st batch(batch_id: 0)
     *  since from now on operations of all batches should possess unique annotation id's
     */
    for ( gli = graphlets().begin(); gli != graphlets().end(); ++gli )
    {
        NodeSequence& graphletNodes = (*gli)->nodeList();
        for ( NodeSequenceIterator ni = graphletNodes.begin(); ni != graphletNodes.end(); ++ni )
        {
            Node* node = *ni;
            for (size_t et = 0; et < EngineType::num_elements(); ++et)
            {
                NvU32 firstBatchId = 0;
                Node* consumer  = node->dependencyParams(firstBatchId).consumer(et).node();
                NvS16 consAnnId = node->dependencyParams(firstBatchId).consumer(et).nodeAnnId();
                /* populate iff not done before */
                if (consAnnId == -1)
                {
                    node->dependencyParams(firstBatchId).consumer(et).setNodeAnnId(consumer ?
                            consumer->dependencyParams(firstBatchId).annotationId() : -1);
                }

                Node* producer  = node->dependencyParams(firstBatchId).producer(et).node();
                NvS16 prodAnnId = node->dependencyParams(firstBatchId).producer(et).nodeAnnId();
                /* populate iff not done before */
                if (prodAnnId == -1)
                {
                    node->dependencyParams(firstBatchId).producer(et).setNodeAnnId(producer ?
                            producer->dependencyParams(firstBatchId).annotationId() : -1);
                }
            }
        }
    }

fail:
    return e;
}