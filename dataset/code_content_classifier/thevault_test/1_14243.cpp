ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::Activity > par_Activity, const int reference_id)
:ExpansionRegionImpl()
{
	switch(reference_id)
	{	
	case umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		m_activity = par_Activity;
		m_owner = par_Activity;
		 return;
	case umlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		m_inActivity = par_Activity;
		m_owner = par_Activity;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}