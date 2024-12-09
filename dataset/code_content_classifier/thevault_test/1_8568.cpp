int  Reshape::calculateChromaAdjVpduNei(TransformUnit &tu, const Position pos)
{
  CodingStructure &cs = *tu.cu->cs;
  int xPos = pos.x;
  int yPos = pos.y;
  int ctuSize = cs.sps->getCTUSize();
  int numNeighbor = std::min(64, ctuSize);
  int numNeighborLog = getLog2(numNeighbor);
  if (ctuSize == 128)
  {
    xPos &= ~63;
    yPos &= ~63;
  }
  else
  {
    xPos &= ~( ctuSize - 1 );
    yPos &= ~( ctuSize - 1 );
  }

  if( isVPDUprocessed( xPos, yPos ) )
  {
    return getChromaScale();
  }
  else
  {
    setVPDULoc(xPos, yPos);
    Position topLeft(xPos, yPos);
    CodingUnit *topLeftLuma;
    const CodingUnit *cuAbove, *cuLeft;

    topLeftLuma = cs.getCU( topLeft, CHANNEL_TYPE_LUMA );
    cuAbove     = cs.getCURestricted( topLeftLuma->lumaPos().offset( 0, -1 ), *topLeftLuma, CHANNEL_TYPE_LUMA, topLeftLuma->ly() == yPos ? topLeftLuma : topLeftLuma->above );
    cuLeft      = cs.getCURestricted( topLeftLuma->lumaPos().offset( -1, 0 ), *topLeftLuma, CHANNEL_TYPE_LUMA, topLeftLuma->lx() == xPos ? topLeftLuma : topLeftLuma->left  );

    xPos = topLeftLuma->lumaPos().x;
    yPos = topLeftLuma->lumaPos().y;

    CompArea lumaArea = CompArea(COMPONENT_Y, topLeftLuma->lumaPos(), topLeftLuma->lumaSize());
    PelBuf piRecoY = cs.picture->getRecoBuf(lumaArea);
    ptrdiff_t strideY = piRecoY.stride;
    int chromaScale = (1 << CSCALE_FP_PREC);
    int lumaValue = -1;

    Pel* recSrc0 = piRecoY.bufAt(0, 0);
    const uint32_t picH = tu.cu->cs->picture->lheight();
    const uint32_t picW = tu.cu->cs->picture->lwidth();
    const Pel   valueDC = 1 << (tu.cu->sps->getBitDepth(CHANNEL_TYPE_LUMA) - 1);
    int32_t recLuma = 0;
    int pelnum = 0;
    if (cuLeft != nullptr)
    {
      for (int i = 0; i < numNeighbor; i++)
      {
        int k = (yPos + i) >= picH ? (picH - yPos - 1) : i;
        recLuma += recSrc0[-1 + k * strideY];
        pelnum++;
      }
    }
    if (cuAbove != nullptr)
    {
      for (int i = 0; i < numNeighbor; i++)
      {
        int k = (xPos + i) >= picW ? (picW - xPos - 1) : i;
        recLuma += recSrc0[-strideY + k];
        pelnum++;
      }
    }
    if (pelnum == numNeighbor)
    {
      lumaValue = (recLuma + (1 << (numNeighborLog - 1))) >> numNeighborLog;
    }
    else if (pelnum == (numNeighbor << 1))
    {
      lumaValue = (recLuma + (1 << numNeighborLog)) >> (numNeighborLog + 1);
    }
    else
    {
      CHECK(pelnum != 0, "");
      lumaValue = valueDC;
    }
    chromaScale = calculateChromaAdj(lumaValue);
    setChromaScale(chromaScale);
    return(chromaScale);
  }
}