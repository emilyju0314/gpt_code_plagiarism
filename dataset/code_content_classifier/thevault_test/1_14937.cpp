void SGPVObject::DestroyPalettes()
{
	FOR_EACH(UINT16*, i, pShades)
	{
		if (flags_ & SHADETABLE_SHARED) continue;
		UINT16* const p = *i;
		if (!p)                         continue;
		if (palette16_ == p) palette16_ = 0;
		*i = 0;
		delete[] p;
	}

	if (UINT16* const p = palette16_)
	{
		palette16_ = 0;
		delete[] p;
	}

	current_shade_ = 0;
}