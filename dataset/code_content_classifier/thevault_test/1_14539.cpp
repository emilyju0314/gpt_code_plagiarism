std::shared_ptr<Bag<ecore::EOperation>> EClassImpl::getEAllOperations() const
{
	//generated from getterbody annotation
std::shared_ptr< Bag<ecore::EOperation> > eAllOperations(new Bag<ecore::EOperation> () );

    std::shared_ptr<Bag<ecore::EOperation> > operationList = this->getEOperations();
    eAllOperations->insert(eAllOperations->end(), operationList->begin(), operationList->end());
    std::shared_ptr<Bag<EClass> > classList = this->getESuperTypes();
    for (std::shared_ptr<EClass > c : *classList)
    {
    	std::shared_ptr< Bag< EOperation> > operationList = c->getEAllOperations();
        eAllOperations->insert(eAllOperations->end(), operationList->begin(), operationList->end());
    }
    return eAllOperations;
	//end of body
}