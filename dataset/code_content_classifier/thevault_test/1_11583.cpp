static void orxFASTCALL orxPhysics_ApplySimulationResult(orxPHYSICS_BODY *_pstBody)
{
  b2Body         *poBody;
  orxOBJECT      *pstObject;
  orxBODY        *pstBody;
  orxFRAME       *pstFrame;
  orxFRAME_SPACE  eFrameSpace;

  /* Profiles */
  orxPROFILER_PUSH_MARKER("orxPhysics_ApplySimResult");

  /* Gets physics body */
  poBody = (b2Body *)_pstBody;

  /* Gets associated body */
  pstBody = orxBODY(poBody->GetUserData());

  /* Gets owner object */
  pstObject = orxOBJECT(orxStructure_GetOwner(pstBody));

  /* Gets its frame */
  pstFrame = orxOBJECT_GET_STRUCTURE(pstObject, FRAME);

  /* Gets its frame space */
  eFrameSpace = (orxFrame_IsRootChild(pstFrame) != orxFALSE) ? orxFRAME_SPACE_LOCAL : orxFRAME_SPACE_GLOBAL;

  /* Is enabled? */
  if(orxObject_IsEnabled(pstObject) != orxFALSE)
  {
    orxVECTOR   vSpeed, vOldPos, vNewPos;
    orxCLOCK   *pstClock;
    orxFLOAT    fCoef = orxFLOAT_1;

    /* Gets its clock */
    pstClock = orxObject_GetClock(pstObject);

    /* Valid */
    if(pstClock != orxNULL)
    {
      const orxCLOCK_INFO *pstClockInfo;

      /* Gets its info */
      pstClockInfo = orxClock_GetInfo(pstClock);

      /* Has multiplier? */
      if(pstClockInfo->eModType == orxCLOCK_MOD_TYPE_MULTIPLY)
      {
        /* Uses it */
        fCoef = (pstClockInfo->fModValue != orxFLOAT_0) ? orxFLOAT_1 / pstClockInfo->fModValue : orxFLOAT_0;
      }
    }

    /* Gets resulting speed */
    orxPhysics_GetSpeed(_pstBody, &vSpeed);

    /* Global space? */
    if(eFrameSpace == orxFRAME_SPACE_GLOBAL)
    {
      orxVECTOR vScale;
      orxFRAME *pstParentFrame;

      /* Gets parent frame */
      pstParentFrame = orxFRAME(orxStructure_GetParent(pstFrame));

      /* Updates speed according to parent scale & rotation */
      orxVector_2DRotate(&vSpeed, &vSpeed, -orxFrame_GetRotation(pstParentFrame, orxFRAME_SPACE_GLOBAL));
      orxVector_Div(&vSpeed, &vSpeed, orxFrame_GetScale(pstParentFrame, orxFRAME_SPACE_GLOBAL, &vScale));
    }

    /* Updates its speed & angular velocity */
    orxBody_SetSpeed(pstBody, orxVector_Mulf(&vSpeed, &vSpeed, fCoef));
    orxBody_SetAngularVelocity(pstBody, fCoef * orxPhysics_GetAngularVelocity(_pstBody));

    /* Updates rotation */
    orxFrame_SetRotation(pstFrame, eFrameSpace, orxPhysics_GetRotation(_pstBody));

    /* Updates position */
    orxFrame_GetPosition(pstFrame, eFrameSpace, &vOldPos);
    orxPhysics_GetPosition(_pstBody, &vNewPos);
    vNewPos.fZ = vOldPos.fZ;
    orxFrame_SetPosition(pstFrame, eFrameSpace, &vNewPos);
  }
  else
  {
    orxVECTOR vPosition;

    /* Enforces its body properties */
    orxPhysics_SetRotation(_pstBody, orxFrame_GetRotation(pstFrame, eFrameSpace));
    orxPhysics_SetAngularVelocity(_pstBody, orxFLOAT_0);
    orxPhysics_SetPosition(_pstBody, orxFrame_GetPosition(pstFrame, eFrameSpace, &vPosition));
    orxPhysics_SetSpeed(_pstBody, &orxVECTOR_0);
  }

  /* Profiles */
  orxPROFILER_POP_MARKER();

  /* Done! */
  return;
}