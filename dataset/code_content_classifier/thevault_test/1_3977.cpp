bool ReaderPrivate::read(const QString& filePath,
                            QList<QStringList>& list,
                            const QString& separator,
                            const QString& textDelimiter,
                            QTextCodec* codec)
{
    if ( false == checkParams(filePath, separator) )
    {
        return false;
    }

    QFile csvFile(filePath);
    if ( false == csvFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        qDebug() << __FUNCTION__ << "Error - can't open file:" << filePath;
        return false;
    }

    QTextStream stream(&csvFile);
    stream.setCodec(codec);

    // This list will contain elements of the row if its elements
    // are located on several lines
    QStringList row;

    ElementInfo elemInfo;
    while ( false == stream.atEnd() )
    {
        QString line = stream.readLine();
        QStringList elements = ReaderPrivate::splitElements(
                  line, separator, textDelimiter, elemInfo);
        if (elemInfo.isEnded)
        {
            // Current row ends on this line. Check if these elements are
            // end elements of the long row
            if (row.isEmpty())
            {
                // No, these elements constitute the entire row
                list << elements;
            }
            else
            {
                // Yes, these elements should be added to the row
                if (false == elements.isEmpty())
                {
                    row.last().append(elements.takeFirst());
                    row << elements;
                }

                list << row;
                row.clear();
            }
        }
        else
        {
            // These elements constitute long row that lasts on several lines
            if (false == elements.isEmpty())
            {
                if (false == row.isEmpty())
                {
                    row.last().append(elements.takeFirst());
                }

                row << elements;
            }
        }
    }

    csvFile.close();

    if (false == elemInfo.isEnded && false == row.isEmpty())
    {
        list << row;
    }

    return true;
}