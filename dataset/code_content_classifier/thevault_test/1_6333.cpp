bool GeomData::filter(unsigned int idx)
{
  //Iterate all the filters,
  // - if a value matches a filter condition return true (filtered)
  // - if no filters hit, returns false
  float value, min, max;
  int size, range;
  unsigned int ridx;
  for (unsigned int i=0; i < draw->filterCache.size(); i++)
  {
    if (values.size() <= draw->filterCache[i].dataIdx || !values[draw->filterCache[i].dataIdx]) continue;
    size = values[draw->filterCache[i].dataIdx]->size();
    if (draw->filterCache[i].dataIdx < MAX_DATA_ARRAYS && size > 0)
    {
      //Have values but not enough for per-vertex? spread over range (eg: per triangle)
      range = count() / size;
      ridx = idx;
      if (range > 1) ridx = idx / range;

      //if (idx%1000==0) std::cout << "Filtering on index: " << draw->filterCache[i].dataIdx << " " << size << " values" << std::endl;
      min = draw->filterCache[i].minimum;
      max = draw->filterCache[i].maximum;
      Values_Ptr v = values[draw->filterCache[i].dataIdx];
      if (draw->filterCache[i].map)
      {
        //Range type filters map over available values on [0,1] => [min,max]
        //If a colourmap is provided, that is used to get the values (allows log maps)
        //Otherwise they come directly from the data 
        ColourMap* cmap = draw->colourMap;
        if (cmap)
          value = cmap->scaleValue((*v)[ridx]);
        else if (v != nullptr)
        {
          auto range = draw->ranges[v->label];
          value = range.maximum - range.minimum;
          min = range.minimum + min * value;
          max = range.minimum + max * value;
          value = (*v)[ridx];
        }
      }
      else
        value = (*v)[ridx];

      //Always filter nan/inf
      if (std::isnan(value) || std::isinf(value)) return true;

      //if (idx%10000==0) std::cout << min << " < " << value << " < " << max << std::endl;
      //std::cout << min << " < " << value << " < " << max << std::endl;
      
      //"out" flag indicates values between the filter range are skipped - exclude
      if (draw->filterCache[i].out)
      {
        //- return TRUE if VALUE inside RANGE
        if (min == max)
        {
          if (min == value)
            return true;
          continue;
        }
        //Filters out values between specified ranges (allows filtering separate sections)
        if (draw->filterCache[i].inclusive && value >= min && value <= max)
          return true;
        if (value > min && value < max) 
          return true;
      }
      //Default is to filter values NOT in the filter range - include those that are
      else
      {
        //- return TRUE if VALUE outside RANGE
        if (min == max)
        {
          if (min != value)
            return true;
          continue;
        }
        //Filters out values not between specified ranges (allows combining filters)
        if (draw->filterCache[i].inclusive && (value < min || value > max))
          return true;
        if (value <= min || value >= max)
          return true;
      }
    }
  }
  //std::cout << "(Not filtered)\n";
  return false;
}