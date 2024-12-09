bool twoBitSaturatingCountersPredictor (int * table, int index, char taken) {
    bool correct = 0;
    int state = table[index] % 4;
    if (taken == '1') {
        switch (state) {
            case 0:
            case 1:
                table[index]++;
                break;
            case 2:
                table[index]++;
            case 3:
                correct = 1;
                break;
        }
    } else {
        switch (state) {
            case 0:
                correct = 1;
                break;
            case 1:
                correct = 1;
            case 2:
            case 3:
                table[index]--;
                break;
        }
    }
    return correct;
}