void IRrecv::compensateAndPrintIRResultAsPronto(Print *aSerial, unsigned int aFrequencyHertz) {
    aSerial->println(F("Pronto Hex as string"));
    aSerial->print(F("char prontoData[] = \""));
    dumpNumber(aSerial, aFrequencyHertz > 0 ? learnedToken : learnedNonModulatedToken);
    dumpNumber(aSerial, toFrequencyCode(aFrequencyHertz));
    dumpNumber(aSerial, (decodedIRData.rawDataPtr->rawlen + 1) / 2);
    dumpNumber(aSerial, 0);
    unsigned int timebase = toTimebase(aFrequencyHertz);
    compensateAndDumpSequence(aSerial, &decodedIRData.rawDataPtr->rawbuf[1], decodedIRData.rawDataPtr->rawlen - 1, timebase); // skip leading space
    aSerial->println("\";");
}