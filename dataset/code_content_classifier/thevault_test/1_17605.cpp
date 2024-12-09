void printRect(const CvRect rect, const char *label)
{
	if (label)
		std::cout << label << ": ";
	std::cout << "[Rect] at (" << rect.x << "," << rect.y << ") of size " << rect.width << "x" << rect.height <<
		", where bottom-right corner is at (" << (rect.x + rect.width-1) << "," << (rect.y + rect.height-1) << ")" << std::endl;
}