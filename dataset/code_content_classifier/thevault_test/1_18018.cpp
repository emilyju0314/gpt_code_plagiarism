void ProcessRandomLights(XMMATRIX *pViewMatrix, XMMATRIX *pProjectionMatrix)
{
    // Transform point light position from world space to view space
    for (UINT i=0; i<MAX_NUMBER_OF_LIGHTS; i++)
    {
        // Transform point light position from world space to view space
		XMVECTOR pos = XMVectorSet(g_pLightArray[i].vWorldSpacePosition.x, g_pLightArray[i].vWorldSpacePosition.y, 
			g_pLightArray[i].vWorldSpacePosition.z, 1.0f);
        XMVECTOR TransformedVertex = XMVector4Transform(pos, *pViewMatrix);
        g_pLightArray[i].vViewSpacePosition.x = XMVectorGetX(TransformedVertex);
        g_pLightArray[i].vViewSpacePosition.y = XMVectorGetY(TransformedVertex);
        g_pLightArray[i].vViewSpacePosition.z = XMVectorGetZ(TransformedVertex);

        // Calculate 2D screen coordinate extents of sphere
        // This uses a correct method which works even if the camera is close to the sphere
        float zoom[2];
        zoom[0] = XMVectorGetX(pProjectionMatrix->r[0]);
        zoom[1] = XMVectorGetY(pProjectionMatrix->r[1]);
        float minb[2];
        float maxb[2];
        CalcSphereBounds(g_pLightArray[i].vViewSpacePosition, g_pLightArray[i].fRange, zoom, minb, maxb);

        // Write min and max 2D tile coordinates into light array
        g_pLightArray[i].vNDCTile2DCoordinatesMin.x = minb[0];
        g_pLightArray[i].vNDCTile2DCoordinatesMin.y = minb[1];
        
        g_pLightArray[i].vNDCTile2DCoordinatesMax.x = maxb[0];
        g_pLightArray[i].vNDCTile2DCoordinatesMax.y = maxb[1];


        // Transform the point on the sphere closest to the camera to retrieve MinZ
        XMVECTOR vClosest = XMVectorSet(g_pLightArray[i].vViewSpacePosition.x,
                              g_pLightArray[i].vViewSpacePosition.y,
                              g_pLightArray[i].vViewSpacePosition.z - g_pLightArray[i].fRange, 1.0f );
        XMVECTOR vTransformedClosest = XMVector4Transform(vClosest, *pProjectionMatrix);
		vTransformedClosest = vTransformedClosest / XMVectorGetW(vTransformedClosest);

        // Transform the point on the sphere furthest to the camera to retrieve MaxZ
        XMVECTOR vFurthest = XMVectorSet( g_pLightArray[i].vViewSpacePosition.x,
                               g_pLightArray[i].vViewSpacePosition.y,
                               g_pLightArray[i].vViewSpacePosition.z + g_pLightArray[i].fRange, 1.0f );
        XMVECTOR vTransformedFurthest = XMVector4Transform(vFurthest, *pProjectionMatrix);
		vTransformedFurthest = vTransformedFurthest / XMVectorGetW(vTransformedFurthest);

        // Check if sphere intersects the front clip plane
        if ( ( (g_pLightArray[i].vViewSpacePosition.z - g_pLightArray[i].fRange) < FRONT_CLIP_PLANE ) &&
             ( (g_pLightArray[i].vViewSpacePosition.z + g_pLightArray[i].fRange) > FRONT_CLIP_PLANE ) )
        {
            // Closest sphere point is behind clip plane but furthest point is not
            // We therefore need to clamp the closest sphere point
			vTransformedClosest = XMVectorSet(XMVectorGetX(vTransformedClosest), XMVectorGetY(vTransformedClosest),
				XMVectorGetZ(vTransformedClosest), 0.0f);
        }

        // Set min and max in tile coordinates
        g_pLightArray[i].vNDCTile2DCoordinatesMin.z = XMVectorGetZ(vTransformedClosest);
        g_pLightArray[i].vNDCTile2DCoordinatesMax.z = XMVectorGetZ(vTransformedFurthest);
    }
}