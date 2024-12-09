void ComputeBackVector( int* recon_right_back_ptr, int* recon_down_back_ptr,
                        VidStream* the_stream )
{
  Pict *picture;
  Macroblock *mblock;

  picture = &(the_stream->picture);
  mblock = &(the_stream->mblock);

  ComputeVector(recon_right_back_ptr, recon_down_back_ptr,
		mblock->recon_right_back_prev, 
		mblock->recon_down_back_prev,
		(int) picture->back_f, 
		picture->full_pel_back_vector,
		mblock->motion_h_back_code, mblock->motion_v_back_code,
		mblock->motion_h_back_r, mblock->motion_v_back_r); 

}