void DeltaFinder2::testOrderID() {

    ChannelID x, o;
    
    for (int s=0; s<2; ++s) {
      for (int pl=0; pl<2; ++pl) {
	for (int pa=0; pa<6; ++pa) {
	  for (int l=0; l<2; ++l) {
	    x.Station = s;
	    x.Plane   = pl;
	    x.Panel   = pa;
	    x.Layer   = l;
	    orderID(&x, &o);
	    printf(" testOrderID: Initial(station = %i, plane = %i, face = %i, panel = %i, layer = %i)", 
		   x.Station, x.Plane, x.Face, x.Panel, x.Layer);
	    printf("  Ordered(station = %i, plane = %i, face = %i, panel = %i, layer = %i)\n",
		   o.Station, o.Plane, o.Face, o.Panel, o.Layer);
	  }
	}
      }
    }
  }