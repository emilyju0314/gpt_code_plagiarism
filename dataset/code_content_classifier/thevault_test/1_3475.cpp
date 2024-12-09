void Algorithm::mvJunct() {
    int rotation = 0;
    bool hasRotated = false;

    // first check if there is a priority among tremaux
    int lowestSide = 0; //front
    int lowestVal = 99;
    int front, left, right;
    switch(currDir){
        case 0: // east
            front = tremauxMap[currX + 1][currY][0];
            left = tremauxMap[currX][currY - 1][0];
            right = tremauxMap[currX][currY + 1][0];

            if(openF)                       // front
                lowestVal = front;
            if(right < lowestVal && openR){ // right
                lowestSide = 2;
                lowestVal = right;
            }
            if(left < lowestVal && openL){  // left
                lowestSide = 1;
                lowestVal = left;
            }
            if(lowestSide == 0){
                hasRotated = false;
            }
            else if(lowestSide == 1){
                rotation = 90;
                hasRotated = true;
            }else if(lowestSide == 2){
                rotation = -90;
                hasRotated = true;
            }else{
                cout << "Algorithm::mvJunct(): invalid lowest side error." << endl;
            }
            break;
        case 1: // north
            front = tremauxMap[currX][currY - 1][0];
            left = tremauxMap[currX - 1][currY][0];
            right = tremauxMap[currX + 1][currY][0];

            if(openF)                       // front
                lowestVal = front;
            if(right < lowestVal && openR){ // right
                lowestSide = 2;
                lowestVal = right;
            }
            if(left < lowestVal && openL){  // left
                lowestSide = 1;
                lowestVal = left;
            }
            if(lowestSide == 0){
                hasRotated = false;
            }
            else if(lowestSide == 1){
                rotation = 90;
                hasRotated = true;
            }else if(lowestSide == 2){
                rotation = -90;
                hasRotated = true;
            }else{
                cout << "Algorithm::mvJunct(): invalid lowest side error." << endl;
            }
            break;
        case 2: // west
            front = tremauxMap[currX - 1][currY][0];
            left = tremauxMap[currX][currY + 1][0];
            right = tremauxMap[currX][currY - 1][0];

            if(openF)                       // front
                lowestVal = front;
            if(right < lowestVal && openR){ // right
                lowestSide = 2;
                lowestVal = right;
            }
            if(left < lowestVal && openL){  // left
                lowestSide = 1;
                lowestVal = left;
            }
            if(lowestSide == 0){
                hasRotated = false;
            }
            else if(lowestSide == 1){
                rotation = 90;
                hasRotated = true;
            }else if(lowestSide == 2){
                rotation = -90;
                hasRotated = true;
            }else{
                cout << "Algorithm::mvJunct(): invalid lowest side error." << endl;
            }
            break;
        case 3: // south
            front = tremauxMap[currX][currY + 1][0];
            left = tremauxMap[currX + 1][currY][0];
            right = tremauxMap[currX - 1][currY][0];

            if(openF)                       // front
                lowestVal = front;
            if(right < lowestVal && openR){ // right
                lowestSide = 2;
                lowestVal = right;
            }
            if(left < lowestVal && openL){  // left
                lowestSide = 1;
                lowestVal = left;
            }
            if(lowestSide == 0){
                hasRotated = false;
            }
            else if(lowestSide == 1){
                rotation = 90;
                hasRotated = true;
            }else if(lowestSide == 2){
                rotation = -90;
                hasRotated = true;
            }else{
                cout << "Algorithm::mvJunct(): invalid lowest side error." << endl;
            }
            break;
        default:
            cout << "Algorithm::myJunct(): invalid currDir" << endl;
    }

    if(hasRotated){
        out[0] = 2;
        out[1] = rotation;
    }else{
        out[0] = 0;
        out[1] = 1;
    }
}