#include <iostream>
#include <vector>
#include <algorithm>

// Function to generate all possible original images from a given filtered image
void generateOriginalImages(std::vector<std::string>& originalImages, std::string& filteredImage, int pos) {
    if (pos >= filteredImage.size()) {
        originalImages.push_back(filteredImage);
    } else if (filteredImage[pos] == '.') {
        generateOriginalImages(originalImages, filteredImage, pos + 1);
    } else {
        generateOriginalImages(originalImages, filteredImage, pos + 1);
        filteredImage[pos] = '.';
        generateOriginalImages(originalImages, filteredImage, pos + 1);
        filteredImage[pos] = '#';
    }
}

int countBlackPixels(std::string& image) {
    return std::count(image.begin(), image.end(), '#');
}

int main() {
    int caseNum = 1;
    int W, H;
    
    while (std::cin >> W >> H && (W != 0 || H != 0)) {
        std::vector<std::string> filteredImages(H);
        for (int i = 0; i < H; i++) {
            std::cin >> filteredImages[i];
        }
        
        int minBlackPixels = INT_MAX;
        int maxBlackPixels = 0;
        bool possible = false;
        
        for (const std::string& filteredImage : filteredImages) {
            std::vector<std::string> originalImages;
            generateOriginalImages(originalImages, filteredImage, 0);
            
            for (const std::string& originalImage : originalImages) {
                int blackPixels = countBlackPixels(originalImage);
                minBlackPixels = std::min(minBlackPixels, blackPixels);
                maxBlackPixels = std::max(maxBlackPixels, blackPixels);
                possible = true;
            }
        }
        
        if (possible) {
            std::cout << "Case " << caseNum << ": " << maxBlackPixels - minBlackPixels << std::endl;
        } else {
            std::cout << "Case " << caseNum << ": Impossible" << std::endl;
        }
        
        caseNum++;
    }
    
    return 0;
}