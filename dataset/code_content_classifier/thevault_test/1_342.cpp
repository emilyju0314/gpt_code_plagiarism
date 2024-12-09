void Imc::Worker::DoNonbonded(Topology *top)
{
    for (list<Property*>::iterator iter = _imc->_nonbonded.begin();
            iter != _imc->_nonbonded.end(); ++iter) {
        string name = (*iter)->get("name").value();
        
        interaction_t &i = *_imc->_interactions[name];
        
        // generate the bead lists
        BeadList beads1, beads2;
        
        beads1.Generate(*top, (*iter)->get("type1").value());
        beads2.Generate(*top, (*iter)->get("type2").value());
               
        // generate the neighbour list
        NBList *nb;

        bool gridsearch=true;

        if(_imc->_options.exists("cg.nbsearch")) {
            if(_imc->_options.get("cg.nbsearch").as<string>() == "grid")
                gridsearch=true;
            else if(_imc->_options.get("cg.nbsearch").as<string>() == "simple")
                gridsearch=false;
            else throw std::runtime_error("cg.nbsearch invalid, can be grid or simple");
        }
        if(gridsearch)
            nb = new NBListGrid();
        else
            nb = new NBList();

        nb->setCutoff(i._max + i._step);
                
        // clear the current histogram
        _current_hists[i._index].Clear();

        IMCNBSearchHandler h(&(_current_hists[i._index]));

        nb->SetMatchFunction(&h, &IMCNBSearchHandler::FoundPair);

        // is it same types or different types?
        if((*iter)->get("type1").value() == (*iter)->get("type2").value())
            nb->Generate(beads1);
        else
            nb->Generate(beads1, beads2);

        // process all pairs
        /*NBList::iterator pair_iter;
        for(pair_iter = nb->begin(); pair_iter!=nb->end();++pair_iter) {
                _current_hists[i._index].Process((*pair_iter)->dist());
        }*/

        delete nb;
    }    
}