bool UILayout::setScreenSize(UINT16 width, UINT16 height)
{
	if((width >= MIN_INTERFACE_WIDTH) && (height >= MIN_INTERFACE_HEIGHT))
	{
		m_screenWidth = width;
		m_screenHeight = height;
		recalculatePositions();
		return true;
	}
	return false;
}