int GetExportedFunctionNamesFromAddress(ulonglong PeHeader,uchar* Address,uchar** pNamesOut)
{
	ulong cNamesOut = 0;

	if(PeHeader)
	{
		_IMAGE_DOS_HEADER* pDos = (_IMAGE_DOS_HEADER*)PeHeader;

		ulong rva_nt = pDos->e_lfanew;

		_IMAGE_NT_HEADERS64* pNT64 = (_IMAGE_NT_HEADERS64*)(PeHeader + rva_nt);

		ulong rva_export = pNT64->OptionalHeader.DataDirectory[0].VirtualAddress;
		ulong sz_export  = pNT64->OptionalHeader.DataDirectory[0].Size;

		_IMAGE_EXPORT_DIRECTORY* pExport = (_IMAGE_EXPORT_DIRECTORY*)(PeHeader + rva_export);


		ulong NumFunctions = pExport->NumberOfFunctions;
		ulong NumNames = pExport->NumberOfNames;
		ulong BaseX = pExport->Base;
		printf("Base: %X\r\n",BaseX);

		ulong rva_AddressOfFunctions = pExport->AddressOfFunctions;
		ulong* pAddressOfFunctions = (ulong*)(PeHeader + rva_AddressOfFunctions);

		ulong rva_AddressOfNames = pExport->AddressOfNames;
		ulong* pAddressOfNames = (ulong*)(PeHeader + rva_AddressOfNames);

		ulong rva_AddressOfNameOrdinals = pExport->AddressOfNameOrdinals;
		ushort* pAddressOfNameOrdinals = (ushort*)(PeHeader + rva_AddressOfNameOrdinals);



		ulong rva = ((ulonglong)Address) - (PeHeader);

		for(ulong i=0;i<NumFunctions;i++)
		{
			if(pAddressOfFunctions[i] == rva)
			{
				for(ulong z=0;z<NumNames;z++)
				{
					if( pAddressOfNameOrdinals[z] == i)
					{
						uchar* ExportedName = (uchar*)( PeHeader + pAddressOfNames[z] );
						printf("%s\r\n",ExportedName);
						pNamesOut[cNamesOut] = ExportedName;
						cNamesOut++;
					}
				}
			}
		}

		return 0;
	}
	return -1;
}