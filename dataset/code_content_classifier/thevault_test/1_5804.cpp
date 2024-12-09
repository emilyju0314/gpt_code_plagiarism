void CSpectralSampleData::interpolate(std::vector<double> const & t_Wavelengths)
    {
        m_Transmittances = m_Transmittances->interpolate(t_Wavelengths);
        m_ReflectancesFront = m_ReflectancesFront->interpolate(t_Wavelengths);
        m_ReflectancesBack = m_ReflectancesBack->interpolate(t_Wavelengths);
        m_AbsorptancesFront = m_AbsorptancesFront->interpolate(t_Wavelengths);
        m_AbsorptancesBack = m_AbsorptancesBack->interpolate(t_Wavelengths);
    }