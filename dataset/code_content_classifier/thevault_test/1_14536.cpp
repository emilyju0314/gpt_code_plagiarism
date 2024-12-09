std::shared_ptr<Bag<ecore::EAttribute>> EClassImpl::getEAllAttributes() const
{
	//generated from getterbody annotation
    std::shared_ptr<Bag<ecore::EAttribute> > eAllAttributes(new Bag<ecore::EAttribute>());

    std::shared_ptr<Bag<ecore::EAttribute> > attributeList = this->getEAttributes();
    eAllAttributes->insert(eAllAttributes->end(), attributeList->begin(), attributeList->end());
    std::shared_ptr<Bag<EClass> > classList = this->getESuperTypes();
    for (std::shared_ptr<EClass> c : *classList)
    {
        std::shared_ptr<Bag<EAttribute> > attributeList = c->getEAllAttributes();
        eAllAttributes->insert(eAllAttributes->end(), attributeList->begin(), attributeList->end());
    }
    return eAllAttributes;
	//end of body
}