CsgApplication::Worker * CsgTestApp::ForkWorker() {
    RDFWorker *worker;
    worker = new RDFWorker();
// initialize
    worker->_cut_off = OptionsMap()["c"].as<double>();
    worker->_rdf.Initialize(0, worker->_cut_off, 50);
    return worker; 
}