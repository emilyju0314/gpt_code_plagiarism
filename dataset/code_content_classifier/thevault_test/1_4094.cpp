void inputTwoHugeInts(istream & inFile, int hugeInt1[], int hugeInt2[], int & size1, int & size2) {
    
    char numericString1[arraySize];
    char numericString2[arraySize];
    
    inFile >> numericString1 >> numericString2;
    
    size1 = strlen(numericString1);
    for (int i = 0; i < size1; ++i)
        hugeInt1[i] = numericString1[size1 - i - 1] - '0';
    
    size2 = strlen(numericString2);
    for (int i = 0; i < size2; ++i)
        hugeInt2[i] = numericString2[size2 - i - 1] - '0';
    
}