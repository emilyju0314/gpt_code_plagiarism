static void fill_allocation_size_alternative(find_data& FindData, string_view Directory)
	{
		if (FindData.AllocationSize)
			return;

		if (!FindData.FileSize)
			return;

		if (flags::check_any(FindData.Attributes, FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_REPARSE_POINT))
			return;

		static const auto IsWeirdCompressionAvailable = IsWindows10OrGreater();
		if (!IsWeirdCompressionAvailable && !flags::check_any(FindData.Attributes, FILE_ATTRIBUTE_COMPRESSED | FILE_ATTRIBUTE_SPARSE_FILE))
			return;

		// TODO: It's a separate call so we might need an elevation for it
		ULARGE_INTEGER Size;
		Size.LowPart = GetCompressedFileSize(NTPath(path::join(Directory, FindData.FileName)).c_str(), &Size.HighPart);
		if (Size.LowPart == INVALID_FILE_SIZE && GetLastError() != NO_ERROR)
			return;

		FindData.AllocationSize = Size.QuadPart;
	}