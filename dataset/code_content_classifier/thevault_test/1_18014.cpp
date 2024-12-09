bool LightInFrustum(UINT lightIndex)
{
	XMVECTOR center = XMVectorSet(g_pLightArray[lightIndex].vWorldSpacePosition.x, 
						g_pLightArray[lightIndex].vWorldSpacePosition.y,
						g_pLightArray[lightIndex].vWorldSpacePosition.z,
						1.0f);
	float radius = g_pLightArray[lightIndex].fRange;
	float distance;

	for (int i = 0; i < 6; i++)
	{
		XMVECTOR planeEqn = XMVectorSet(g_pWorldSpaceFrustumPlaneEquation[i].x, g_pWorldSpaceFrustumPlaneEquation[i].y,
			g_pWorldSpaceFrustumPlaneEquation[i].z, g_pWorldSpaceFrustumPlaneEquation[i].w);
		XMVECTOR vDistance = XMVector4Dot(center, planeEqn);
		distance = XMVectorGetX(vDistance);
		// see if light is completely behind the frustum plane
		if ( distance < -radius)
			return false;
		// see if the light intersects the plane
		if (fabs(distance) < radius)
			return true;
	}

	// must be inside the frustum
	return true;
}