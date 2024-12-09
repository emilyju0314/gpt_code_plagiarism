void FeatureNetGraph::BoundingBox(BBox& bb)
{
  int i;
  minx_=int(bb.xmin);
  maxx_=int(bb.xmax);
  int newtix=int(time_*(maxx_-minx_)/(maxtime_-mintime_));
  if (newtix!=tix_) {
    tix_=newtix;
  }
  for(i=0;i<maxx_-minx_;i++)
    {
      scaleddata_[i]=0.0;
    }
  maxy_=1.0;
  /*Note: storing the data in an array like this is quick, but introduces
    some aliasing effects in the scaling process.  I think they're 
    negligable for this purpose but if we really want to remove them
    we must store the unscaled data in a list instead*/
  for(i=0;i<MAX_GRAPH;i++)
    {
      int ix = int(((float)(i*(maxx_-minx_)))/MAX_GRAPH);
      scaleddata_[ix]=graphdata_[i];
      if (scaleddata_[ix]>maxy_)
	maxy_=scaleddata_[ix];
    }
  if (miny_!=maxy_)
    {
      bb.ymin=miny_;
      bb.ymax=maxy_;
    }
  else 
    {
      bb.ymin=0.0;
      bb.ymax=1.0;
    }
}