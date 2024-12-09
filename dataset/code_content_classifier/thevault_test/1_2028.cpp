static void merge(
    uint *dstKey,
    uint *dstVal,
    uint *srcAKey,
    uint *srcAVal,
    uint *srcBKey,
    uint *srcBVal,
    uint lenA,
    uint lenB,
    uint sortDir
){
    checkOrder(srcAKey, lenA, sortDir);
    checkOrder(srcBKey, lenB, sortDir);

    for(uint i = 0; i < lenA; i++){
        uint dstPos = binarySearchExclusive(srcAKey[i], srcBKey, lenB, sortDir) + i;
        assert( dstPos < lenA + lenB );
        dstKey[dstPos] = srcAKey[i];
        dstVal[dstPos] = srcAVal[i];
    }

    for(uint i = 0; i < lenB; i++){
        uint dstPos = binarySearchInclusive(srcBKey[i], srcAKey, lenA, sortDir) + i;
        assert( dstPos < lenA + lenB );
        dstKey[dstPos] = srcBKey[i];
        dstVal[dstPos] = srcBVal[i];
    }
}