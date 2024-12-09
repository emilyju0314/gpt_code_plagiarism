NvDlaError engine_ast::Edge::reserveBuffer()
{
    NvDlaError e = NvDlaError_Success;

    NvU64 existingSize = 0;
    NvU64 proposedSize = 0;
    memory::TensorCategory tc;
    memory::TensorBufferDesc* tbd;
    surface::TensorSurfaceDesc* tsd = tensorSurfaceDesc();
    NvU16 numBatches = graph()->profile()->multiBatchSize();

    if ( !isDataEdge() )
    {
        goto fail;
    }
    else if (!tsd)
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "TSD not yet registered for edge %s", id().c_str());
    }
    else if (!tsd->size())
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "surface size == 0 for %s", tsd->id().c_str());
    }

    tbd = tsd->tensorBufferDesc();
    tc  = tsd->tensorCategory();
    existingSize = tbd->size();
    proposedSize = tsd->size();
    switch(tc.v())
    {
        case memory::TensorCategoryEnum::GLOBAL_TENSOR:
        case memory::TensorCategoryEnum::LOCAL_TENSOR:
            tbd->setSize( std::max<NvU64>(existingSize, proposedSize) );
            break;
        case memory::TensorCategoryEnum::EXTERNAL_TENSOR:
            ASSERT( bindable() );
            // adjust buffer size for multiple batches on the bindable tensor
            if ( existingSize )
            {
                tbd->setSize( std::max<NvU64>(existingSize, proposedSize * numBatches) );
            }
            else
            {
                tbd->setSize(proposedSize * numBatches);
            }
            break;
        case memory::TensorCategoryEnum::STREAM_TENSOR:
            tbd->setMemoryLoc(memory::LocationEnum::lSTREAM);
            break;

        default:
            ORIGINATE_ERROR_FAIL(NvDlaError_BadValue, "Tensor Category:%s not recognized", tc.c_str());
    }

fail:
    return e;
}