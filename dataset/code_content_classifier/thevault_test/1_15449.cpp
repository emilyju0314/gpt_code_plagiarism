int convertStringToDecimal(string str, int base){
    int sum = 0;
    int baseVal = 1;//which power the base is raised to. base^0 = 1
    int c;
    if (str.length() > 0){
        for (int i = str.length() - 1; i >= 0; i--){
            c = str.at(i);
            if (c == '\n'){
                break;
            }
            if ((c >= 48) && (c <= 57)){
                c = c - 48;
            } else if ((c >= 65) && (c <= 70)){
                c = c - 55;
            }

            c = (c * (baseVal));
            sum += c;
            baseVal = baseVal * base;//increase the exponent
        }
    }
    return sum;
}