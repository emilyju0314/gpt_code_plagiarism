void Imc::Worker::DoBonded(Topology *top)
{
    for (list<Property*>::iterator iter = _imc->_bonded.begin();
            iter != _imc->_bonded.end(); ++iter) {
        string name = (*iter)->get("name").value();
        
        interaction_t &i = *_imc->_interactions[name];

        // clear the current histogram
        _current_hists[i._index].Clear();

        // now fill with new data
        std::list<Interaction *> list = top->InteractionsInGroup(name);

        std::list<Interaction *>::iterator ic_iter;
        for(ic_iter=list.begin(); ic_iter!=list.end(); ++ic_iter) {
            Interaction *ic = *ic_iter;
            double v = ic->EvaluateVar(*top);
            _current_hists[i._index].Process(v);
        }
    }    
}