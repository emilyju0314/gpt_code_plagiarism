void MRDplot::initMRD(int n_channels, int numpoints, m_real freq)
{
	names.resize(n_channels);
	units.resize(n_channels);
	data.resize(numpoints, n_channels);
	setAllUnits("m");
	frequency=freq;
	for(int i=0; i<n_channels; i++)
		names[i].format("channel%d", i);
}