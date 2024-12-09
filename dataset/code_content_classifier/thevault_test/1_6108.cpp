int SegmenterMS::subsample(float *Xmean )
{
  int J[9];
  register int my_contor=0, uj, i0;
  if(auto_segm)
    i0=J[my_contor]=
       gen_remain[int(float(n_remain)*float(rand())/float(RAND_MAX))]; 
  else
    i0=J[my_contor]=int(float(_n_points)*float(rand())/float(RAND_MAX));
  my_contor++;
  for(int i=0;i<8;i++){
    uj=i0 + my_neigh_r[i];
    if(uj>=0 && uj<_n_points)
      {
        if((auto_segm && gen_class[uj]!=255)) break;
	else
          {        
            J[my_contor] = uj;
            my_contor++;
	  }      
      }
    }
  mean_s(my_contor, _p, J, _data, Xmean);
  return 1;
}