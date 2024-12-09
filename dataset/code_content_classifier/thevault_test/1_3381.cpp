XMLCh* DOMLSSerializerImpl::writeToString(const DOMNode* nodeToWrite, MemoryManager* manager /*= NULL*/)
{
    if(manager==NULL)
        manager = fMemoryManager;
    MemBufFormatTarget  destination(1023, manager);
    bool retVal;

    bool bBOMFlag=getFeature(BYTE_ORDER_MARK_ID);
    setFeature(BYTE_ORDER_MARK_ID, false);
    try
    {
        DOMLSOutputImpl output(manager);
        output.setByteStream(&destination);
        output.setEncoding(XMLUni::fgUTF16EncodingString);
        retVal = write(nodeToWrite, &output);
    }
    catch(const OutOfMemoryException&)
    {
        throw;
    }
    catch (...)
    {
        //
        // there is a possibility that memory allocation
        // exception thrown in XMLBuffer class
        //
        setFeature(BYTE_ORDER_MARK_ID, bBOMFlag);
        return 0;
    }

    setFeature(BYTE_ORDER_MARK_ID, bBOMFlag);
    return (retVal ? XMLString::replicate((XMLCh*) destination.getRawBuffer(), manager) : 0);
}