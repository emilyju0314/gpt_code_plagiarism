void SegmenterMS::conn_comp(Octet *my_class, int *n_rects, Octet *inv_map, float T[][p_max],int my_lim, int change_type)
{
  REGION *first_region; 
  int *my_max_region;
  if(change_type==0)
    {
      my_max_region = new int[(*n_rects)+1];
      memset(my_max_region,0,sizeof(int)*((*n_rects)+1));
    }
  first_region=create_region_list(my_max_region, change_type);
  if(change_type==0)  //elliminate classes with small regions
    eliminate_class(my_class,my_max_region,n_rects,my_lim,inv_map,T,first_region); 
  else if(change_type==1)  //elliminate small regions
    eliminate_region(n_rects,my_lim,T,first_region);
  destroy_region_list(first_region);
  if(change_type==0) delete [] my_max_region;
  //cerr<<":";
}