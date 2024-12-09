LifelineImpl::LifelineImpl(std::weak_ptr<uml::Interaction > par_interaction)
:LifelineImpl()
{
	m_interaction = par_interaction;
	m_namespace = par_interaction;
}