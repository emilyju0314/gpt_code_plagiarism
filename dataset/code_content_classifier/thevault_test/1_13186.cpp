StatusCode AcdOverlayMergeAlg::initialize() 
{
    StatusCode sc = StatusCode::SUCCESS;
  
    MsgStream log(msgSvc(), name());
    log << MSG::INFO << "initialize" << endreq;

    sc = setProperties();
    if (sc.isFailure()) {
        log << MSG::ERROR << "Could not set jobOptions properties" << endreq;
        return sc;
    }
    
    // try to find the GlastDetSvc service
    sc = service("GlastDetSvc", m_detSvc);
    if (sc.isFailure() ) {
        log << MSG::ERROR << "  can't get GlastDetSvc " << endreq;
        return sc;
    }

    IService* iService = 0;
    sc = serviceLocator()->service("AcdGeometrySvc", iService, true);
    if (sc.isSuccess() ) 
    {
        sc = iService->queryInterface(IID_IAcdGeometrySvc, (void**)&m_acdGeoSvc);
    }

    if (sc.isFailure()) 
    {
        log << MSG::ERROR << "Failed to get the AcdGeometerySvc" << endreq;
        return sc;
    }

    // Convention for multiple input overlay files is that there will be separate OverlayDataSvc's with 
    // names appended by "_xx", for example OverlayDataSvc_1 for the second input file. 
    // In order to ensure the data read in goes into a unique section of the TDS we need to modify the 
    // base root path, which we do by examining the name of the service
    std::string dataSvcName = "OverlayDataSvc";
    int         subPos      = name().rfind("_");
    std::string nameEnding  = subPos > 0 ? name().substr(subPos, name().length() - subPos) : "";

    if (nameEnding != "") dataSvcName += nameEnding;

    IService* dataSvc = 0;
    sc = service(dataSvcName, dataSvc);
    if (sc.isFailure() ) {
        log << MSG::ERROR << "  can't get OverlayDataSvc " << endreq;
        return sc;
    }

    // Caste back to the "correct" pointer
    m_dataSvc = dynamic_cast<DataSvc*>(dataSvc);

    return sc;
}