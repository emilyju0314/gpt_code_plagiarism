std::shared_ptr<Bag<ecore::EStructuralFeature>> EClassImpl::getEAllStructuralFeatures() const
{
	//generated from getterbody annotation
std::shared_ptr< Bag<ecore::EStructuralFeature> > eAllStructuralFeatures( new Bag<ecore::EStructuralFeature> ());

    std::shared_ptr< Bag< EStructuralFeature> > featureList = this->getEStructuralFeatures();
    eAllStructuralFeatures->insert(eAllStructuralFeatures->end(), featureList->begin(), featureList->end());
    std::shared_ptr<Bag<EClass> > classList = this->getESuperTypes();
    for (std::shared_ptr<EClass > c : *classList)
    {
    	std::shared_ptr<Bag<EStructuralFeature> > featureList = c->getEAllStructuralFeatures();
        eAllStructuralFeatures->insert(eAllStructuralFeatures->end(), featureList->begin(), featureList->end());
    }
    return eAllStructuralFeatures;
	//end of body
}