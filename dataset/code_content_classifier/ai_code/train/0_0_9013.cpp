#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("labels.txt");
    std::vector<int> labels;
    
    int label;
    while (inputFile >> label) {
        labels.push_back(label);
    }
    
    inputFile.close();
    
    for (int i = 20; i < 50; i++) {
        int imageId = i + 1;
        std::string filename = std::to_string(imageId) + ".png";
        
        // Assuming you have a function classifyImage(filename) that returns 1 if the image depicts a Fourier doodle and 0 otherwise
        int classification = classifyImage(filename);
        
        std::cout << "Image " << filename << " is classified as: " << classification << std::endl;
    }
    
    return 0;
}