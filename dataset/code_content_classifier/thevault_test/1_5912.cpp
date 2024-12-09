DUPL_RETURN DXFrameProcessor::ProcessFrame(const Monitor &currentmonitorinfo)
    {
        Microsoft::WRL::ComPtr<IDXGIResource> DesktopResource;
        DXGI_OUTDUPL_FRAME_INFO FrameInfo = {0};
        AquireFrameRAII frame(OutputDuplication.Get());

        // Get new frame
        auto hr = frame.AcquireNextFrame(100, &FrameInfo, DesktopResource.GetAddressOf());
        if (hr == DXGI_ERROR_WAIT_TIMEOUT) {
            return DUPL_RETURN_SUCCESS;
        }
        else if (FAILED(hr)) {
            return ProcessFailure(Device.Get(), L"Failed to acquire next frame in DUPLICATIONMANAGER", L"Error", hr, FrameInfoExpectedErrors);
        }
        if (FrameInfo.AccumulatedFrames == 0) {
            return DUPL_RETURN_SUCCESS;
        }

        Microsoft::WRL::ComPtr<ID3D11Texture2D> aquireddesktopimage;
        // QI for IDXGIResource
        hr = DesktopResource.Get()->QueryInterface(__uuidof(ID3D11Texture2D), reinterpret_cast<void **>(aquireddesktopimage.GetAddressOf()));
        if (FAILED(hr)) {
            return ProcessFailure(nullptr, L"Failed to QI for ID3D11Texture2D from acquired IDXGIResource in DUPLICATIONMANAGER", L"Error", hr);
        }





		if (!CursorSurf || !StagingSurf) {
            D3D11_TEXTURE2D_DESC ThisDesc = {0};
            aquireddesktopimage->GetDesc(&ThisDesc);

			if (!CursorSurf) {
                D3D11_TEXTURE2D_DESC CursorDesc;
                CursorDesc = ThisDesc;
                CursorDesc.ArraySize = 1;
                CursorDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_RENDER_TARGET;
                CursorDesc.MiscFlags = D3D11_RESOURCE_MISC_GDI_COMPATIBLE;
                CursorDesc.SampleDesc.Count = 1;
                CursorDesc.SampleDesc.Quality = 0;
                CursorDesc.MipLevels = 1;
                CursorDesc.CPUAccessFlags = 0;
                CursorDesc.Usage = D3D11_USAGE_DEFAULT;
                CursorDesc.Height = Height(SelectedMonitor);
                CursorDesc.Width = Width(SelectedMonitor);

                hr = Device->CreateTexture2D(&CursorDesc, nullptr, CursorSurf.GetAddressOf());
                if (FAILED(hr)) {
                    return ProcessFailure(Device.Get(), L"Failed to create cursor texture for mouse pointer GDI operations", L"Error", hr,
                                          SystemTransitionsExpectedErrors);
                }
			}

			if (!StagingSurf) {
                D3D11_TEXTURE2D_DESC StagingDesc;
                StagingDesc = ThisDesc;
                StagingDesc.BindFlags = 0;
                StagingDesc.Usage = D3D11_USAGE_STAGING;
                StagingDesc.CPUAccessFlags = D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE;
                StagingDesc.MiscFlags = 0;
                StagingDesc.Height = Height(SelectedMonitor);
                StagingDesc.Width = Width(SelectedMonitor);

                hr = Device->CreateTexture2D(&StagingDesc, nullptr, StagingSurf.GetAddressOf());
                if (FAILED(hr)) {
                    return ProcessFailure(Device.Get(), L"Failed to create staging texture for move rects", L"Error", hr,
                                            SystemTransitionsExpectedErrors);
                }
            }
		}


        if (Width(currentmonitorinfo) == Width(SelectedMonitor) && Height(currentmonitorinfo) == Height(SelectedMonitor)) {
			// we first copy the acquired image into our cursor surface so that we can perform GDI operations on it
            DeviceContext->CopyResource(CursorSurf.Get(), aquireddesktopimage.Get());

			// setup a DC for the surface
			Microsoft::WRL::ComPtr<IDXGISurface1> surface;
            auto hr = CursorSurf->QueryInterface(__uuidof(IDXGISurface1), reinterpret_cast<void **>(surface.GetAddressOf()));

            if (SUCCEEDED(hr)) {
                HDC surfaceDC;
                surface->GetDC(FALSE, &surfaceDC);

    			// draw the cursor using this DC
                CursorHelpers::DrawCursor(surfaceDC, SelectedMonitor.OffsetX, SelectedMonitor.OffsetY);

    			// release
                surface->ReleaseDC(NULL);
            }

			// copy the composed image into staging surface to be mapped out
            DeviceContext->CopyResource(StagingSurf.Get(), CursorSurf.Get());
        }
        else {
            D3D11_BOX sourceRegion;
            sourceRegion.left = OffsetX(SelectedMonitor) - OutputDesc.DesktopCoordinates.left;
            sourceRegion.right = sourceRegion.left + Width(SelectedMonitor);
            sourceRegion.top = OffsetY(SelectedMonitor) + OutputDesc.DesktopCoordinates.top;
            sourceRegion.bottom = sourceRegion.top + Height(SelectedMonitor);
            sourceRegion.front = 0;
            sourceRegion.back = 1;
            DeviceContext->CopySubresourceRegion(StagingSurf.Get(), 0, 0, 0, 0, aquireddesktopimage.Get(), 0, &sourceRegion);
        }

        D3D11_MAPPED_SUBRESOURCE MappingDesc = {0};
        MAPPED_SUBRESOURCERAII mappedresrouce(DeviceContext.Get());
        hr = mappedresrouce.Map(StagingSurf.Get(), 0, D3D11_MAP_READ, 0, &MappingDesc);
        // Get the data
        if (MappingDesc.pData == NULL) {
            return ProcessFailure(Device.Get(),
                                  L"DrawSurface_GetPixelColor: Could not read the pixel color because the mapped subresource returned NULL", L"Error",
                                  hr, SystemTransitionsExpectedErrors);
        }
        auto startsrc = reinterpret_cast<unsigned char *>(MappingDesc.pData);
        ProcessCapture(Data->ScreenCaptureData, *this, SelectedMonitor, startsrc, MappingDesc.RowPitch);
        return DUPL_RETURN_SUCCESS;
    }