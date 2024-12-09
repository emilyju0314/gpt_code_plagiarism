static void linearizeDepthBuffer(int width, int height, float* depthData, uint16_t* u16Data) {
    // Linearize the depth data (cf. DisplayDepth.fx from the ReShade shader repository).
    int numPixels = width * height;
    #pragma omp parallel for
    for (int i = 0; i < numPixels; i++) {
        float depthValue = depthData[i];
        if (isDepthLogarithmic) {
            const float C = 0.01f;
            depthValue = (std::exp(depthValue * std::log(C + 1.0f)) - 1.0f) / C;
        }
        if (isDepthReversed) {
            depthValue = 1.0f - depthValue;
        }

        depthValue /= farPlaneDist - depthValue * (farPlaneDist - nearPlaneDist);
        u16Data[i] = uint16_t(std::round(std::clamp(depthValue, 0.0f, 1.0f) * 65535.0f));
        depthData[i] = depthValue;
    }
}