astc_codec_image *astc_codec_load_image(
	const char* input_filename,
	int padding,
	int* load_result
) {
	#define LOAD_HTGA 0
	#define LOAD_KTX 1
	#define LOAD_DDS 2
	#define LOAD_STB_IMAGE 3

	// check the ending of the input filename
	int load_fileformat = LOAD_STB_IMAGE;
	size_t filename_len = strlen(input_filename);

	const char *eptr = input_filename + filename_len - 5;
	if (eptr > input_filename && (strcmp(eptr, ".htga") == 0 || strcmp(eptr, ".HTGA") == 0))
		load_fileformat = LOAD_HTGA;
	eptr = input_filename + filename_len - 4;
	if (eptr > input_filename && (strcmp(eptr, ".ktx") == 0 || strcmp(eptr, ".KTX") == 0))
		load_fileformat = LOAD_KTX;
	if (eptr > input_filename && (strcmp(eptr, ".dds") == 0 || strcmp(eptr, ".DDS") == 0))
		load_fileformat = LOAD_DDS;

	// OpenEXR support: call exr_to_htga to convert from EXR to HTGA.
	char htga_load_filename[300];
	int load_exr = 0;
	if (eptr > input_filename && (strcmp(eptr, ".exr") == 0 || strcmp(eptr, ".EXR") == 0))
	{
		// don't support filenames longer than 250 characters; this way, we
		// cannot get a buffer overflow from the sprintfs below.
		if (filename_len > 250)
		{
			*load_result = -1;
			return nullptr;
		}

		char exr_to_htga_command[550];
		sprintf(htga_load_filename, "%s.htga", input_filename);
		sprintf(exr_to_htga_command, "exr_to_htga -q %s %s", input_filename, htga_load_filename);

		int retval = system(exr_to_htga_command);
		if (retval != 0)
		{
			*load_result = -1;
			printf("Failed to run exr_to_htga to convert input .exr file.\n");
			return nullptr;
		}
		input_filename = htga_load_filename;
		load_fileformat = LOAD_HTGA;
		load_exr = 1;
	}

	astc_codec_image *input_image;

	switch (load_fileformat)
	{
	case LOAD_KTX:
		input_image = load_ktx_uncompressed_image(input_filename, padding, load_result);
		break;
	case LOAD_DDS:
		input_image = load_dds_uncompressed_image(input_filename, padding, load_result);
		break;
	case LOAD_HTGA:
		input_image = load_tga_image(input_filename, padding, load_result);
		break;
	case LOAD_STB_IMAGE:
		input_image = load_image_with_stb(input_filename, padding, load_result);
		break;
	default:
		ASTC_CODEC_INTERNAL_ERROR();
	}

	if (load_exr)
		unlink_file(htga_load_filename);

	return input_image;
}