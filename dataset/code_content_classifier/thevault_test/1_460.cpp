void ApplicationUI::invokePhotoViewer(const QString& path) const {
	InvokeManager invokeManager;
	InvokeRequest request;

	request.setTarget("sys.pictures.card.previewer");
	request.setAction("bb.action.VIEW");
	request.setMimeType("image/png");
	request.setUri(QUrl(path));
	invokeManager.invoke(request);
}