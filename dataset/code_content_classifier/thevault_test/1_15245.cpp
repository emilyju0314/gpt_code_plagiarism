NvDlaError engine_ast::Edge::registerSurface()
{
    NvDlaError e = NvDlaError_Success;

    surface::TensorSurfaceDesc* tsd = NULL;
    TensorType tt;
    NvU16 numBatches = graph()->profile()->multiBatchSize();

    if ( !isDataEdge() )
    {
        goto fail;
    }

    tt = originalTensor() ? originalTensor()->getTensorType() : TensorType::kDEBUG;

    if ( tt == TensorType::kUNKNOWN )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter, "Unidentified TensorType '%d' in edge '%s'", tt, id().c_str());
    }

    tsd = tensorSurfaceDesc();
    if ( !tsd )
    {
        tsd = graph()->resourceMgr()->regTensorSurfaceDesc(tt, numBatches);
        tsd->setName(std::string(originalTensor()->getName()));
        tsd->setBufferOffset(0);        // default offset
        tsd->setDimensions(originalTensor()->getDimensions());
        tsd->setCopyOutDebugSurface(tt == TensorType::kDEBUG);
        tsd->setDataFormat(originalTensor()->getDataFormat());
        tsd->setParentEdge(this);
        setTensorSurfaceDesc(tsd);

        //
        // is this edge related to a bindable resource?
        // if so we need to maintain that connection.
        //
        if ( bindable() )
        {
            enum IOD bindDomain;
            NvS16 bid = bindId(bindDomain);
            tsd->setBindId(bid, bindDomain);
            if ( debugBinding() )
            {
                gLogInfo << "set bind id " << bid << " for " << id() << " " << tsd->id() << endl;
            }

            // tbd: theoretically could be cvsram as well?
            // choosing not to support it for now.
            //tsd->setMemoryLoc(memory::LocationEnum::lDRAM);
        }

        if ( graph()->debugSurfaces() )
        {
            gLogInfo << ((tt == TensorType::kDEBUG) ? "(debug) ":"" ) <<
                "edge: " << id() << " tsd: " << tsd->id() <<
                " registered" << endl;
        }
    }

fail:
    return e;
}