void packRGBA8ToRGBA8Unmultiply(const uint8_t* source, uint8_t* destination)
{
    float scaleFactor = 1.0f / (source[3] ? source[3] / 255.0f : 1.0f);
    uint8_t sourceR = static_cast<uint8_t>(static_cast<float>(source[0]) * scaleFactor);
    uint8_t sourceG = static_cast<uint8_t>(static_cast<float>(source[1]) * scaleFactor);
    uint8_t sourceB = static_cast<uint8_t>(static_cast<float>(source[2]) * scaleFactor);
    destination[0] = sourceR;
    destination[1] = sourceG;
    destination[2] = sourceB;
    destination[3] = source[3];
}