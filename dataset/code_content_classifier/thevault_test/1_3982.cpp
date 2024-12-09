bool Reader::readToData(const QString& filePath,
                        AbstractData& data,
                        const QString& separator,
                        const QString& textDelimiter,
                        QTextCodec* codec)
{
    QList<QStringList> list;
    if (false == ReaderPrivate::read(filePath, list, separator, textDelimiter,
                                     codec))
    {
        return false;
    }

    for (int i = 0; i < list.size(); ++i)
    {
        data.addRow( list.at(i) );
    }

    return true;
}