std::vector<int>
opengv::relative_pose::MANoncentralRelativeMulti::
    convertMultiIndices( const std::vector<std::vector<int> > & multiIndices ) const
{
  std::vector<int> singleIndices;
  for(size_t pairIndex = 0; pairIndex < multiIndices.size(); pairIndex++)
  {
    for(
        size_t correspondenceIndex = 0;
        correspondenceIndex < multiIndices[pairIndex].size(); 
        correspondenceIndex++ )
      singleIndices.push_back(convertMultiIndex(
          pairIndex, multiIndices[pairIndex][correspondenceIndex] ));
  }

  return singleIndices;
}