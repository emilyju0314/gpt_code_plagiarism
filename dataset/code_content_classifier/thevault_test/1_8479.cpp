asynStatus NDFileTIFF::writeFile(NDArray *pArray)
{
    unsigned long stripSize;
    tsize_t nwrite=0;
    int strip, sizeY;
    unsigned char *pRed, *pGreen, *pBlue;
    static const char *functionName = "writeFile";

    asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW,
              "%s:%s: %lu, %lu\n", 
              driverName, functionName, (unsigned long)pArray->dims[0].size, (unsigned long)pArray->dims[1].size);

    if (this->output == NULL) {
        asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
        "%s:%s NULL TIFF file\n",
        driverName, functionName);
        return(asynError);
    }

    stripSize = (unsigned long)TIFFStripSize(this->output);
    TIFFGetField(this->output, TIFFTAG_IMAGELENGTH, &sizeY);

    switch (this->colorMode) {
        case NDColorModeMono:
        case NDColorModeRGB1:
            nwrite = TIFFWriteEncodedStrip(this->output, 0, pArray->pData, stripSize); 
            break;
        case NDColorModeRGB2:
            /* TIFF readers don't support row interleave, put all the red strips first, then all the blue, then green. */
            for (strip=0; strip<sizeY; strip++) {
                pRed   = (unsigned char *)pArray->pData + 3*strip*stripSize;
                pGreen = pRed + stripSize;
                pBlue  = pRed + 2*stripSize;
                nwrite = TIFFWriteEncodedStrip(this->output, strip, pRed, stripSize);
                nwrite = TIFFWriteEncodedStrip(this->output, sizeY+strip, pBlue, stripSize);
                nwrite = TIFFWriteEncodedStrip(this->output, 2*sizeY+strip, pGreen, stripSize);
            }
            break;
        case NDColorModeRGB3:
            for (strip=0; strip<3; strip++) {
                nwrite = TIFFWriteEncodedStrip(this->output, strip, (unsigned char *)pArray->pData+stripSize*strip, stripSize);
            }
            break;
        default:
            asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
                "%s:%s: unknown color mode %d\n",
                driverName, functionName, this->colorMode);
            return(asynError);
            break;
    }
    if (nwrite <= 0) {
        asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR, 
            "%s:%s: error writing data to file\n",
            driverName, functionName);
        return(asynError);
    }

    return(asynSuccess);
}