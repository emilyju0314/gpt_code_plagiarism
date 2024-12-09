StatusCode AcdOverlayMergeAlg::execute() 
{
    // Get a message object for output
    MsgStream msglog(msgSvc(), name());

    // First, recover any overlay digis, to see if we have anything to do
    SmartDataPtr<Event::AcdOverlayCol> overlayCol(m_dataSvc, m_dataSvc->rootName() + OverlayEventModel::Overlay::AcdOverlayCol);
    if (!overlayCol) return StatusCode::SUCCESS;

    // The calibration will need the Event Header information for both the sim and the overlay
    SmartDataPtr<Event::McPositionHitCol> mcPosHitCol(eventSvc(), EventModel::MC::McPositionHitCol);
    if (!mcPosHitCol) return StatusCode::SUCCESS;

    // The calibration will need the Event Header information for both the sim and the overlay
    SmartDataPtr<Event::EventHeader> digiHeader(eventSvc(), "/Event");
  
    if (!digiHeader) {
      msglog << MSG::ERROR << "Unable to retrieve event timestamp for digis" << endreq;
      return StatusCode::FAILURE;
    }

    // The calibration will need the Event Header information for both the sim and the overlay
    SmartDataPtr<Event::EventOverlay> overHeader(m_dataSvc, m_dataSvc->rootName() + OverlayEventModel::Overlay::EventOverlay);
  
    if (!overHeader) {
      msglog << MSG::ERROR << "Unable to retrieve event timestamp for overlay" << endreq;
      return StatusCode::FAILURE;
    }

    // Loop through the input digis and using the above map merge with existing MC digis
    for(Event::AcdOverlayCol::iterator overIter  = overlayCol->begin(); overIter != overlayCol->end(); overIter++)
    {
        Event::AcdOverlay* acdOverlay = *overIter;

        // Retrieve the volume identifiers
        const idents::VolumeIdentifier& volumeId = acdOverlay->getVolumeId();
        const idents::AcdId&            acdId    = acdOverlay->getAcdId();

        // Energy deposited
        double energyDep = acdOverlay->getEnergyDep();

        //if threshold is above zero, cut on that value...
        if (m_energyThreshold>0.0 && energyDep < m_energyThreshold) continue;

        // Position
        HepPoint3D position = acdOverlay->getPosition();

        HepPoint3D center;

        // If we have a struck tile go down this path
        if (acdId.tile())
        {
            // Look up the geometry for the tile
            const AcdTileDim* tileDim = m_acdGeoSvc->geomMap().getTile(acdId,*m_acdGeoSvc);

            center = tileDim->tileCenter(0);

            // Work out the entry point
            HepPoint3D entryPoint = tileDim->corner(0)[0];

            for(int idx = 1; idx < 4; idx++) entryPoint += tileDim->corner(0)[idx];

            entryPoint /= 4;

            HepPoint3D locEntryPoint;

            tileDim->toLocal(entryPoint, locEntryPoint, 0);

            HepPoint3D locExitPoint(locEntryPoint.x(), locEntryPoint.y(), locEntryPoint.z() + 0.5);

            HepPoint3D exitPoint = tileDim->transform(0).inverse() * locExitPoint;

            // Irregular shape?
            if (tileDim->nVol() > 1)
            {
                // Work out the exit point
                HepPoint3D exitPoint = tileDim->corner(1)[0];

                for(int idx = 1; idx < 4; idx++) exitPoint += tileDim->corner(1)[idx];

                exitPoint /= 4;

                tileDim->toLocal(exitPoint, locExitPoint, 1);
            }

            // Create a new McPositionHit for this 
            Event::McPositionHit* mcHit = new Event::McPositionHit();

            // Initalize
            mcHit->init(energyDep, 
                        volumeId, 
                        locEntryPoint, 
                        locExitPoint, 
                        entryPoint, 
                        exitPoint, 
                        Event::McPositionHit::overlayHit);

            // Since this is from overlay, add the acdOverlay status mask to the packed flags
            mcHit->addPackedMask(acdOverlay->getStatus() | Event::AcdDigi::DIGI_OVERLAY);

            mcPosHitCol->push_back(mcHit);
        }

    }

    return StatusCode::SUCCESS;
}