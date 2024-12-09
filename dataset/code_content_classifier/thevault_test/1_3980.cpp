bool ReaderPrivate::IsElementLast(const QString& str,
                                  const int& startPos,
                                  const QString& separator,
                                  const QString& txtDelim)
{
    if (str.isEmpty() ||
            startPos < 0 ||
            separator.isEmpty() ||
            txtDelim.isEmpty())
    {
        return false;
    }

    // Check if string ends with text delimiter. If not, then this element
    // do not ends on this line
    if (false == str.endsWith(txtDelim))
    {
        return false;
    }

    // Check that this is really the end symbols of the
    // element and we don't mix up it with double delimiter.
    // Calc number of delimiter symbols from end
    // to startPos that stands together.
    int numOfDelimiters = 0;
    for (int pos = str.size() - 1; startPos <= pos; --pos, ++numOfDelimiters)
    {
        QStringRef strRef = str.midRef(pos, txtDelim.size());
        if (QStringRef::compare(strRef, txtDelim) != 0)
        {
            break;
        }
    }

    // If we have odd number of delimiter symbols that stand together,
    // then this is the even number of double delimiter symbols + last
    // delimiter symbol. That means that this element is the last on the line.
    if (numOfDelimiters % 2 == 1)
    {
        return true;
    }

    return false;
}