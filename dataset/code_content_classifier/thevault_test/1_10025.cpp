BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   WindowHandle = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!WindowHandle)
   {
      return FALSE;
   }

   ShowWindow(WindowHandle, nCmdShow);
   UpdateWindow(WindowHandle);
   RECT r;
   GetClientRect(WindowHandle, &r);
   Width = r.right - r.left;
   Height = r.bottom - r.top;
   gRenderer = fb::InitRenderer(fb::RendererType::D3D12, (void*)WindowHandle);

   BuildFrameResources();
   //BuildMaterials_Skull();
   BuildMaterials_Wave();

   gRenderer->ResetCommandList(nullptr, 0);
   std::wcout << L"Reset Command List" << std::endl;

   BuildShapeGeometry();
   BuildTreeSpritesGeometry();

   LoadTextures_Wave();

   BuildShaderResourceView_Wave();

   BuildShadersAndInputLayout();

   BuildWaves();
   BuildLandGeometry();
   BuildWavesGeometryBuffers();

   //BuildRoomGeometry();
   //BuildSkullGeometry();

   //BuildRenderItems_Skull();
   BuildRenderItems_Wave();

   BuildConstantBuffers((int)AllRitems.size(), (int)Materials.size() , 2);
   
   SimpleBoxRootSig = gRenderer->CreateRootSignature("DTable,1,0,CBV");
   CBVRootSig = gRenderer->CreateRootSignature("RootCBV,0;RootCBV,1;");
   // per object, material, per frame, texture
   gRootSignature = gRenderer->CreateRootSignature("RootCBV,0;RootCBV,1;RootCBV,2;DTable,3,0,SRV");

   std::wcout << L"Root sig." << std::endl;

   BuildPSO_Wave();

   std::wcout << L"Build PSO." << std::endl;

   //BuildBoxGeometry();

   gAxisRenderer = new fb::AxisRenderer(gRenderer, 100, 100, 300, 300);
   gAxisRenderer->SetShaders(Shaders["axisVS"], Shaders["axisPS"]);
   
   gRenderer->CloseCommandList();
   gRenderer->ExecuteCommandList();
   gRenderer->SignalFence();
   gRenderer->FlushCommandQueue();
   ProjMat = glm::perspectiveFov(0.25f * glm::pi<float>(), (float)Width, (float)Height, 1.0f, 1000.0f);
   
   return gRenderer != nullptr;
}