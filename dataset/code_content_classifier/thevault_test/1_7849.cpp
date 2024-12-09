void Quant::setScalingListDec( ScalingList& scalingList )
{
  const int minimumQp = 0;
  const int maximumQp = SCALING_LIST_REM_NUM;

  int scalingListId    = 0;
  int recScalingListId = 0;
  for( uint32_t size = SCALING_LIST_FIRST_CODED; size <= SCALING_LIST_LAST_CODED; size++ )
  {
    for( uint32_t list = 0; list < SCALING_LIST_NUM; list++ )
    {
      if( size == SCALING_LIST_2x2 && list < 4 )   // skip 2x2 luma
      {
        continue;
      }
      scalingListId = g_scalingListId[size][list];
      for( int qp = minimumQp; qp < maximumQp; qp++ )
      {
        xSetScalingListDec( scalingList, list, size, qp, scalingListId );
      }
    }
  }
  // based on square result and apply downsample technology
  for( uint32_t sizew = 0; sizew <= SCALING_LIST_LAST_CODED; sizew++ )   // 7
  {
    for( uint32_t sizeh = 0; sizeh <= SCALING_LIST_LAST_CODED; sizeh++ )   // 7
    {
      if( sizew == sizeh || ( sizew == SCALING_LIST_1x1 && sizeh < SCALING_LIST_4x4 ) || ( sizeh == SCALING_LIST_1x1 && sizew < SCALING_LIST_4x4 ) )
      {
        continue;
      }
      for( uint32_t list = 0; list < SCALING_LIST_NUM; list++ )   // 9
      {
        int largerSide = ( sizew > sizeh ) ? sizew : sizeh;
        CHECK( largerSide < SCALING_LIST_4x4, "Rectangle Error!" );
        recScalingListId = g_scalingListId[largerSide][list];
        for( int qp = minimumQp; qp < maximumQp; qp++ )
        {
          xSetRecScalingListDec( scalingList, list, sizew, sizeh, qp, recScalingListId );
        }
      }
    }
  }
}