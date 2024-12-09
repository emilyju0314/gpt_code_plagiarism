string int2roman(int n) {
    string rom;

    string m[] = { "", "M", "MM", "MMM" };
    string c[] = { "", "C", "CC", "CCC", "CD", "D",
                        "DC", "DCC", "DCCC", "CM" };
    string x[] = { "", "X", "XX", "XXX", "XL", "L",
                        "LX", "LXX", "LXXX", "XC" };
    string i[] = { "", "I", "II", "III", "IV", "V",
                        "VI", "VII", "VIII", "IX" };

    string thousands = m[n / 1000];
    string hundereds = c[(n % 1000) / 100];
    string tens = x[(n % 100) / 10];
    string ones = i[n % 10];

    rom = thousands + hundereds + tens + ones;
    return rom;
}