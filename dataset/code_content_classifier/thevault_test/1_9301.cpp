ModelOptions::ModelOptions(ModelConfiguration& mc){
    ptrMC=&mc;
    
    //initial n-at-z options
    optsInitNatZ.allocate(0,1);
    optsInitNatZ(0) = "build up n-at-z from recruitments (like TCSAM2013)"; 
    optsInitNatZ(1) = "calculate initial n-at-z using equilibrium calculations (like Gmacs)";
    
    //options for natural mortality parameterization
    optsParamNM.allocate(0,1);
    optsParamNM(0) = "use log-scale parameterization (default)";
    optsParamNM(1) = "use TCSAM2013 parameterization (arithmetic scale)"; 
    
    //growth parameterization options
    optsGrowthParam.allocate(0,2);
    optsGrowthParam(0) = "TCSAM2013 parameterization (ln-scale intercept, slope)"; 
    optsGrowthParam(1) = "parameterization based on min, max pre-molt sizes";
    optsGrowthParam(2) = "parameterization based on min pre-molt size, ln-scale slope";
    
    //growth pdf options
    optsGrowthPDF.allocate(0,1);
    optsGrowthPDF(0) = "use gamma probability distribution (like TCSAM2013)"; 
    optsGrowthPDF(1) = "use cumulative gamma distribution (like Gmacs)";
    
    //penalty options for prM2M parameters/ogives smoothness
    optsPenSmthPrM2M.allocate(0,1);
    optsPenSmthPrM2M(0) = "evaluate smoothness using parameters";
    optsPenSmthPrM2M(1) = "evaluate smoothness using ogives";    
    //penalty options for prM2M parameters/ogives being non-decreasing w/ size
    optsPenNonDecPrM2M.allocate(0,3);
    optsPenNonDecPrM2M(0) = "use posfun function on parameters";
    optsPenNonDecPrM2M(1) = "use exponential function on parameters";    
    optsPenNonDecPrM2M(2) = "use posfun function on ogives";
    optsPenNonDecPrM2M(3) = "use exponential function on ogives";    
    
    //smoothness penalty options for nonparametric selectivity function parameters/curves
    optsPenSmthNPSel.allocate(0,1);
    optsPenSmthNPSel(0) = "evaluate smoothness using selectivity parameters";
    optsPenSmthNPSel(1) = "evaluate smoothness using selectivity functions";    
    
    //effort extrapolation options
    ptrEffXtrapScenarios = new EffXtrapScenarios(mc);
    
    //options for OFL calculations: capture rate/selectivity function averaging
    optsOFLAvgCapRate.allocate(0,1);
    optsOFLAvgCapRate(0) = "average max capture rates, selectivity functions (like TCSAM2013)";
    optsOFLAvgCapRate(1) = "average size-specific capture rates";
    
    //options for iterative re-weighting
    optsIterativeReweighting.allocate(0,2);
    optsIterativeReweighting(0) = "no iterative re-weighting";
    optsIterativeReweighting(1) = "use harmonic means of McAllister-Ianelli effective N's";
    optsIterativeReweighting(2) = "use Francis weights";
}