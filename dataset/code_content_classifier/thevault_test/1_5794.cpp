void PeptideNamespace::Peptide::removeLabelIntensityBelow(double min_int, bool require_nl, bool remove)
{
    for(auto it = fragments.begin(); it != fragments.end();)
    {
        if(it->getFoundIntensity() <= min_int)
        {
            if(require_nl && !it->isNL()) {
                ++it;
                continue;
            }

            if(remove) {
                fragments.erase(it);
                continue;
            }
            else {
                it->setFound(false);
            }
        }
        ++it;
    }
}