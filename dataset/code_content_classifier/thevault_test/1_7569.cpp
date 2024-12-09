void noveltyarchive::evaluate_population(Population* pop,bool fitness)
{
    Population *p = (Population*)pop;
    vector<Organism*>::iterator it;
    for(it=p->organisms.begin(); it<p->organisms.end(); it++)
        evaluate_individual((*it),pop->organisms,fitness);
}