void GxCamera::setExposureGainParam(bool AutoExposure, bool AutoGain, double ExposureTime, double AutoExposureTimeMin, double AutoExposureTimeMax, double Gain, double AutoGainMin, double AutoGainMax, int64_t GrayValue)
{
    exposure_gain.m_bAutoExposure = AutoExposure;
    exposure_gain.m_bAutoGain = AutoGain;
    exposure_gain.m_dExposureTime = ExposureTime;
    exposure_gain.m_dAutoExposureTimeMin = AutoExposureTimeMin;
    exposure_gain.m_dAutoExposureTimeMax = AutoExposureTimeMax;
    exposure_gain.m_dGain = Gain;
    exposure_gain.m_dAutoGainMin = AutoGainMin;
    exposure_gain.m_dAutoGainMax = AutoGainMax;
    exposure_gain.m_i64GrayValue = GrayValue;
}