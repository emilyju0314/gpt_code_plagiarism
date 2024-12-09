int designerPdfViewer(vector<int> h, string word) {
    int maxHeight = 0;
    int width = word.size();
    for (int i = 0; i < width; i++) {
        maxHeight = max(maxHeight, h[word[i] - 'a']);
    }
    return maxHeight * width;
}