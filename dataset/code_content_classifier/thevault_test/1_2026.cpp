static void generateSampleRanks(
    uint *ranksA,
    uint *ranksB,
    uint *srcKey,
    uint stride,
    uint N,
    uint sortDir
){
    uint lastSegmentElements = N % (2 * stride);
    uint         sampleCount = (lastSegmentElements > stride) ? (N + 2 * stride - lastSegmentElements) / (2 * SAMPLE_STRIDE) : (N - lastSegmentElements) / (2 * SAMPLE_STRIDE);

    for(uint pos = 0; pos < sampleCount; pos++){
        const uint           i = pos & ( (stride / SAMPLE_STRIDE) - 1 );
        const uint segmentBase = (pos - i) * (2 * SAMPLE_STRIDE);

        const uint lenA = stride;
        const uint lenB = umin(stride, N - segmentBase - stride);
        const uint   nA = stride / SAMPLE_STRIDE;
        const uint   nB = getSampleCount(lenB);

        if(i < nA){
            ranksA[(segmentBase +      0) / SAMPLE_STRIDE + i] = i * SAMPLE_STRIDE;
            ranksB[(segmentBase +      0) / SAMPLE_STRIDE + i] = binarySearchExclusive(srcKey[segmentBase + i * SAMPLE_STRIDE], srcKey + segmentBase + stride, lenB, sortDir);
        }

        if(i < nB){
            ranksB[(segmentBase + stride) / SAMPLE_STRIDE + i] = i * SAMPLE_STRIDE;
            ranksA[(segmentBase + stride) / SAMPLE_STRIDE + i] = binarySearchInclusive(srcKey[segmentBase + stride + i * SAMPLE_STRIDE], srcKey + segmentBase, lenA, sortDir);
        }
    }
}