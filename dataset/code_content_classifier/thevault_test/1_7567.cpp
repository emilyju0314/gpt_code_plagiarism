Population* noveltyarchive::merge_populations(Population* p1, vector<Organism*> p2)
{

    vector<Organism*> total_orgs;
    vector<Organism*> merged_orgs;
    vector<Organism*>::iterator it;
    vector<noveltyitem*>::iterator novit;

//compile the organisms together
    for(it = p1->organisms.begin(); it!= p1->organisms.end(); it++)
    {
        total_orgs.push_back(*it);
        (*it)->blacklist=false;
    }

    for(it = p2.begin(); it!= p2.end(); it++)
    {
        total_orgs.push_back(*it);
        (*it)->blacklist=false;
    }

//throw in the archive as well

    for(novit = novel_items.begin(); novit != novel_items.end(); novit++)
    {
        //TODO: just creating these organisms will be a mem leak
        //eventually refactor...
        Organism* arch_org = new Organism(0.1,(*novit)->genotype,0,NULL);
        arch_org->noveltypoint = (*novit);
        arch_org->blacklist=false;
        total_orgs.push_back(arch_org);
        //or at least delete...?
    }

    int size = total_orgs.size(); //remove one since we are adding 1st
    cout << size << " " << p1->organisms.size() << " " << p2.size() << " " <<
         novel_items.size() << endl;

//randomly add first member to merged organisms
    Organism* last_added = total_orgs[rand()%size];
    last_added->blacklist=true;
    merged_orgs.push_back(last_added);

    for(it = total_orgs.begin(); it!=total_orgs.end(); it++)
    {
        (*it)->closest = 100000.0;
    }

//now greedily add point furthest from merged pop so far
//for(int x=0;x<(size/2)-1;x++)
    for(int x=0; x<(p1->organisms.size()-1); x++)
    {
        Organism* best=NULL;
        double best_dist= -1000.0;
        for(it = total_orgs.begin(); it!=total_orgs.end(); it++)
        {
            if ((*it)->blacklist)
                continue;

            double new_dist = (*novelty_metric)((*it)->noveltypoint,
                                                last_added->noveltypoint);

            if (new_dist < (*it)->closest)
                (*it)->closest = new_dist;

            if ((*it)->closest > best_dist)
            {
                best_dist = ((*it)->closest);
                best = *it;
            }
        }
        best->blacklist=true;
        last_added = best;
        merged_orgs.push_back(best);
    }

    return new Population(merged_orgs);


}