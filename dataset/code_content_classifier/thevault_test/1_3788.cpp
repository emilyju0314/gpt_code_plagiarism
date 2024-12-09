void CPhysicsObject::RestoreShadowController( IPhysicsShadowController *pShadowController )
{
	Assert( !m_pShadow );
	m_pShadow = pShadowController;
}