bool isSpecial(char a){
    //We convert the character to lower to avoid having unnecessary if conditions
    a = tolower(a);
    if(a==97 || a==101 || a==105 || a==111 || a==117) {
        return true;
    }
    return false;
}