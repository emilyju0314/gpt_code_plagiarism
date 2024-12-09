void Algorithm::mvCorr() {
    if(openF){  // dead end, has rotated, move forward.
        out[0] = 0;
        out[1] = 1;
    }else if(openL || openR){   // corner, left or right is open.
        if(openL){  // rotate left
            out[0] = 2;
            out[1] = 90;
        }else{  // rotate right
            out[0] = 2;
            out[1] = -90;
        }
    }else{
        cout << "Algorithm::mvCorr(): Invalid boolean set " << openL << "|" << openF << "|" << openR << endl;
    }
}