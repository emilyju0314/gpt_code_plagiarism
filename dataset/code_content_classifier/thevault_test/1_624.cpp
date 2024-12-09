void
compute_curl_b_pipeline_scalar( pipeline_args_t * args,
                                int pipeline_rank,
                                int n_pipeline )
{
  DECLARE_STENCIL();

  int n_voxel;

  DISTRIBUTE_VOXELS( 2,nx, 2,ny, 2,nz, 16,
                     pipeline_rank, n_pipeline,
                     x, y, z, n_voxel );

  INIT_STENCIL();

  for( ; n_voxel; n_voxel-- )
  {
    UPDATE_EX();
    UPDATE_EY();
    UPDATE_EZ();

    NEXT_STENCIL();
  }
}