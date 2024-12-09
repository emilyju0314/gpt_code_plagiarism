bool
NSGenerateurFr::donnePremierAdj(NSPhraseur* pCompAdj, NSPhraseMot* pMotAdj)
{
    NSSuper* pSuper = pContexte->getSuperviseur();
    NSPathologData PremierAdjData;
    NSPhraseMot PremierAdj(pContexte);
    bool trouve;
    string sLexiqueAdj = "";

    if (pCompAdj)
    {
        NsProposition* pPropos = new NsProposition(pContexte, &pCompAdj, NsProposition::notSetType, NsProposition::notSetConjonct, false);
        NSGenerateurFr* pGeneCompl = new NSGenerateurFr(pContexte, pPropos, sLang);
        pCompAdj->classeAdjectif(this);
        pGeneCompl->classeTout();

        if (pGeneCompl->pAdjEpitheteAvPos)
        {
            if (!((pGeneCompl->pAdjEpitheteAvPos)->empty()))
            {
                PremierAdj = *(*((pGeneCompl->pAdjEpitheteAvPos)->begin()));
                sLexiqueAdj = PremierAdj.getLexique();

                // Si jamais le premier adjectif est un texte libre, on l'ignore,
                // vu qu'on est incapable de le traiter grammaticalement.
                if (PremierAdj.estTexteLibre())
                    return false;

                trouve = pContexte->getDico()->trouvePathologData(sLang, &sLexiqueAdj, &PremierAdjData);
                if (!trouve)
                    return false;
                if (pMotAdj)
                    *pMotAdj = PremierAdj;
                return true;
            }
        }
        else if (pGeneCompl->pAdjEpitheteAvNeg)
            if (!((pGeneCompl->pAdjEpitheteAvNeg)->empty()))
            {
                PremierAdj = *(*((pGeneCompl->pAdjEpitheteAvNeg)->begin()));
                sLexiqueAdj = PremierAdj.getLexique();

                if (PremierAdj.estTexteLibre())
                    return false;

                trouve = pContexte->getDico()->trouvePathologData(sLang, &sLexiqueAdj, &PremierAdjData);
                if (!trouve)
                    return false;
                if (pMotAdj)
                    *pMotAdj = PremierAdj;
                return true;
            }

        delete pGeneCompl;
        delete pPropos;
    }
    return false;
}