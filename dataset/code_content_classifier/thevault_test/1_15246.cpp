NvDlaError engine_ast::Edge::registerBuffer()
{
    NvDlaError e = NvDlaError_Success;
    typedef memory::TensorBufferDesc TBD;

    surface::TensorSurfaceDesc *tsd;
    Graph::NodeUnorderedSet producers;
    Graph::NodeUnorderedSet consumers;
    Graph::NodeUnorderedSet clients;

    TBD* currTBD = NULL;
    TBD* commonTBD = NULL;
    std::map<Node*, TBD*> clientBufferMap;

    tsd = tensorSurfaceDesc();

    if ( !isDataEdge() )
    {
        goto fail;
    }
    else if (!tsd)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "TSD not yet registered for edge %s", id().c_str());
    }
    else if ( tsd->tensorCategory().v() == memory::TensorCategoryEnum::UNKNOWN_TENSOR )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter, "Edge %s has 'unknown' tensor category",
                             tsd->id().c_str());
    }

    producers = tsd->producers();
    consumers = tsd->consumers();
    clients.insert(producers.begin(), producers.end());
    clients.insert(consumers.begin(), consumers.end());

    commonTBD = tsd->tensorBufferDesc();
    if ( !commonTBD )
    {
        Graph::NodeUnorderedSetIterator cli;

        for (cli = clients.begin(); cli != clients.end(); ++cli)
        {
            if ((*cli)->isSoftwareNode())
            {
                commonTBD = (*cli)->suggestBuffer(tsd);
                break;
            }
        }

        // Step-1: If there's a software client, prefer its suggested TBD
        //         don't bother querying the TBDs from non-software clients
        if (commonTBD)
        {
            tsd->setTensorBufferDesc(commonTBD);
        }
        // Step-2: If there's no software client, assert that all clients suggested 1 common TBD
        else
        {
            for (cli = clients.begin(); cli != clients.end(); ++cli)
            {
                currTBD = (*cli)->suggestBuffer(tsd);
                if (cli == clients.begin())
                {
                    commonTBD = currTBD;
                    tsd->setTensorBufferDesc(commonTBD);
                }
                else
                {
                    ASSERT(currTBD == commonTBD);
                }
            }
        }
    }

    PROPAGATE_ERROR_FAIL( commonTBD->addSurface(tsd) );
    if ( graph()->debugBuffers() )
    {
        gLogInfo << commonTBD->id() << " for " << tsd->id() << " for " << id() << " with " << tsd->surfaceFormat().c_str() << endl;
    }

fail:
    return e;
}