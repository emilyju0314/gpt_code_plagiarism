size_t convertAdjMatToVector(
    IntegerMatrix gene_interaction, std::vector<size_t>& tgtGene,
    std::vector<std::pair<size_t,size_t> >& intSrcType){
  size_t nGene = gene_interaction.nrow();
  size_t nInteractions = 0;
  //  Rcout<<nGene<<"\n";
  for(size_t tmpTgtGene = 0; tmpTgtGene < nGene; tmpTgtGene++ ){
    for(size_t tmpSrcGene = 0; tmpSrcGene < nGene; tmpSrcGene++ ){
      if(gene_interaction(tmpTgtGene,tmpSrcGene) > 0){
        nInteractions++;
        tgtGene.push_back(tmpTgtGene);
        intSrcType.push_back(
          std::make_pair(tmpSrcGene,(gene_interaction(tmpTgtGene,tmpSrcGene))));

      }
    }
  }
  return nInteractions;
}