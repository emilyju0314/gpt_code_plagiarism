bool CWretch::CreateBehaviors( void )
{
	AddBehavior( &m_PassengerBehavior );

	return BaseClass::CreateBehaviors();
}