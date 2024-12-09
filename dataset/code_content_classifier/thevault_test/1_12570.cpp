void parser::setPeriodicity() {
    xPer = true;
    yPer = true;
    zPer = true;
    xPerInt = 1;
    yPerInt = 1;
    zPerInt = 1;

    if (domainType[0] == 'N') {
        xPer = false;
        xPerInt = 0;
    } 
    if (domainType[1] == 'N') {
        yPer = false;
        yPerInt = 0;
    }
    if (domainType[2] == 'N') {
        zPer = false;
        zPerInt = 0;
    }
}