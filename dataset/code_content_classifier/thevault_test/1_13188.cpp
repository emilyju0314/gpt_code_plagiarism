StatusCode DiagDataOverlayCnv::createObj(IOpaqueAddress* pOpaque, DataObject*& refpObject) 
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

    IOverlayDataSvc* inputDataSvc = dynamic_cast<IOverlayDataSvc*>(pDataSvc);

    // Retrieve the pointer to the digi
    EventOverlay* overlayRoot = inputDataSvc->getRootEventOverlay();

    // Extract the Diagnostic Data from our input EventOverlay object
    const DiagDataOverlay& diagDataRoot = overlayRoot->getDiagDataOverlay();

    // Create the new DiagDataOverlay object to put in the TDS
    Event::DiagDataOverlay* diagDataTds = new Event::DiagDataOverlay();

    // Copy over Cal diagnostic info first
    int numCalDiags = diagDataRoot.getNumCalDiagnostic();

    for(int idx = 0; idx < numCalDiags; idx++)
    {
        const CalDiagDataOverlay& calDiagDataRoot = diagDataRoot.getCalDiagnosticByIndex(idx);

        Event::CalDiagDataOverlay cal(calDiagDataRoot.dataWord(), calDiagDataRoot.tower(), calDiagDataRoot.layer());

        diagDataTds->addCalDiagnostic(cal);
    }

    // Now come back and copy the Tkr diagnostic info
    int numTkrDiags = diagDataRoot.getNumTkrDiagnostic();

    for(int idx = 0; idx < numTkrDiags; idx++)
    {
        const TkrDiagDataOverlay& tkrDiagDataRoot = diagDataRoot.getTkrDiagnosticByIndex(idx);

        Event::TkrDiagDataOverlay tkr(tkrDiagDataRoot.dataWord(), tkrDiagDataRoot.tower(), tkrDiagDataRoot.gtcc());

        diagDataTds->addTkrDiagnostic(tkr);
    }

    // Return the pointer to it
    refpObject = diagDataTds;

    return status;
}