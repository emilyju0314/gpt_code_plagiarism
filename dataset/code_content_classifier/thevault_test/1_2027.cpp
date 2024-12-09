static void mergeRanksAndIndices(
    uint *limits,
    uint *ranks,
    uint stride,
    uint N
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
            uint dstPosA = binarySearchExclusive(ranks[(segmentBase + 0) / SAMPLE_STRIDE + i], ranks + (segmentBase + stride) / SAMPLE_STRIDE, nB, 1) + i;
            assert( dstPosA < nA + nB );
            limits[(segmentBase / SAMPLE_STRIDE) + dstPosA] = ranks[(segmentBase + 0) / SAMPLE_STRIDE + i];
        }

        if(i < nB){
            uint dstPosA = binarySearchInclusive(ranks[(segmentBase + stride) / SAMPLE_STRIDE + i], ranks + (segmentBase + 0) / SAMPLE_STRIDE, nA, 1) + i;
            assert( dstPosA < nA + nB );
            limits[(segmentBase / SAMPLE_STRIDE) + dstPosA] = ranks[(segmentBase + stride) / SAMPLE_STRIDE + i];
        }
    }
}