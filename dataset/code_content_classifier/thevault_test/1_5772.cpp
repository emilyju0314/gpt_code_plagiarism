void ms2::Spectrum::labelSpectrum(PeptideNamespace::Peptide& peptide,
                                  const base::ParamsBase& pars,
                                  bool removeUnlabeledFrags, size_t labelTop)
{
    initLabeledIons();
    plotWidth = pars.getPlotWidth();
    plotHeight = pars.getPlotHeight();
    size_t len = peptide.getNumFragments();
    size_t labledCount = 0;
    double _labelTolerance;
    bool seqPrinted = false;

    typedef std::list<ms2::DataPoint*> listType;
    listType rangeList;
    listType::iterator label;

    setLabelTop(labelTop); //determine which labeledIons are abundant enough to considered in labeling
    std::sort(_dataPoints.begin(), _dataPoints.end(), DataPoint::MZComparison()); //sort labeledIons by mz
    if(pars.getMZSpecified()) //set user specified mz range if specified
    {
        setMZRange(pars.getMinMZSpecified() ? pars.getMinMZ() : getMaxMZ(),
                   pars.getMaxMZSpecified() ? pars.getMaxMZ() : getMaxMZ(),
                   false);
    }
    // apply snr filter
    if(pars.getMinSNRSpecified())
        removeSNRBelow(pars.getMinSnr(), pars.getSNRConf());

    //iterate through all calculated fragment ions and label ions on spectrum if they are found
    for(size_t i = 0; i < len; i++)
    {
        double tempMZ = peptide.getFragmentMZ(i);

        rangeList.clear();

        //first get lowest value in range
        _labelTolerance = pars.getMatchTolerance(tempMZ);
        auto lowerBound = std::lower_bound(_dataPoints.begin(), _dataPoints.end(),
                                           (tempMZ - (_labelTolerance)),
                                           DataPoint::MZComparison());

        //ittreate throughout all labeledIons above in range
        for(auto it = lowerBound; it != _dataPoints.end(); ++it)
        {
            if(it->getMZ() > (tempMZ + _labelTolerance))
                break;

            if(it->getTopAbundant()){
                //check that it->mz is in range
                bool inRange = utils::inRange(it->getMZ(), tempMZ, _labelTolerance);
                if(inRange)
                    rangeList.push_back(&(*it));
            }//end of if
        }
        //else continue;

        if(rangeList.empty())
            continue;

        label = rangeList.begin();
        if(rangeList.size() > 1)
        {
            //iterate through all ions within matchTolerance range to get the one with max intensity
            double tempMax = (*label)->getIntensity();
            double tempMZdiff = abs((*label)->getMZ() - tempMZ);
            for(auto it = rangeList.begin(); it != rangeList.end(); ++it)
            {
                if(pars.getMultipleMatchCompare() == "intensity" || pars.getMultipleMatchCompare() == "int"){
                    if((*it)->getIntensity() > tempMax)
                    {
                        label = it;
                        tempMax = (*label)->getIntensity();
                    }
                }
                else if(pars.getMultipleMatchCompare() == "mz"){
                    if(((*it)->getMZ() - tempMZ) < tempMZdiff)
                    {
                        label = it;
                        tempMZdiff = abs((*label)->getMZ() - tempMZ);
                    }
                }
                else{
                    throw std::runtime_error("Unknown multipleMatchCompare method!");
                }
            }
        }

        if((*label)->getLabeledIon() && pars.getVerbose()){
            if(!seqPrinted){
                std::cout << "In sequence: " << peptide.getFullSequence() << NEW_LINE;
                seqPrinted = true;
            }
            std::cout << "\tDuplicate label found: " << (*label)->getLabel() << ", " <<
                      peptide.getFragmentLabel(i) << NEW_LINE;
        }

        //if label is not already labeled or if peptide.getFragment(i) is not a NL
        if(!(*label)->getLabeledIon() || peptide.getFragment(i).isNL())
        {
            if(peptide.getIncludeLabel(i)) //only label spectrum if fragment should be labeled.
            {
                (*label)->setLabel(peptide.getFragmentLabel(i));
                (*label)->setFormatedLabel(peptide.getFormatedLabel(i));
                (*label)->setLabeledIon(true);
                (*label)->label.setIncludeLabel(true);
                (*label)->setIonType(peptide.getFragment(i).getIonType());
                (*label)->setIonNum(peptide.getFragment(i).getNum());
                labledCount++;
            }
        }
        peptide.setFound(i, true);
        peptide.setFoundMZ(i, (*label)->getMZ());
        peptide.setFoundIntensity(i, (*label)->getIntensity());
    }//end of for
    ionPercent = (double(labledCount) / double(len)) * 100;

    //remove unlabeled ions if necessary
    if(!pars.getIncludeAllIons())
        removeUnlabeledIons();

    //remove unlabeled peptide fragments
    //only used for debugging
    if(removeUnlabeledFrags)
        peptide.removeUnlabeledFrags();

}