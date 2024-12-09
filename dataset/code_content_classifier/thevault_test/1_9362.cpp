HRESULT CheckImports
(
    LPWSTR              DriverPath,
    LPSTR               ModuleNameToCheck,
    LPSTR               MethodNameToCheck,
    bool*               pIsImported
)
{
    HRESULT hr = S_OK;

    *pIsImported = FALSE;

    CHAR szDriverPath[MAX_PATH];
    size_t bytesConverted = 0;
    if (!VERIFY_IS_TRUE(0 == wcstombs_s(&bytesConverted, szDriverPath, MAX_PATH, DriverPath, _TRUNCATE)))
    {
        hr = E_FAIL;
        return hr;
    }

    LOADED_IMAGE image;
    //Load the image
    if (!VERIFY_IS_TRUE(MapAndLoad(szDriverPath, NULL, &image, TRUE, TRUE)))
    {
        hr = HRESULT_FROM_WIN32(GetLastError());
        return hr;
    }

    auto imageCleanup = wil::scope_exit([&]()
    {
        (VOID)UnMapAndLoad(&image);
    });

    //Get the Import Directory
    ULONG importDescriptorSize;
    PIMAGE_SECTION_HEADER sectionHeader;
    PIMAGE_IMPORT_DESCRIPTOR importDescriptor = (PIMAGE_IMPORT_DESCRIPTOR)ImageDirectoryEntryToDataEx(image.MappedAddress,
        FALSE,
        IMAGE_DIRECTORY_ENTRY_IMPORT,
        &importDescriptorSize,
        &sectionHeader);
    if (!VERIFY_IS_NOT_NULL(importDescriptor))
    {
        hr = HRESULT_FROM_WIN32(GetLastError());
        return hr;
    }

    //Iterate through each directory entry
    while (!(importDescriptor->Characteristics == 0 &&
        importDescriptor->TimeDateStamp == 0 &&
        importDescriptor->ForwarderChain == 0 &&
        importDescriptor->Name == 0 &&
        importDescriptor->FirstThunk == 0))
    {
        CHAR* str = (PCHAR)ImageRvaToVa(ImageNtHeader(image.MappedAddress),
            image.MappedAddress,
            importDescriptor->Name,
            NULL);
        if (!str || !*str)
        {
            continue;
        }

        if (_stricmp(str, ModuleNameToCheck) == 0)
        {
            // If a specific method name is provided, check for the specific method
            if (MethodNameToCheck)
            {
                PIMAGE_THUNK_DATA thunk;
                //Iterate through the INT(Import Name Table)
                if (importDescriptor->OriginalFirstThunk == 0)
                {
                    thunk = nullptr;
                }
                else
                {
                    thunk = (PIMAGE_THUNK_DATA)ImageRvaToVa(ImageNtHeader(image.MappedAddress),
                        image.MappedAddress,
                        importDescriptor->OriginalFirstThunk,
                        NULL);
                }

                while (thunk && thunk->u1.Ordinal != 0)
                {
                    if (!IMAGE_SNAP_BY_ORDINAL(thunk->u1.Ordinal))
                    {
                        PIMAGE_IMPORT_BY_NAME importName = (PIMAGE_IMPORT_BY_NAME)ImageRvaToVa(ImageNtHeader(image.MappedAddress),
                            image.MappedAddress,
                            (ULONG)thunk->u1.ForwarderString,
                            NULL);
                        if (importName && _stricmp(importName->Name, MethodNameToCheck) == 0)
                        {
                            *pIsImported = TRUE;
                        }
                    }

                    thunk++;
                }
            }
            else
            {
                *pIsImported = TRUE;
            }
            
            break;
        }

        importDescriptor++;
    }

    return hr;

}