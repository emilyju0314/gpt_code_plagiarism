void GxCamera::setRoiParam(int64_t Width, int64_t Height, int64_t OffsetX, int64_t OffsetY)
{
    roi.m_i64Width = Width;
    roi.m_i64Height = Height;
    roi.m_i64OffsetX = OffsetX;
    roi.m_i64OffsetY = OffsetY;
}