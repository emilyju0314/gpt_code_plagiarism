void GridSlice::invalidate(void) {
		m_type = SliceType::Invalid;
		// should only do with 0 duration slices, but force to 0 if not already.
		setDuration(0);
}