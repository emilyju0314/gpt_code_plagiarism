void imageblock_initialize_orig_from_work(
	imageblock* pb,
	int pixelcount
) {
	float *fptr = pb->orig_data;

	for (int i = 0; i < pixelcount; i++)
	{
		if (pb->rgb_lns[i])
		{
			fptr[0] = sf16_to_float(lns_to_sf16((uint16_t)pb->data_r[i]));
			fptr[1] = sf16_to_float(lns_to_sf16((uint16_t)pb->data_g[i]));
			fptr[2] = sf16_to_float(lns_to_sf16((uint16_t)pb->data_b[i]));
		}
		else
		{
			fptr[0] = sf16_to_float(unorm16_to_sf16((uint16_t)pb->data_r[i]));
			fptr[1] = sf16_to_float(unorm16_to_sf16((uint16_t)pb->data_g[i]));
			fptr[2] = sf16_to_float(unorm16_to_sf16((uint16_t)pb->data_b[i]));
		}

		if (pb->alpha_lns[i])
		{
			fptr[3] = sf16_to_float(lns_to_sf16((uint16_t)pb->data_a[i]));
		}
		else
		{
			fptr[3] = sf16_to_float(unorm16_to_sf16((uint16_t)pb->data_a[i]));
		}

		fptr += 4;
	}
}