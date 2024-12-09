void Quant::xInitScalingList( const Quant* other )
{
  if( other )
  {
    m_dequantCoefBuf  = other->m_dequantCoefBuf;
    m_ownDequantCoeff = false;
  }
  else
  {
    m_dequantCoefBuf  = new int[580644];
    m_ownDequantCoeff = true;
  }

  size_t numQuants = 0;

  for(uint32_t sizeIdX = 0; sizeIdX < SCALING_LIST_SIZE_NUM; sizeIdX++)
  {
    for(uint32_t sizeIdY = 0; sizeIdY < SCALING_LIST_SIZE_NUM; sizeIdY++)
    {
      for(uint32_t qp = 0; qp < SCALING_LIST_REM_NUM; qp++)
      {
        for(uint32_t listId = 0; listId < SCALING_LIST_NUM; listId++)
        {
          m_dequantCoef [sizeIdX][sizeIdY][listId][qp] = &m_dequantCoefBuf[numQuants];
          numQuants += g_vvcScalingListSizeX[sizeIdX] * g_vvcScalingListSizeX[sizeIdY];
        } // listID loop
      }
    }
  }

  CHECK( numQuants != 580644, "Incorrect size of scaling list entries number!" );
}