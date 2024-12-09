QString ApplicationUI::copyToData(const QString& path) const {
	QFile sourceFile(path);

	if (sourceFile.open(QFile::ReadOnly)) {
		QByteArray base64Encoded = sourceFile.readAll();
		QByteArray a = base64Encoded.toBase64();
		sourceFile.close();

		// delete original file from the crop tool here
		// - this deleted the 'edit' version of the file picked
		// - prevents duplicate images from being created
		sourceFile.remove();
		return QString(a);
	}
	return QLatin1String("");
}