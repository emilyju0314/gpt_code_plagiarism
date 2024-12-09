Event::TkrTrackHit* reconRootReaderAlg::convertTkrTrackHit(const TkrTrackHit* trackHitRoot)
{
    Event::TkrTrackHit* trackHitTds = new Event::TkrTrackHit();
    commonRootData::TkrId hitId  = trackHitRoot->getTkrId();

    // Fill cluster id only if it exists
    if (const TkrCluster* clusRoot   = trackHitRoot->getClusterPtr())
    {
        const Event::TkrCluster* clusTds = m_common.m_rootTkrClusterMap[clusRoot];
        trackHitTds->setClusterPtr(clusTds);
    }

    if(hitId.hasTowerX()&&hitId.hasTowerY()&&hitId.hasTray()&&hitId.hasBotTop()) {
        if(hitId.hasView()) {
            idents::TkrId hitTdsId(hitId.getTowerX(), hitId.getTowerY(),
                hitId.getTray(), hitId.getBotTop(), hitId.getView());
            trackHitTds->setTkrID(hitTdsId);
        } else { // no view if no cluster
            idents::TkrId hitTdsId(hitId.getTowerX(), hitId.getTowerY(),
                hitId.getTray(), hitId.getBotTop());
            trackHitTds->setTkrID(hitTdsId);
        }
    }
    else {
        idents::TkrId hitTdsId = idents::TkrId();
        trackHitTds->setTkrID(hitTdsId);
    }

    // Fill in the "easy" stuff first 
    trackHitTds->setStatusBit(trackHitRoot->getStatusBits());
    trackHitTds->setZPlane(trackHitRoot->getZPlane());
    trackHitTds->setEnergy(trackHitRoot->getEnergy());
    trackHitTds->setRadLen(trackHitRoot->getRadLen());
    trackHitTds->setActiveDist(trackHitRoot->getActiveDist());
    trackHitTds->setChiSquareFilter(trackHitRoot->getChiSquareFilter());
    trackHitTds->setChiSquareSmooth(trackHitRoot->getChiSquareSmooth());

    // Now set the track params
    if (trackHitRoot->validMeasuredHit()) trackHitTds->getTrackParams(Event::TkrTrackHit::MEASURED) = 
        convertTkrTrackParams(trackHitRoot->getTrackParams(TkrTrackHit::MEASURED));
    if (trackHitTds->validPredictedHit()) trackHitTds->getTrackParams(Event::TkrTrackHit::PREDICTED) = 
        convertTkrTrackParams(trackHitRoot->getTrackParams(TkrTrackHit::PREDICTED));
    if (trackHitTds->validFilteredHit())  trackHitTds->getTrackParams(Event::TkrTrackHit::FILTERED) = 
        convertTkrTrackParams(trackHitRoot->getTrackParams(TkrTrackHit::FILTERED));
    if (trackHitTds->validFilteredHit())  trackHitTds->getTrackParams(Event::TkrTrackHit::REVFIT)   = 
        convertTkrTrackParams(trackHitRoot->getTrackParams(TkrTrackHit::REVFIT)); 
    if (trackHitTds->validSmoothedHit())  trackHitTds->getTrackParams(Event::TkrTrackHit::SMOOTHED) = 
        convertTkrTrackParams(trackHitRoot->getTrackParams(TkrTrackHit::SMOOTHED));
    if (trackHitTds->validRevFit())       trackHitTds->getTrackParams(Event::TkrTrackHit::REVFIT) = 
        convertTkrTrackParams(trackHitRoot->getTrackParams(TkrTrackHit::REVFIT));
    if (trackHitTds->validMaterial())     trackHitTds->getTrackParams(Event::TkrTrackHit::QMATERIAL) = 
        convertTkrTrackParams(trackHitRoot->getTrackParams(TkrTrackHit::QMATERIAL));

    return trackHitTds;
}