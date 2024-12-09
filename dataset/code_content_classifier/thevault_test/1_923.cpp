bool isPalindrome(string word) {
    for (int i = 0; i < (int)word.length() / 2; ++i) {
        if (tolower(word[i]) != tolower(word[((int)word.length() - 1) - i])) {
            return false;
        }
    }
    return true;
}