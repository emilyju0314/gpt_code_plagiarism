NvDlaError engine_ast::SDPScaleOpNode::populateWithUnitScaleParams
(
    engine_ast::SDPMode scaleMode,
    Dims4               scaleDims
)
{
    NvDlaError e = NvDlaSuccess;

    surface::SurfacePrecision computePrecision = graph()->profile()->computePrecision();
    Weights unitScaleData = Weights(nvdla::DataType::FLOAT, NULL, 0);

    Tensor* scaleDataTensor;
    engine_ast::Edge* scaleDataEdge  = NULL;
    NVDLA_UNUSED(scaleDataEdge);

    /* Creates a new unit scale data */
    PRECISION_SWITCH(nvdla::DataType::FLOAT, computePrecision.v(), unitScaleData,
                                                                    WeightTrns::createUnitScaleData,
                                                                    scaleMode,
                                                                    scaleDims);

    params().x1Params().setEnabled(true);
    params().x1Params().setMode(scaleMode);
    params().setScaleDims(scaleDims);
    params().setRawScaleData(unitScaleData);
    params().setDLAScaleData(Weights(DataType::FLOAT, NULL, 0));

    setUnitScale(true);

    /* adds aux tensor and an edge corresponding to it */
    scaleDataTensor = graph()->addAuxTensor(graph()->newAuxTensorName(), params().scaleDims(), TensorType::kSCALE);
    scaleDataEdge = graph()->addDataEdge((canonical_ast::Edge*)0, 0, this, scaleDataTensor);

    return e;
}