void Algorithm::updateMap(){
    switch(currDir){
        case 0: // east
            tremauxMap[currX][currY][1] = openF;
            tremauxMap[currX][currY][2] = openL;
            tremauxMap[currX][currY][3] = 1;
            tremauxMap[currX][currY][4] = openR;
            break;
        case 1: // north
            tremauxMap[currX][currY][1] = openR;
            tremauxMap[currX][currY][2] = openF;
            tremauxMap[currX][currY][3] = openL;
            tremauxMap[currX][currY][4] = 1;
            break;
        case 2: // west
            tremauxMap[currX][currY][1] = 1;
            tremauxMap[currX][currY][2] = openR;
            tremauxMap[currX][currY][3] = openF;
            tremauxMap[currX][currY][4] = openL;
            break;
        case 3: // south
            tremauxMap[currX][currY][1] = openL;
            tremauxMap[currX][currY][2] = 1;
            tremauxMap[currX][currY][3] = openR;
            tremauxMap[currX][currY][4] = openF;
            break;
        default:
            cout << "Algorithm::updateMap(): Invalid restricted heading - " << currDir << endl;
            break;
    }
}