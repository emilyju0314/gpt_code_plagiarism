EObjectImpl::EObjectImpl(std::weak_ptr<ecore::EObject > par_eContainer)
:EObjectImpl()
{
	m_eContainer = par_eContainer;
}