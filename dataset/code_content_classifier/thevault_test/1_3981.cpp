QList<QStringList> Reader::readToList(const QString& filePath,
                                      const QString& separator,
                                      const QString& textDelimiter,
                                      QTextCodec* codec)
{
    QList<QStringList> data;
    ReaderPrivate::read(filePath, data, separator, textDelimiter, codec);

    return data;
}