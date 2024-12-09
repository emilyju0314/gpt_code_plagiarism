int ReadBack::countHitNeighbours( Straw const& straw,
                                    art::Handle<StepPointMCCollection>& hits ){

    int count(0);

    for ( auto const& step : *hits ){
      if ( step.strawId().nearestNeighbor(straw.id()) ){
	++count;
      }
    }
    return count;
  }