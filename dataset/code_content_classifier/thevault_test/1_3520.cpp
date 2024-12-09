void CPhysicsObject::SetLocalGravity(const btVector3 &gravityVector)
{
    //m_pObject->setFlags( BT_DISABLE_WORLD_GRAVITY );
    m_pObject->setGravity( gravityVector );
}