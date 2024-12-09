StatusCode PtOverlayCnv::createObj(IOpaqueAddress* pOpaque, DataObject*& refpObject) 
{
    StatusCode status = StatusCode::SUCCESS;

    // If no opaque address then there is nothing to do
    if (!pOpaque) return StatusCode::FAILURE;

    // Recover the pointer to the registry
    IRegistry* pRegistry = pOpaque->registry();

    if (!pRegistry) return StatusCode::FAILURE;

    // Recover pointer to the data provider service
    IDataProviderSvc* pDataSvc = pRegistry->dataSvc();

    if (!pDataSvc) return StatusCode::FAILURE;

    IOverlayDataSvc* inputDataSvc = SmartIF<IOverlayDataSvc>(pDataSvc);

    // Retrieve the pointer to the digi
    EventOverlay* overlayRoot = inputDataSvc->getRootEventOverlay();

    // Extract GEM information from input digis
    const PtOverlay &ptRoot = overlayRoot->getPtOverlay();

    // Create the new PtOverlay event to put in the TDS
    Event::PtOverlay* ptTds = new Event::PtOverlay();

    float sc_position[3];

    sc_position[0] = ptRoot.getSC_Position()[0];
    sc_position[1] = ptRoot.getSC_Position()[1];
    sc_position[2] = ptRoot.getSC_Position()[2];

    ptTds->initPtOverlay(ptRoot.getStartTime(), 
                         sc_position,
                         ptRoot.getLatGeo(),
                         ptRoot.getLonGeo(),
                         ptRoot.getLatMag(),
                         ptRoot.getRadGeo(),
                         ptRoot.getRaScz(),
                         ptRoot.getDecScz(),
                         ptRoot.getRaScx(),
                         ptRoot.getDecScx(),
                         ptRoot.getZenithScz(),
                         ptRoot.getB(),
                         ptRoot.getL(),
                         ptRoot.getLambda(),
                         ptRoot.getR(),
                         ptRoot.getBEast(),
                         ptRoot.getBNorth(),
                         ptRoot.getBUp(),
						 ptRoot.getLATMode(),
						 ptRoot.getLATConfig(),
						 ptRoot.getDataQual(),
						 ptRoot.getRockAngle(),
						 ptRoot.getLivetimeFrac()
						 );


    // Return the pointer to it
    refpObject = ptTds;

    return status;
}