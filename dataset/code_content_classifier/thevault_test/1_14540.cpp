std::shared_ptr<Bag<ecore::EReference>> EClassImpl::getEAllReferences() const
{
	//generated from getterbody annotation
    std::shared_ptr<Bag<ecore::EReference> > eAllReferences(new Bag<ecore::EReference>());

    std::shared_ptr<Bag<ecore::EReference> > referenceList = this->getEReferences();
    eAllReferences->insert(eAllReferences->end(), referenceList->begin(), referenceList->end());
    std::shared_ptr<Bag<EClass> > classList = this->getESuperTypes();
    for (std::shared_ptr<EClass> c : *classList)
    {
        std::shared_ptr<Bag<EReference> > referenceList = c->getEAllReferences();
        eAllReferences->insert(eAllReferences->end(), referenceList->begin(), referenceList->end());
    }
    return eAllReferences;
	//end of body
}