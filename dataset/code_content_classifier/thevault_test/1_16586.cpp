FormDataIODevice::FormDataIODevice(FormData* data)
    : m_formElements(data ? data->elements() : Vector<FormDataElement>())
    , m_currentFile(0)
    , m_currentDelta(0)
    , m_fileSize(0)
    , m_dataSize(0)
{
    setOpenMode(FormDataIODevice::ReadOnly);

    if (!m_formElements.isEmpty() && m_formElements[0].m_type == FormDataElement::encodedFile)
        openFileForCurrentElement();
    computeSize();
}