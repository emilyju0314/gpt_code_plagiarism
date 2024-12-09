int8u Aac_k2_Compute(int8u bs_stop_freq, int8u extension_sampling_frequency_index, int8u  k0)
{
    switch (bs_stop_freq)
    {
        case 14 : return (int8u)min(64, 2*k0);
        case 15 : return (int8u)min(64, 3*k0);
        default : ;
    }

    return (int8u)min(64, Aac_k2_stopMin[extension_sampling_frequency_index]+Aac_k2_offset[extension_sampling_frequency_index][bs_stop_freq]);
}