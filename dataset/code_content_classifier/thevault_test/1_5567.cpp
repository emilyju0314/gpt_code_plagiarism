void AbstractWindow::update()
{
	if (!aValidatedContents)
	{
		validate();
	}

	render();
}