void GenerateRandomLights(XMFLOAT3* pReferencePoint, XMFLOAT3* pMaxExtents, float fMaxRange, float fMaxIntensity)
{
    srand(g_uRandomSeed);
    for (UINT i=0; i<MAX_NUMBER_OF_LIGHTS; i++)
    {
        g_pLightArray[i].vWorldSpacePosition.x = FLOAT_RANDOM( pMaxExtents->x ) + pReferencePoint->x;
        g_pLightArray[i].vWorldSpacePosition.y = FLOAT_RANDOM( pMaxExtents->y ) + pReferencePoint->y;
        g_pLightArray[i].vWorldSpacePosition.z = FLOAT_RANDOM( pMaxExtents->z ) + pReferencePoint->z;
        g_pLightArray[i].fRange = FLOAT_POSITIVE_RANDOM( fMaxRange );
		float r = FLOAT_POSITIVE_RANDOM( fMaxIntensity );
		float g = FLOAT_POSITIVE_RANDOM( fMaxIntensity );
		float b = FLOAT_POSITIVE_RANDOM( fMaxIntensity );
		g_pLightArray[i].vColor = XMVectorSet(r, g, b, 1.0f);
    }
}