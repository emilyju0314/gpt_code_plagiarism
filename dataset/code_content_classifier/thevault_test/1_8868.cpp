QPoint ShellWidget::neovimCursorTopLeft() const noexcept
{
	const QSize cSize{ cellSize() };
	const int xPixels{ m_cursor_pos.x() * cSize.width() };
	const int yPixels{ m_cursor_pos.y() * cSize.height() };

	return { xPixels, yPixels };
}