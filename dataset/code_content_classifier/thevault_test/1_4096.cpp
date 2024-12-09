bool equal(int hugeInt1[], int hugeInt2[], int size1, int size2) {
    
    if (size1 != size2) {
        return false;
    }
    else if (size1 == size2) {
        for (int i = 0; i < size1; i++) {
            if (hugeInt1[i] != hugeInt2[i]) {
                return false;
            }
        }
    }
    return true;
    
}