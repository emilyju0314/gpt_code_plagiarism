void progressBar(bool horizontal, Framebuffer::PointF base, Framebuffer::PointF extent, Color fg, Color bg, float completion) {
	PointF progress = horizontal ? PointF(extent.x * completion, extent.y) : PointF(extent.x, extent.y * completion);

	display::fillRect(Framebuffer::Type::foreground, base, base + progress, fg);
	display::fillRect(Framebuffer::Type::foreground, base + progress, base + extent, bg);
}