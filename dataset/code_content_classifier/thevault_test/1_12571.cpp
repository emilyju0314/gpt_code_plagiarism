void parser::setInitVars() {
    initVarInt.resize(21);
    initVarReal.resize(7);

    initVarInt(0) = xInd;
    initVarInt(1) = yInd;
    initVarInt(2) = zInd;
    initVarInt(3) = xGrid;
    initVarInt(4) = yGrid;
    initVarInt(5) = zGrid;
    initVarInt(6) = npX;
    initVarInt(7) = npY;
    initVarInt(8) = nThreads;
    initVarInt(9) = xPerInt;
    initVarInt(10) = yPerInt;
    initVarInt(11) = zPerInt;
    initVarInt(12) = vcDepth;
    initVarInt(13) = vcCount;
    initVarInt(14) = preSmooth;
    initVarInt(15) = postSmooth;
    initVarInt(16) = interSmooth[0];
    initVarInt(17) = interSmooth[1];
    initVarInt(18) = interSmooth[2];
    initVarInt(19) = interSmooth[3];
    initVarInt(20) = interSmooth[4];

    initVarReal(0) = Lx;
    initVarReal(1) = Ly;
    initVarReal(2) = Lz;
    initVarReal(3) = betaX;
    initVarReal(4) = betaY;
    initVarReal(5) = betaZ;
    initVarReal(6) = tolerance;
    }