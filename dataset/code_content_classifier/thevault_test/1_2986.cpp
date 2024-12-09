uint8_t TccCcNum(uint8_t tccNum) {
    uint8_t tccCcNum;
    switch (tccNum) {
        case 0:
            tccCcNum = TCC0_CC_NUM;
            break;
        case 1:
            tccCcNum = TCC1_CC_NUM;
            break;
        case 2:
            tccCcNum = TCC2_CC_NUM;
            break;
        case 3:
            tccCcNum = TCC3_CC_NUM;
            break;
        case 4:
            tccCcNum = TCC4_CC_NUM;
            break;
        default:
            tccCcNum = 0;
            break;
    }
    return tccCcNum;
}