void HLSyntaxReader::decodeScalingList( ScalingList *scalingList, uint32_t scalingListId, bool isPredictor )
{
  int matrixSize = ( scalingListId < SCALING_LIST_1D_START_4x4 ) ? 2 : ( scalingListId < SCALING_LIST_1D_START_8x8 ) ? 4 : 8;
  int i, coefNum = matrixSize * matrixSize;
  int data;
  int scalingListDcCoefMinus8 = 0;
  int nextCoef = ( isPredictor ) ? 0 : SCALING_LIST_START_VALUE;
  const uint16_t *scan = g_scanOrder[SCAN_UNGROUPED][g_sizeIdxInfo.idxFrom( matrixSize )][g_sizeIdxInfo.idxFrom( matrixSize )];
  int *dst = scalingList->getScalingListAddress( scalingListId );

  int PredListId = scalingList->getRefMatrixId( scalingListId );
  CHECK( isPredictor && PredListId > scalingListId, "Scaling List error predictor!" );
  const int *srcPred = isPredictor ? ( ( scalingListId == PredListId ) ? scalingList->getScalingListDefaultAddress( scalingListId )
                                                                       : scalingList->getScalingListAddress( PredListId ) )
                                   : NULL;
  int predCoef = 0;

  if( scalingListId >= SCALING_LIST_1D_START_16x16 )
  {
    READ_SVLC( scalingListDcCoefMinus8, "scaling_list_dc_coef" );
    nextCoef += scalingListDcCoefMinus8;
    if( isPredictor )
    {
      predCoef = ( PredListId >= SCALING_LIST_1D_START_16x16 ) ? scalingList->getScalingListDC( PredListId ) : srcPred[0];
    }
    scalingList->setScalingListDC( scalingListId, ( nextCoef + predCoef + 256 ) % 256 );
  }

  for( i = 0; i < coefNum; i++ )
  {
    int blkPos = scan[i];
    int posX = blkPos & ( ( 1 << g_sizeIdxInfo.idxFrom( matrixSize ) ) - 1 );
    int posY = blkPos >> g_sizeIdxInfo.idxFrom( matrixSize );

    if( scalingListId >= SCALING_LIST_1D_START_64x64 && posX >= 4 && posY >= 4 )
    {
      dst[scan[i]] = 0;
      continue;
    }
    READ_SVLC( data, "scaling_list_delta_coef[i]" );
    nextCoef += data;
    predCoef = ( isPredictor ) ? srcPred[scan[i]] : 0;
    dst[scan[i]] = (nextCoef + predCoef + 256) % 256;
  }
}