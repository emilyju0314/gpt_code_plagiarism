Organism* Population::remove_worst_probabilistic() {

    double adjusted_fitness;
    double min_fitness=999999;
    std::vector<Organism*>::iterator curorg;
    Organism *org_to_kill = 0;
    std::vector<Organism*>::iterator deadorg;
    Species *orgs_species; //The species of the dead organism

    //Make sure the organism is deleted from its species and the population

    std::vector<Organism*> sorted_adjusted_orgs;

    for(curorg = organisms.begin(); curorg != organisms.end(); ++curorg) {
        if ((*curorg)->time_alive >= NEAT::time_alive_minimum)
            sorted_adjusted_orgs.push_back(*curorg);
    }

    if (sorted_adjusted_orgs.size() == 0)
        return 0;

    //sorted_adjusted_orgs.qsort(order_orgs_by_adjusted_fit);
    std::sort(sorted_adjusted_orgs.begin(), sorted_adjusted_orgs.end(), order_orgs_by_adjusted_fit);

    int size_bottom_10_percent = ceil((float)sorted_adjusted_orgs.size() * 0.10);
    int randorgnum = NEAT::randint(sorted_adjusted_orgs.size() - size_bottom_10_percent, sorted_adjusted_orgs.size() - 1);

    curorg = sorted_adjusted_orgs.begin();
    curorg += randorgnum;
    org_to_kill = *curorg;
    orgs_species=(org_to_kill)->species;

    curorg = organisms.begin();
    while (*curorg != org_to_kill) {
        ++curorg;
    }
    deadorg = curorg;

    //First find the organism with minimum *adjusted* fitness
    //for(curorg=organisms.begin();curorg!=organisms.end();++curorg) {
    //	adjusted_fitness=((*curorg)->fitness)/((*curorg)->species->organisms.size());
    //	if ((adjusted_fitness<min_fitness)&&
    //		(((*curorg)->time_alive) >= NEAT::time_alive_minimum))
    //	{
    //		min_fitness=adjusted_fitness;
    //		org_to_kill=(*curorg);
    //		deadorg=curorg;
    //		orgs_species=(*curorg)->species;
    //	}
    //}

    //printf("Org to kill time_alive = %d and fitness = %f",org_to_kill->time_alive,org_to_kill->fitness);

    if (org_to_kill) {
        //Remove the organism from its species and the population
        orgs_species->remove_org(org_to_kill);  //Remove from species
        delete org_to_kill;  //Delete the organism itself
        organisms.erase(deadorg); //Remove from population list

        //Did the species become empty?
        if ((orgs_species->organisms.size())==0) {

            remove_species(orgs_species);
            delete orgs_species;
        }
        //If not, re-estimate the species average after removing the organism
        else {
            orgs_species->estimate_average();
        }
    }

    return org_to_kill;
}