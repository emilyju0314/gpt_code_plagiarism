void SegmenterMS::eliminate_class(Octet *my_class,int *my_max_region, int *n_rects,int my_lim, Octet* inv_map, float T[][p_max], REGION *first_region)
{
  register int j, k;
  register Octet *valid_class; 
  register REGION *current_region=first_region;
  
  valid_class=new Octet[*n_rects]; 
  for(j=0;j<*n_rects;j++)
    {
      if(my_max_region[j]<my_lim) valid_class[j]=0;
      else                        valid_class[j]=1;
    }
  while(1)
    {
      if((current_region->my_class<*n_rects && 
          !valid_class[current_region->my_class]))
        for(k=0;k<current_region->my_contor;k++)
           gen_class[current_region->my_region[k]]=*n_rects;
      if(current_region->next_region_str)  
        current_region=current_region->next_region_str;
      else break;
    }
  Octet my_map[Max_rects];
  reverse_map(inv_map,my_map,n_rects,valid_class,T);
  for(k=0;k<_ro_col;k++)
    my_class[k]=my_map[gen_class[k]];
  delete [] valid_class;
  memcpy(gen_class,my_class,_ro_col);
}