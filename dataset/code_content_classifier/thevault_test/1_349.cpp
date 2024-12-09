void CsgTestApp::MergeWorker(Worker *worker) {
    RDFWorker * myRDFWorker;
// cast generel Worker into your derived worker class(here RDFWorker)
    myRDFWorker = dynamic_cast<RDFWorker*> (worker);

// the next comment block explains how mutexes are used internally for this function:
// mutexes are used to exclusively work on data
// e.g., if you read or write global data, make sure that nobody else (i.e. no other worker)
// works on that very same piece of data at the same time; otherwise,
// you will end up with wrong results that you struggle to understand
// the parent class handles a "merging mutex" for you internally; this is what happens:
// first, a mutex is created, e.g.
//        Mutex rdfMutex;
// then, for each worker, the mutex is first locked
//        rdfMutex.Lock())
// and MergeWorker(worker) is called (i.e. the code you define here is executed)
// after MergeWorker exits, the mutex is unlocked
//        rdfMutex.Unlock();
// and allows other threads to get a lock and start merging

// now follows your code

// merging of data in this simple example is easy and does not have to follow
// the original order of frames (since plain summing is commutative)
    _rdf.data().y() = _rdf.data().y() + myRDFWorker->_rdf.data().y();

}