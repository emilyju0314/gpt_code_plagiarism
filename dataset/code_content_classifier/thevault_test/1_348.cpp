void RDFWorker::EvalConfiguration(Topology *top, Topology *top_ref) {
    BeadList b;
    b.Generate(*top, "*");
    NBListGrid nb;
    nb.setCutoff(_cut_off);
    nb.Generate(b);
    NBList::iterator i;
    for (i = nb.begin(); i != nb.end(); ++i) {
        _rdf.Process((*i)->dist());
    }
}