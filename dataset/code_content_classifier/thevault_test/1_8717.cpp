void imageblock_initialize_work_from_orig(
	imageblock* pb,
	int pixelcount
) {
	float *fptr = pb->orig_data;

	for (int i = 0; i < pixelcount; i++)
	{
		if (pb->rgb_lns[i])
		{
			pb->data_r[i] = float_to_lns(fptr[0]);
			pb->data_g[i] = float_to_lns(fptr[1]);
			pb->data_b[i] = float_to_lns(fptr[2]);
		}
		else
		{
			pb->data_r[i] = fptr[0] * 65535.0f;
			pb->data_g[i] = fptr[1] * 65535.0f;
			pb->data_b[i] = fptr[2] * 65535.0f;
		}

		if (pb->alpha_lns[i])
		{
			pb->data_a[i] = float_to_lns(fptr[3]);
		}
		else
		{
			pb->data_a[i] = fptr[3] * 65535.0f;
		}

		fptr += 4;
	}
}