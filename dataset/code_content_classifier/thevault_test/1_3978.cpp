bool ReaderPrivate::checkParams(const QString& filePath,
                                const QString& separator)
{
    if ( separator.isEmpty() )
    {
        qDebug() << __FUNCTION__ << "Error - separator could not be empty";
        return false;
    }

    if ( filePath.isEmpty() )
    {
        qDebug() << __FUNCTION__ << "Error - file path is empty";
        return false;
    }

    if ( false == CheckFile(filePath, true) )
    {
        qDebug() << __FUNCTION__ << "Error - wrong file path:" << filePath;
        return false;
    }

    return true;
}