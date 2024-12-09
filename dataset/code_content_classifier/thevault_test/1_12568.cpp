void parser::parseYAML() {
    std::ifstream inFile;

    inFile.open("input/parameters.yaml", std::ifstream::in);

    YAML::Node yamlNode;
    YAML::Parser parser(inFile);

    parser.GetNextDocument(yamlNode);

    /********** Problem parameters **********/

    yamlNode["Program"]["Problem Type"] >> probType;
    yamlNode["Program"]["Initial Condition"] >> icType;
    yamlNode["Program"]["Domain Type"] >> domainType;
    yamlNode["Program"]["RBC Type"] >> rbcType;

    yamlNode["Program"]["Reynolds Number"] >> Re;
    yamlNode["Program"]["Rossby Number"] >> Ro;
    yamlNode["Program"]["Rayleigh Number"] >> Ra;
    yamlNode["Program"]["Prandtl Number"] >> Pr;
    yamlNode["Program"]["Taylor Number"] >> Ta;

    yamlNode["Program"]["X Length"] >> Lx;
    yamlNode["Program"]["Y Length"] >> Ly;
    yamlNode["Program"]["Z Length"] >> Lz;

    yamlNode["Program"]["Force"] >> forceType;

    yamlNode["Program"]["Heating Plate"] >> nonHgBC;
    yamlNode["Program"]["Plate Radius"] >> patchRadius;

    /********** Mesh parameters **********/

    yamlNode["Mesh"]["Mesh Type"] >> meshType;

    yamlNode["Mesh"]["X Beta"] >> betaX;
    yamlNode["Mesh"]["Y Beta"] >> betaY;
    yamlNode["Mesh"]["Z Beta"] >> betaZ;

    yamlNode["Mesh"]["X Index"] >> xInd;
    yamlNode["Mesh"]["Y Index"] >> yInd;
    yamlNode["Mesh"]["Z Index"] >> zInd;

    /********** Parallelization parameters **********/

    yamlNode["Parallel"]["Number of OMP threads"] >> nThreads;

    yamlNode["Parallel"]["X Number of Procs"] >> npX;
    yamlNode["Parallel"]["Y Number of Procs"] >> npY;

    /********** Solver parameters **********/

    yamlNode["Solver"]["Differentiation Scheme"] >> dScheme;
    yamlNode["Solver"]["Integration Scheme"] >> iScheme;
    yamlNode["Solver"]["Restart Run"] >> restartFlag;

    yamlNode["Solver"]["Use CFL Condition"] >> useCFL;
    yamlNode["Solver"]["Courant Number"] >> courantNumber;
    yamlNode["Solver"]["Time-Step"] >> tStp;
    yamlNode["Solver"]["Final Time"] >> tMax;

    yamlNode["Solver"]["I/O Count"] >> ioCnt;
    yamlNode["Solver"]["Solution Format"] >> solnFormat;
    yamlNode["Solver"]["Solution Write Interval"] >> fwInt;
    yamlNode["Solver"]["Restart Write Interval"] >> rsInt;

    yamlNode["Solver"]["Record Probes"] >> readProbes;
    yamlNode["Solver"]["Probe Time Interval"] >> prInt;
    yamlNode["Solver"]["Probes"] >> probeCoords;

    /********** Multigrid parameters **********/

    yamlNode["Multigrid"]["Jacobi Tolerance"] >> tolerance;
    yamlNode["Multigrid"]["V-Cycle Depth"] >> vcDepth;
    yamlNode["Multigrid"]["V-Cycle Count"] >> vcCount;
    yamlNode["Multigrid"]["Pre-Smoothing Count"] >> preSmooth;
    yamlNode["Multigrid"]["Post-Smoothing Count"] >> postSmooth;
    yamlNode["Multigrid"]["Inter-Smoothing Count"] >> interSmooth;

    inFile.close();
}