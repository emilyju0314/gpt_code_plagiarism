int         XPMPModelMatchQuality(const char *              inICAO,
                                  const char *              inAirline,
                                  const char *              inLivery)
{
    CSLModel* pModel;
    return CSLModelMatching(inICAO      ? inICAO : "",
                            inAirline   ? inAirline : "",
                            inLivery    ? inLivery : "",
                            pModel);
}