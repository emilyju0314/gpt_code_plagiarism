SignalEventImpl::SignalEventImpl(std::weak_ptr<uml::Package > par_owningPackage)
:SignalEventImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}