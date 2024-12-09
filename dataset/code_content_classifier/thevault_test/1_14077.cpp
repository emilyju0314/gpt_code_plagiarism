GeneralizationImpl::GeneralizationImpl(std::weak_ptr<uml::Classifier > par_specific)
:GeneralizationImpl()
{
	m_specific = par_specific;
	m_owner = par_specific;
}