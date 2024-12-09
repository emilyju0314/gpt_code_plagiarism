double ImageSearchIndex::CalcDocumentSimilarity(const ImageDocument& a,
                                                const ImageDocument& b) const {
  double score = 0;

  // Start by calculating the dot product by iterating through the smaller doc
  const ImageDocument* iterDoc = &a;
  const ImageDocument* lookupDoc = &b;
  if (a.nUniqueTerms() > b.nUniqueTerms()) {
    iterDoc = &b;
    lookupDoc = &a;
  }
  for(ImageDocument::TermMap::const_iterator termI = iterDoc->begin();
      termI != iterDoc->end(); ++termI) {
    score += (termI->second->val() * lookupDoc->GetVal(termI->first));
  }

  // Now divide by the lengths
  score /= a.length();
  score /= b.length();

  return score;
}