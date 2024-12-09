HRESULT CampaignIdHelper::GetCampaignIdFromStoreContextWithWait( HSTRING *presultCampaignId)
{
	 
	ComPtr<ABI::Windows::Services::Store::IStoreContextStatics> storeContextStatics;
	HRESULT hr = RoGetActivationFactory(HStringReference(RuntimeClass_Windows_Services_Store_StoreContext).Get(), __uuidof(storeContextStatics), &storeContextStatics);
	ReturnIfFailedHresult(hr);

	ComPtr<ABI::Windows::Services::Store::IStoreContext> storeContext;
    hr = storeContextStatics->GetDefault(&storeContext);
	 
	if (SUCCEEDED(hr) && storeContext != nullptr)
	{
		Event asyncFinished(CreateEventEx(NULL, NULL, CREATE_EVENT_MANUAL_RESET, EVENT_ALL_ACCESS));
		ComPtr<IAsyncOperation<ABI::Windows::Services::Store::StoreProductResult*>> asyncOperation;

		hr = storeContext->GetStoreProductForCurrentAppAsync(&asyncOperation);

		if (SUCCEEDED(hr))
		{
			 
			auto callback = Microsoft::WRL::Callback<Implements<RuntimeClassFlags<ClassicCom>, IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreProductResult*>, FtmBase>>(
				[&](IAsyncOperation<ABI::Windows::Services::Store::StoreProductResult*>* operation, AsyncStatus status)
			{
				if (status == AsyncStatus::Completed)
				{
					ComPtr<ABI::Windows::Services::Store::IStoreProductResult> storeProductResult;
					hr = operation->GetResults(&storeProductResult);
					if (SUCCEEDED(hr) && storeProductResult != nullptr )
					{
						ComPtr<ABI::Windows::Services::Store::IStoreProduct> storeProduct;
						hr = storeProductResult->get_Product(&storeProduct);
						// &storeProduct returns null on sideloaded apps ... 
						if (SUCCEEDED(hr) && storeProduct != nullptr )
						{

							ABI::Windows::Foundation::Collections::IVectorView<ABI::Windows::Services::Store::StoreSku*>* pSKUs;
							hr = storeProduct->get_Skus(&pSKUs);
							if (SUCCEEDED(hr) && pSKUs != nullptr  )
							{
								unsigned int totalSkus = 0;
								hr = pSKUs->get_Size(&totalSkus);								 
								for (unsigned int itemIndex = 0; itemIndex < totalSkus; itemIndex++)
								{									 
									boolean isInUserCollection = false;
									ComPtr<ABI::Windows::Services::Store::IStoreSku> sku;
									pSKUs->GetAt(itemIndex, &sku);
									sku->get_IsInUserCollection(&isInUserCollection);
									if (isInUserCollection)
									{
										ComPtr < ABI::Windows::Services::Store::IStoreCollectionData> collectionData;
										hr = sku->get_CollectionData(&collectionData);
										if (SUCCEEDED(hr) && collectionData != nullptr )
										{ 
											hr = collectionData->get_CampaignId( presultCampaignId );
											if (SUCCEEDED(hr))
											{ 
													break;
											}
										}

									}
								}
								 
							}
						}
					}
				}
				else
				{
					hr = E_FAIL;
					RoOriginateError(hr, HStringReference(L"GetStoreProductForCurrentAppAsync failed").Get());
				} 
 
				SetEvent(asyncFinished.Get());
				return S_OK;

			});
			asyncOperation->put_Completed(callback.Get());
			 
			DWORD waitResult = WaitForSingleObjectEx(asyncFinished.Get(), NetworkRequestTimeOutMills, false);


			if (waitResult != WAIT_OBJECT_0 )
			{
				hr = E_FAIL;  
				RoOriginateError(hr, HStringReference(L"GetStoreProductForCurrentAppAsync timed out").Get());
			}
		}
	}
	return hr;
}