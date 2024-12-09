void Image::saveImage(const std::string &fileName) {
    std::ofstream f;
    f.open(fileName, std::ios::out | std::ios::binary);
    if (!f.is_open()) {
        std::cout << "The file could not be opened." << std::endl;
        exit(1);
    }

//    padding to add
    unsigned char bmpPad[3] = {0, 0, 0};
//    amount of padding added at the end of each row of pixels
    const int paddingAmount = ((4 - (imageWidth * 3) % 4) % 4);
//    the number of bytes in a row must be divisible by 4
//    imageWidth * 3 -> how many bytes in array
//    imageWidth * 3) % 4 -> how many excess bytes at the end
//    4 - (imageWidth * 3) % 4 -> how many bytes left
//    (4 - (imageWidth * 3) % 4) % 4 -> we cannot have 4 padding amount.

    fileSize = fileHeaderSize + informationHeaderSize + imageWidth * imageHeight * 3 + paddingAmount * imageHeight;

//    initialize the file header
    // file type
    fileHeader[0] = 'B';
    fileHeader[1] = 'M';
    // file size
    fileHeader[2] = fileSize;
    fileHeader[3] = fileSize >> 8;
    fileHeader[4] = fileSize >> 16;
    fileHeader[5] = fileSize >> 24;
    // reserved 1 (not used)
    fileHeader[6] = 0;
    fileHeader[7] = 0;
    // reserved 2 (not used)
    fileHeader[8] = 0;
    fileHeader[9] = 0;
    // pixel data offset
    fileHeader[10] = fileHeaderSize + informationHeaderSize;
    fileHeader[11] = 0;
    fileHeader[12] = 0;
    fileHeader[13] = 0;

//    initialize the information header
    // header size
    informationHeader[0] = informationHeaderSize;
    informationHeader[1] = 0;
    informationHeader[2] = 0;
    informationHeader[3] = 0;
    // image width
    informationHeader[4] = imageWidth;
    informationHeader[5] = imageWidth >> 8;
    informationHeader[6] = imageWidth >> 16;
    informationHeader[7] = imageWidth >> 24;
    // image height
    informationHeader[8] = imageHeight;
    informationHeader[9] = imageHeight >> 8;
    informationHeader[10] = imageHeight >> 16;
    informationHeader[11] = imageHeight >> 24;
    // planes
    informationHeader[12] = 1;
    informationHeader[13] = 0;
    // bits per pixel (rgb)
    informationHeader[14] = 24;
    informationHeader[15] = 0;
    // compression (no compression)
    informationHeader[16] = 0;
    informationHeader[17] = 0;
    informationHeader[18] = 0;
    informationHeader[19] = 0;
    // image size (no compression)
    informationHeader[20] = 0;
    informationHeader[21] = 0;
    informationHeader[22] = 0;
    informationHeader[23] = 0;
    // x pixels per meter (not specified)
    informationHeader[24] = 0;
    informationHeader[25] = 0;
    informationHeader[26] = 0;
    informationHeader[27] = 0;
    // y pixels per meter (not specified)
    informationHeader[28] = 0;
    informationHeader[29] = 0;
    informationHeader[30] = 0;
    informationHeader[31] = 0;
    // total colors (color palette not used)
    informationHeader[32] = 0;
    informationHeader[33] = 0;
    informationHeader[34] = 0;
    informationHeader[35] = 0;
    // important colors (generally ignored)
    informationHeader[32] = 0;
    informationHeader[33] = 0;
    informationHeader[34] = 0;
    informationHeader[35] = 0;

    f.write(reinterpret_cast<char *>(fileHeader), fileHeaderSize);
    f.write(reinterpret_cast<char *>(informationHeader), informationHeaderSize);

//    go through each pixel in the image
    int value; // value to add to each color channel of the pixel
    for (int y = 0; y < imageHeight; ++y) {
        for (int x = 0; x < imageWidth; ++x) {
            if (bitImage[y][x] == 1) value = 0; // black
            else value = 255; // white

            unsigned char color[3]; // create pixel with colors of value (black or white)
            color[0] = value;
            color[1] = value;
            color[2] = value;
            f.write(reinterpret_cast<char *>(color), 3);
        }
        // add padding
        f.write(reinterpret_cast<char *>(bmpPad), paddingAmount);
    }
    f.close();
}