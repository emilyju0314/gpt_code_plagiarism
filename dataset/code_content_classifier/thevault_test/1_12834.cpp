size_t IRrecv::compensateAndStorePronto(String *aString, unsigned int frequency) {

    size_t size = 0;
    unsigned int timebase = toTimebase(frequency);

    size += dumpNumber(aString, frequency > 0 ? learnedToken : learnedNonModulatedToken);
    size += dumpNumber(aString, toFrequencyCode(frequency));
    size += dumpNumber(aString, (decodedIRData.rawDataPtr->rawlen + 1) / 2);
    size += dumpNumber(aString, 0);
    size += compensateAndDumpSequence(aString, &decodedIRData.rawDataPtr->rawbuf[1], decodedIRData.rawDataPtr->rawlen - 1,
            timebase); // skip leading space

    return size;
}