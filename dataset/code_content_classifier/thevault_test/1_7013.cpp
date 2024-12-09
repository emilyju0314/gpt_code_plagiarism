void Renderer::drawScreenPixels(const ScreenPixels& pixels)
{
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, &pixels[0]);

	glDrawPixels(pixels.width(), pixels.height(), GL_RGBA, GL_UNSIGNED_BYTE, &pixels[0]);
}