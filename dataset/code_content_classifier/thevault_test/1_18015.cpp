void SetDepthBoundsFromLightRadius(UINT i, XMVECTOR *pViewVec, XMMATRIX *pViewProjection)
{
	XMVECTOR center = XMVectorSet(g_pLightArray[i].vWorldSpacePosition.x, g_pLightArray[i].vWorldSpacePosition.y, g_pLightArray[i].vWorldSpacePosition.z, 1.0);
	XMVECTOR pos, radiusVec;
	XMVECTOR tfmNear, tfmFar;

	// scale the view vector by the radius
	radiusVec = *pViewVec * g_pLightArray[i].fRange;

	// calculate the near z
	pos = center + radiusVec;
	pos = XMVectorSet(XMVectorGetX(pos), XMVectorGetY(pos), XMVectorGetZ(pos), 1.0f);

	// project the near coordinate into screen space
	tfmNear = XMVector4Transform(pos, *pViewProjection);
	float nearBound = XMVectorGetZ(tfmNear) / XMVectorGetW(tfmNear);

	// calculate the far z
	pos = center - radiusVec;
	pos = XMVectorSet(XMVectorGetX(pos), XMVectorGetY(pos), XMVectorGetZ(pos), 1.0f);

	// project the far coordinate into screen space
	tfmFar =  XMVector4Transform(pos, *pViewProjection);
	float farBound =  XMVectorGetZ(tfmFar) / XMVectorGetW(tfmFar);

	// clip values outside the frustum
	nearBound = CLIP(nearBound);
	farBound = CLIP(farBound);

	// set the depth bounds based on the near and far z of the light
	agsDriverExtensionsDX11_SetDepthBounds( g_pAGSContext, true, nearBound, farBound );
}