HRESULT AddShadersToCache()
{
    HRESULT hr = E_FAIL;

     // G-Buffer Layout
    const D3D11_INPUT_ELEMENT_DESC meshvertexlayout[] =
    {
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,    0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

	// G-buffer building shaders
    g_ShaderCache.AddShader( (ID3D11DeviceChild**)&g_pBuildingPass_StoreVS, AMD::ShaderCache::SHADER_TYPE_VERTEX, L"vs_5_0", L"VS_FillGBuffers",
        L"BuildGBuffers.hlsl", 0, NULL, &g_pMeshLayout, meshvertexlayout, ARRAYSIZE( meshvertexlayout ) );

    g_ShaderCache.AddShader( (ID3D11DeviceChild**)&g_pBuildingPass_StorePS, AMD::ShaderCache::SHADER_TYPE_PIXEL, L"ps_5_0", L"PS_FillGBuffers",
        L"BuildGBuffers.hlsl", 0, NULL, NULL, NULL, 0 );


    // Quad input layout
    const D3D11_INPUT_ELEMENT_DESC quadvertexlayout[] =
    {
        { "NDCPOSITION",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

	// Shading pass shaders
    g_ShaderCache.AddShader( (ID3D11DeviceChild**)&g_pShadingPass_FullscreenQuadVS, AMD::ShaderCache::SHADER_TYPE_VERTEX, L"vs_5_0", L"VS_FullScreenQuad",
        L"ShadingPasses.hlsl", 0, NULL, &g_pFSQuadVertexLayout, quadvertexlayout, ARRAYSIZE( quadvertexlayout ) );

    g_ShaderCache.AddShader( (ID3D11DeviceChild**)&g_pShadingPass_FullscreenLightPS, AMD::ShaderCache::SHADER_TYPE_PIXEL, L"ps_5_0", L"PS_FullscreenLight",
        L"ShadingPasses.hlsl", 0, NULL, NULL, NULL, 0 );

    g_ShaderCache.AddShader( (ID3D11DeviceChild**)&g_pShadingPass_PointLightFromTileVS, AMD::ShaderCache::SHADER_TYPE_VERTEX, L"vs_5_0", L"VS_PointLightFromTile",
        L"ShadingPasses.hlsl", 0, NULL, &g_pQuadVertexLayout, quadvertexlayout, ARRAYSIZE( quadvertexlayout ) );

    g_ShaderCache.AddShader( (ID3D11DeviceChild**)&g_pShadingPass_PointLightFromTilePS, AMD::ShaderCache::SHADER_TYPE_PIXEL, L"ps_5_0", L"PS_PointLight",
        L"ShadingPasses.hlsl", 0, NULL, NULL, NULL, 0 );

    // Particle input layout
    const D3D11_INPUT_ELEMENT_DESC particlevertexlayout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,    0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "RADIUS",   0, DXGI_FORMAT_R32_FLOAT,          0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

	// Particle rendering shader
    g_ShaderCache.AddShader( (ID3D11DeviceChild**)&g_pParticleVS, AMD::ShaderCache::SHADER_TYPE_VERTEX, L"vs_5_0", L"VSPassThrough",
        L"Particle.hlsl", 0, NULL, &g_pParticleVertexLayout, particlevertexlayout, ARRAYSIZE( particlevertexlayout ) );

    g_ShaderCache.AddShader( (ID3D11DeviceChild**)&g_pParticleGS, AMD::ShaderCache::SHADER_TYPE_GEOMETRY, L"gs_5_0", L"GSPointSprite",
        L"Particle.hlsl", 0, NULL, NULL, NULL, 0 );

	g_ShaderCache.AddShader( (ID3D11DeviceChild**)&g_pParticlePS, AMD::ShaderCache::SHADER_TYPE_PIXEL, L"ps_5_0", L"PSConstantColor",
        L"Particle.hlsl", 0, NULL, NULL, NULL, 0 );


	return hr;
}