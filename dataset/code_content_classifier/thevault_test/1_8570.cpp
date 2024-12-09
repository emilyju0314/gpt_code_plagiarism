int PartitionerImpl::getCUSubPartitions( const UnitArea &cuArea, const CodingStructure &cs, const PartSplit _splitType, Partitioning& dst )
{
  const PartSplit splitType = _splitType;

  if( splitType == CU_QUAD_SPLIT )
  {
    Partitioning& sub = dst;

    for( uint32_t i = 0; i < 4; i++ )
    {
      sub[i] = cuArea;

      for( auto &blk : sub[i].blocks )
      {
        blk.height >>= 1;
        blk.width  >>= 1;
        if( i >= 2 ) blk.y += blk.height;
        if( i &  1 ) blk.x += blk.width;
      }

      CHECK( sub[i].lumaSize().height < MIN_TU_SIZE, "the split causes the block to be smaller than the minimal TU size" );
    }

    return 4;
  }
  else if( splitType == CU_HORZ_SPLIT )
  {
    Partitioning& sub = dst;

    for (uint32_t i = 0; i < 2; i++)
    {
      sub[i] = cuArea;

      for (auto &blk : sub[i].blocks)
      {
        blk.height >>= 1;
        if (i == 1) blk.y += blk.height;
      }

      CHECK(sub[i].lumaSize().height < MIN_TU_SIZE, "the cs split causes the block to be smaller than the minimal TU size");
    }

    return 2;
  }
  else if( splitType == CU_VERT_SPLIT )
  {
    Partitioning& sub = dst;

    for( uint32_t i = 0; i < 2; i++ )
    {
      sub[i] = cuArea;

      for( auto &blk : sub[i].blocks )
      {
        blk.width >>= 1;
        if( i == 1 ) blk.x += blk.width;
      }

      CHECK( sub[i].lumaSize().width < MIN_TU_SIZE, "the split causes the block to be smaller than the minimal TU size" );
    }

    return 2;
  }
  else if( splitType == CU_TRIH_SPLIT )
  {
    Partitioning& sub = dst;

    for( int i = 0; i < 3; i++ )
    {
      sub[i] = cuArea;

      for( auto &blk : sub[i].blocks )
      {
        blk.height >>= 1;
        if( ( i + 1 ) & 1 ) blk.height >>= 1;
        if( i == 1 )        blk.y       +=     blk.height / 2;
        if( i == 2 )        blk.y       += 3 * blk.height;
      }

      CHECK( sub[i].lumaSize().height < MIN_TU_SIZE, "the cs split causes the block to be smaller than the minimal TU size" );
    }

    return 3;
  }
  else if( splitType == CU_TRIV_SPLIT )
  {
    Partitioning& sub = dst;

    for( int i = 0; i < 3; i++ )
    {
      sub[i] = cuArea;

      for( auto &blk : sub[i].blocks )
      {
        blk.width >>= 1;

        if( ( i + 1 ) & 1 ) blk.width >>= 1;
        if( i == 1 )        blk.x      +=     blk.width / 2;
        if( i == 2 )        blk.x      += 3 * blk.width;
      }

      CHECK( sub[i].lumaSize().width < MIN_TU_SIZE, "the cs split causes the block to be smaller than the minimal TU size" );
    }

    return 3;
  }
  else
  {
    THROW( "Unknown CU sub-partitioning" );
  }
}