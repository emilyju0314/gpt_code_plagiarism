HRESULT	CDRGObject::Update(float	fTimeStep, bool bUpdateChildren)
{
	//update the object's current rotation angle scale and position
	m_fRotationAngle += m_fRotationalVelocity * fTimeStep;
	m_vScale += m_vScalingVelocity * fTimeStep;
	m_vPosition += m_vVelocity * fTimeStep;	

	//update the local to world matrix (start with the base matrix)
	m_MxLocalToParent = m_MxLocalBase;
		
	m_MxLocalToParent.Translate(m_vPosition.x, m_vPosition.y, m_vPosition.z );
	m_MxLocalToParent.Scale(m_vScale.x, m_vScale.y, m_vScale.z);
	m_MxLocalToParent.Rotate(m_vRotationAxis, m_fRotationAngle);

	if (bUpdateChildren)
	{
		CDRGObject	*pTempObject = m_pFirstChild;
		while (pTempObject != NULL)
		{
			pTempObject->Update(fTimeStep, true);
			pTempObject = pTempObject->m_pNext;
		}
	}
		
	return S_OK;
}