std::shared_ptr<Bag<ecore::EClass>> EClassImpl::getEAllSuperTypes() const
{
	//generated from getterbody annotation
std::shared_ptr< Bag<ecore::EClass> > eAllSuperTypes(new Bag<ecore::EClass>  ());

	std::shared_ptr<Bag<EClass> > classList = this->getESuperTypes();
    eAllSuperTypes->insert(eAllSuperTypes->end(), classList->begin(), classList->end());
    for (std::shared_ptr<EClass > c : *classList)
    {
    	std::shared_ptr<Bag<EClass> > classList = c->getEAllSuperTypes();
        eAllSuperTypes->insert(eAllSuperTypes->end(), classList->begin(), classList->end());
    }
    return eAllSuperTypes;
	//end of body
}