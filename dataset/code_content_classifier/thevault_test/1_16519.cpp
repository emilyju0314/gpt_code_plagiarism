void DocumentWriter::replaceDocument(const String& source)
{
    m_frame->loader()->stopAllLoaders();
    begin(m_frame->document()->url(), true, m_frame->document()->securityOrigin());

    if (!source.isNull()) {
        if (!m_receivedData) {
            m_receivedData = true;
            m_frame->document()->setCompatibilityMode(Document::NoQuirksMode);
        }

        // FIXME: This should call DocumentParser::appendBytes instead of append
        // to support RawDataDocumentParsers.
        if (DocumentParser* parser = m_frame->document()->parser())
            parser->append(source);
    }

    end();
}