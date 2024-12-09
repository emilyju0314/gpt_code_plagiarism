std::pair<std::string, std::vector<double> > imageMoments(std::string filepath)
{

    // Image moments needed for centroid calculation
    int M00 = 0, M10 = 0, M01 = 0;

    // Reading pixel intensities and filling image moments needed for centroid calculation
    int width, height, nrChannels;
    // debug - delete resouces
    std::string proteinID = filepath.substr(10, 20);
    std::cout << filepath.substr(10, 20) << std::endl;
    unsigned char *img = stbi_load(filepath.c_str(), &width, &height, &nrChannels, 1);
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int pixel_intensity = static_cast<int>(img[x + y*width]);
            M00 += pixel_intensity;
            M10 += x * pixel_intensity;
            M01 += y * pixel_intensity;
        }
    }

    // Components of the centroid
    int xc = M10 / M00;
    int yc = M01 / M00;

    // Centralized image moments
    double mu00 = M00;
    double mu11 = 0, mu02 = 0, mu20 = 0, mu12 = 0, mu21 = 0, mu03 = 0, mu30 = 0;

    // Calculating centralized image moments
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int pixel_intensity = static_cast<int>(img[x + y*width]);
            mu11 += (x - xc) * (y - yc) * pixel_intensity;
            mu02 += pow(y - yc, 2) * pixel_intensity;
            mu20 += pow(x - xc, 2) * pixel_intensity;
            mu12 += (x - xc) * pow(y - yc, 2) * pixel_intensity;
            mu21 += pow(x - xc, 2) * (y - yc) * pixel_intensity;
            mu03 += pow(y - yc, 3) * pixel_intensity;
            mu30 += pow(x - xc, 3) * pixel_intensity;
        }
    }

    std::vector<double> imVector = { mu00, 0, 0, mu11, mu02, mu20, mu12, mu21, mu03, mu30 };
    std::pair<std::string, std::vector<double> > vec_representation = std::make_pair(proteinID, imVector);

    // Deallocating resources
    stbi_image_free(img);

    // Debug
    for (int i = 0; i < 10; ++i)
        // std::cout << vec_representation[i] << std::endl;
        return vec_representation;
}