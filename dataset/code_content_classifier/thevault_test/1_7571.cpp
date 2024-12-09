void noveltyarchive::evaluate_individual(Organism* ind,vector<Organism*> pop,bool fitness)
{
    float result;
    if(fitness)  //assign fitness according to average novelty
    {
        if(ind->destroy)
        {
            result = 0.000000001;
            ind->fitness = result;
            ind->noveltypoint->novelty=result;
            ind->noveltypoint->genodiv=0;
        }
        else
        {
            if(!histogram)
                result = novelty_avg_nn(ind->noveltypoint,-1,false,&pop);
            else
                result = novelty_histogram(ind->noveltypoint);

        }
        //NEW WAY: production of novelty important
        if(production_score) {
            int init_weight=10;
            double fit_weight=init_weight;
            double fit_tot=ind->noveltypoint->novelty*init_weight;
            fit_tot+= ind->gnome->production;
            fit_weight+= ind->gnome->production_count;
            ind->fitness = fit_tot/fit_weight;
            //cout << fit_weight << endl;
            //cout << "adjusting novelty, weight " << fit_weight << ", from " << ind->noveltypoint->novelty << " to " << ind->fitness << endl;

            //END NEW WAY
        } else {
            ind->fitness = result;  //old way
        }
    }
    else  //consider adding a point to archive based on dist to nearest neighbor
    {
        if(!histogram)
        {
            result = novelty_avg_nn(ind->noveltypoint,1,false);
            //ind->noveltypoint->novelty=result;

            //if(!minimal_criteria)
            //   ind->noveltypoint->viable=true;
            if((!minimal_criteria || ind->noveltypoint->viable) && add_to_novelty_archive(result))
                add_novel_item(ind->noveltypoint);
        }
    }

}