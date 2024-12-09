void HLSyntaxReader::parseScalingList( ScalingList *scalingList, bool aps_chromaPrsentFlag )
{
  uint32_t  code;
  bool scalingListCopyModeFlag;
  scalingList->setChromaScalingListPresentFlag( aps_chromaPrsentFlag );
  for( int scalingListId = 0; scalingListId < 28; scalingListId++ )
  {
    if( aps_chromaPrsentFlag || scalingList->isLumaScalingList( scalingListId ) )
    {
      READ_FLAG( code, "scaling_list_copy_mode_flag" );
      scalingListCopyModeFlag = ( code ) ? true : false;
      scalingList->setScalingListCopyModeFlag( scalingListId, scalingListCopyModeFlag );

      scalingList->setScalingListPreditorModeFlag( scalingListId, false );
      if( !scalingListCopyModeFlag )
      {
        READ_FLAG( code, "scaling_list_pred_mode_flag" );
        scalingList->setScalingListPreditorModeFlag( scalingListId, code );
      }

      if( ( scalingListCopyModeFlag || scalingList->getScalingListPreditorModeFlag( scalingListId ) ) && scalingListId !=  SCALING_LIST_1D_START_2x2 && scalingListId != SCALING_LIST_1D_START_4x4 && scalingListId != SCALING_LIST_1D_START_8x8 ) //Copy Mode
      {
        READ_UVLC( code, "scaling_list_pred_id_delta" );
        scalingList->setRefMatrixId( scalingListId, (uint32_t)( (int)( scalingListId ) - ( code ) ) );
      }
      else if( scalingListCopyModeFlag || scalingList->getScalingListPreditorModeFlag( scalingListId ) )
      {
        scalingList->setRefMatrixId( scalingListId, (uint32_t)( (int)( scalingListId ) ) );
      }
      if( scalingListCopyModeFlag )//copy
      {
        if( scalingListId >= SCALING_LIST_1D_START_16x16 )
        {
          scalingList->setScalingListDC( scalingListId,
                                         ( ( scalingListId == scalingList->getRefMatrixId( scalingListId ) ) ? 16
                                           : ( scalingList->getRefMatrixId( scalingListId ) < SCALING_LIST_1D_START_16x16 )
                                             ? scalingList->getScalingListAddress( scalingList->getRefMatrixId( scalingListId ) )[0]
                                             : scalingList->getScalingListDC( scalingList->getRefMatrixId( scalingListId ) ) ) );
        }
        scalingList->processRefMatrix( scalingListId, scalingList->getRefMatrixId( scalingListId ) );
      }
      else
      {
        decodeScalingList( scalingList, scalingListId, scalingList->getScalingListPreditorModeFlag( scalingListId ) );
      }
    }
    else
    {
      scalingListCopyModeFlag = true;
      scalingList->setScalingListCopyModeFlag( scalingListId, scalingListCopyModeFlag );
      scalingList->setRefMatrixId(scalingListId, (uint32_t)( (int)( scalingListId ) ) );
      if (scalingListId >= SCALING_LIST_1D_START_16x16)
      {
        scalingList->setScalingListDC( scalingListId, 16 );
      }
      scalingList->processRefMatrix( scalingListId, scalingList->getRefMatrixId( scalingListId ) );
    }
  }

  return;
}