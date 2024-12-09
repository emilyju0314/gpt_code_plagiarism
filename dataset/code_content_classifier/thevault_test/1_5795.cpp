void PeptideNamespace::Peptide::normalizeLabelIntensity(double den)
{
    for(auto & fragment : fragments)
        if(fragment.getFound())
            fragment.setFoundIntensity(fragment.getFoundIntensity() / den);
}