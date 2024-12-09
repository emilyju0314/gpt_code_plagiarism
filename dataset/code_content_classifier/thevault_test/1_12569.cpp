void parser::checkData() {
    int gridSize, localSize, coarsestSize;

    // CHECK IF THE yInd VARIABLE IS SET CORRECTLY FOR A 2D/3D SIMULATION
#ifdef PLANAR
    if (yInd != 0) {
        std::cout << "WARNING: Y Index parameter of YAML file is non-zero although solver has been compiled with PLANAR flag. Setting Y Index to 0" << std::endl;
        yInd = 0;
    }
#else
    if (yInd == 0) {
        std::cout << "ERROR: Y Index parameter of YAML file is 0 for 3D simulation. ABORTING" << std::endl;
        MPI_Finalize();
        exit(0);
    }
#endif

    // CHECK IF LESS THAN 1 PROCESSOR IS ASKED FOR ALONG X-DIRECTION. IF SO, WARN AND SET IT TO DEFAULT VALUE OF 1
    if (npX < 1) {
        std::cout << "WARNING: Number of processors in X-direction is less than 1. Setting it to 1" << std::endl;
        npX = 1;
    }

    // CHECK IF LESS THAN 1 PROCESSOR IS ASKED FOR ALONG Y-DIRECTION. IF SO, WARN AND SET IT TO DEFAULT VALUE OF 1
    if (npY < 1) {
        std::cout << "WARNING: Number of processors in Y-direction is less than 1. Setting it to 1" << std::endl;
        npY = 1;
    }

    // CHECK IF DOMAIN TYPE STRING IS OF CORRECT LENGTH
    if (domainType.length() != 3) {
        std::cout << "ERROR: Domain type string is not correct. Aborting" << std::endl;
        MPI_Finalize();
        exit(0);
    }

    // CHECK IF MESH TYPE STRING IS OF CORRECT LENGTH
    if (meshType.length() != 3) {
        std::cout << "ERROR: Mesh type string is not correct. Aborting" << std::endl;
        MPI_Finalize();
        exit(0);
    }

    // CHECK IF THE TIME-STEP SET BY USER IS LESS THAN THE MAXIMUM TIME SPECIFIED FOR SIMULATION.
    if (tStp > tMax) {
        std::cout << "ERROR: Time step is larger than the maximum duration assigned for simulation. Aborting" << std::endl;
        MPI_Finalize();
        exit(0);
    }

    // CHECK IF MORE THAN 1 PROCESSOR IS ASKED FOR ALONG Y-DIRECTION FOR A 2D SIMULATION
    if (yInd == 0 and npY > 1) {
        std::cout << "ERROR: More than 1 processor is specified along Y-direction, but the yInd parameter is set to 0. Aborting" << std::endl;
        MPI_Finalize();
        exit(0);
    }

    // CHECK IF THE LENGTH OF ARRAY interSmooth IS LESS THAN vcDepth and equal to 5
    // THE SIZE OF interSmooth IS CONVERTED TO int TO AVOID -Wsign-compare WARNING
    // SIZE OF THIS ARRAY CAN NEVER BE TOO LARGE FOR THIS CONVERSION TO CAUSE ANY PROBLEMS ANYWAY
    if (int(interSmooth.size()) < vcDepth) {
        std::cout << "ERROR: The length of array of inter-smoothing counts is less than V-Cycle depths. Aborting" << std::endl;
        MPI_Finalize();
        exit(0);
    }

    if (int(interSmooth.size()) != 5) {
        std::cout << "ERROR: The length of array of inter-smoothing counts is not eual to 5.Aborting" << std::endl;
        MPI_Finalize();
        exit(0);
    }

    // CHECK IF GRID SIZE SPECIFIED ALONG EACH DIRECTION IS SUFFICIENT ALONG WITH THE DOMAIN DIVIIONS TO REACH THE LOWEST LEVEL OF V-CYCLE DEPTH SPECIFIED
    // ALONG X-DIRECTION
    gridSize = int(pow(2, xInd));
    localSize = gridSize/npX;
    coarsestSize = int(pow(2, vcDepth+1));
    if (localSize < coarsestSize) {
        std::cout << "ERROR: The grid size and domain decomposition along X-direction results in sub-domains too coarse to reach the V-Cycle depth specified. Aborting" << std::endl;
        MPI_Finalize();
        exit(0);
    }

    // ALONG Y-DIRECTION
#ifndef PLANAR
    gridSize = int(pow(2, yInd));
    localSize = gridSize/npY;
    coarsestSize = int(pow(2, vcDepth+1));
    if (yInd > 0 and localSize < coarsestSize) {
        std::cout << "ERROR: The grid size and domain decomposition along Y-direction results in sub-domains too coarse to reach the V-Cycle depth specified. Aborting" << std::endl;
        MPI_Finalize();
        exit(0);
    }
#endif

    // ALONG Z-DIRECTION
    gridSize = int(pow(2, zInd));
    coarsestSize = int(pow(2, vcDepth+1));
    if (gridSize < coarsestSize) {
        std::cout << "ERROR: The grid size along Z-direction is too coarse to reach the V-Cycle depth specified. Aborting" << std::endl;
        MPI_Finalize();
        exit(0);
    }

#ifdef REAL_SINGLE
    if (tolerance < 5.0e-6) {
        std::cout << "ERROR: The specified tolerance for Jacobi iterations is too small for single precision calculations. Aborting" << std::endl;
        MPI_Finalize();
        exit(0);
    }
#endif
}