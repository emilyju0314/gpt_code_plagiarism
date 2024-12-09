bool PulseQueue::setPulseRate(int ch, float _f)
{
	if (ch < 1 || ch > n) {
		return false;
	}
	f[ch-1] = _f;
	return true;
}