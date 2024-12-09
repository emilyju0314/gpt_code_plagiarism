static void computeNormalMap(int width, int height, const float* depthData, uint8_t* normalData) {
    #pragma omp parallel for
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Central difference.
            //vec3 leftPoint   = getPoint(x - 1, y, width, height, depthData);
            //vec3 rightPoint  = getPoint(x + 1, y, width, height, depthData);
            //vec3 topPoint    = getPoint(x, y - 1, width, height, depthData);
            //vec3 bottomPoint = getPoint(x, y + 1, width, height, depthData);

            //vec3 dddx = rightPoint - leftPoint;
            //vec3 dddy = bottomPoint - topPoint;
            //vec3 normal = normalize(cross(dddx, dddy));

            // Forward difference (like done in ReShade generic depth plugin).
            vec3 centerPoint = getPoint(x, y, width, height, depthData);
            vec3 rightPoint  = getPoint(x + 1, y, width, height, depthData);
            vec3 topPoint    = getPoint(x, y - 1, width, height, depthData);

            vec3 dddx = rightPoint - centerPoint;
            vec3 dddy = topPoint - centerPoint;
            vec3 normal = normalize(cross(dddy, dddx));

            for (int c = 0; c < 3; c++) {
                normalData[(x + y * width) * 3 + c] = uint8_t(std::round(std::clamp(
                        normal.data[c] * 0.5f + 0.5f, 0.0f, 1.0f) * 255.0f));
            }
        }
    }
}