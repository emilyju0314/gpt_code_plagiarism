Event::TkrTrackParams reconRootReaderAlg::convertTkrTrackParams(const TkrTrackParams& paramsRoot)
{
    Event::TkrTrackParams params(paramsRoot.getxPosition(), paramsRoot.getxSlope(), 
        paramsRoot.getyPosition(), paramsRoot.getySlope(),
        paramsRoot.getxPosxPos(),  paramsRoot.getxPosxSlp(), 
        paramsRoot.getxPosyPos(),  paramsRoot.getxPosySlp(),
        paramsRoot.getxSlpxSlp(),  paramsRoot.getxSlpyPos(), 
        paramsRoot.getxSlpySlp(),  paramsRoot.getyPosyPos(), 
        paramsRoot.getyPosySlp(),  paramsRoot.getySlpySlp() );

    return params;
}