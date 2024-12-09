static void orxFASTCALL orxPhysics_Box2D_Update(const orxCLOCK_INFO *_pstClockInfo, void *_pContext)
{
  orxPHYSICS_EVENT_STORAGE *pstEventStorage;
  b2Body                   *poBody;

  /* Profiles */
  orxPROFILER_PUSH_MARKER("orxPhysics_Update");

  /* Checks */
  orxASSERT(sstPhysics.u32Flags & orxPHYSICS_KU32_STATIC_FLAG_READY);
  orxASSERT(_pstClockInfo != orxNULL);

  /* For all physical bodies */
  for(poBody = sstPhysics.poWorld->GetBodyList();
      poBody != NULL;
      poBody = poBody->GetNext())
  {
    orxOBJECT  *pstObject;
    orxBODY    *pstBody;

    /* Gets associated body */
    pstBody = orxBODY(poBody->GetUserData());

    /* Gets owner object */
    pstObject = orxOBJECT(orxStructure_GetOwner(pstBody));

    /* Is enabled? */
    if(orxObject_IsEnabled(pstObject) != orxFALSE)
    {
      orxFRAME   *pstFrame;
      orxVECTOR   vSpeed, vGravity;
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
          fCoef = pstClockInfo->fModValue;
        }
      }

      /* Enforces its activation state */
      poBody->SetActive(true);

      /* Gets owner's frame */
      pstFrame = orxOBJECT_GET_STRUCTURE(pstObject, FRAME);

      /* Gets its body speed */
      orxBody_GetSpeed(pstBody, &vSpeed);

      /* Is not a root child? */
      if(orxFrame_IsRootChild(pstFrame) == orxFALSE)
      {
        orxVECTOR vPos, vScale;
        orxFRAME *pstParentFrame;

        /* Updates body position & rotation */
        orxPhysics_SetPosition((orxPHYSICS_BODY *)poBody, orxFrame_GetPosition(pstFrame, orxFRAME_SPACE_GLOBAL, &vPos));
        orxPhysics_SetRotation((orxPHYSICS_BODY *)poBody, orxFrame_GetRotation(pstFrame, orxFRAME_SPACE_GLOBAL));

        /* Gets parent frame */
        pstParentFrame = orxFRAME(orxStructure_GetParent(pstFrame));

        /* Updates speed according to parent scale & rotation */
        orxVector_2DRotate(&vSpeed, &vSpeed, orxFrame_GetRotation(pstParentFrame, orxFRAME_SPACE_GLOBAL));
        orxVector_Mul(&vSpeed, &vSpeed, orxFrame_GetScale(pstParentFrame, orxFRAME_SPACE_GLOBAL, &vScale));
      }

      /* Applies speed & angular velocity */
      orxPhysics_SetSpeed((orxPHYSICS_BODY *)poBody, orxVector_Mulf(&vSpeed, &vSpeed, fCoef));
      orxPhysics_SetAngularVelocity((orxPHYSICS_BODY *)poBody, fCoef * orxBody_GetAngularVelocity(pstBody));

      /* No custom gravity */
      if(orxBody_GetCustomGravity(pstBody, &vGravity) == orxNULL)
      {
        /* Uses world gravity */
        orxPhysics_GetGravity(&vGravity);
      }

      /* Applies modified gravity */
      orxPhysics_SetCustomGravity((orxPHYSICS_BODY *)poBody, orxVector_Mulf(&vGravity, &vGravity, fCoef * fCoef));
    }
    else
    {
      /* Is still active? */
      if(poBody->IsActive() != false)
      {
        /* Deactivates it */
        poBody->SetActive(false);
      }
    }
  }

  /* Is simulation enabled? */
  if(orxFLAG_TEST(sstPhysics.u32Flags, orxPHYSICS_KU32_STATIC_FLAG_ENABLED))
  {
    orxU32 u32Steps, i;

    /* Stores DT */
    sstPhysics.fLastDT = _pstClockInfo->fDT;

    /* Updates DT accumulator */
    sstPhysics.fDTAccumulator += _pstClockInfo->fDT;

    /* Computes the number of steps */
    u32Steps = (orxU32)orxMath_Floor((sstPhysics.fDTAccumulator + orxMATH_KF_EPSILON) / sstPhysics.fFixedDT);

    /* For all steps */
    for(i = 0; i < u32Steps; i++)
    {
      /* Updates world simulation */
      sstPhysics.poWorld->Step(sstPhysics.fFixedDT, sstPhysics.u32Iterations, sstPhysics.u32Iterations >> 1);
    }

    /* Updates accumulator */
    sstPhysics.fDTAccumulator -= orxU2F(u32Steps) * sstPhysics.fFixedDT;

    /* Not absolute fixed DT? */
    if(!orxFLAG_TEST(sstPhysics.u32Flags, orxPHYSICS_KU32_STATIC_FLAG_FIXED_DT))
    {
      /* Updates last step of world simulation */
      sstPhysics.poWorld->Step(sstPhysics.fDTAccumulator, sstPhysics.u32Iterations, sstPhysics.u32Iterations >> 1);

      /* Clears accumulator */
      sstPhysics.fDTAccumulator = orxFLOAT_0;
    }

    /* Clears forces */
    sstPhysics.poWorld->ClearForces();

    /* For all physical bodies */
    for(poBody = sstPhysics.poWorld->GetBodyList();
        poBody != NULL;
        poBody = poBody->GetNext())
    {
      /* Non-static and awake? */
      if((poBody->GetType() != b2_staticBody)
      && (poBody->IsAwake() != false))
      {
        /* Applies simulation result */
        orxPhysics_ApplySimulationResult((orxPHYSICS_BODY *)poBody);
      }
    }

    /* For all stored events */
    for(pstEventStorage = (orxPHYSICS_EVENT_STORAGE *)orxLinkList_GetFirst(&(sstPhysics.stEventList));
        pstEventStorage != orxNULL;
        pstEventStorage = (orxPHYSICS_EVENT_STORAGE *)orxLinkList_GetNext(&(pstEventStorage->stNode)))
    {
      /* Depending on type */
      switch(pstEventStorage->eID)
      {
        case orxPHYSICS_EVENT_CONTACT_ADD:
        case orxPHYSICS_EVENT_CONTACT_REMOVE:
        {
          /* New contact? */
          if(pstEventStorage->eID == orxPHYSICS_EVENT_CONTACT_ADD)
          {
            b2Vec2 vPos;

            /* Source can't slide and destination is static? */
            if(!pstEventStorage->poSource->CanSlide() && (pstEventStorage->poDestination->GetType() != b2_dynamicBody))
            {
              /* Gets current position */
              vPos = pstEventStorage->poSource->GetPosition();

              /* Grounds it*/
              vPos.y += 0.01f;

              /* Updates it */
              pstEventStorage->poSource->SetTransform(vPos, pstEventStorage->poSource->GetAngle());
            }
            /* Destination can't slide and source is static? */
            else if(!pstEventStorage->poDestination->CanSlide() && (pstEventStorage->poSource->GetType() != b2_dynamicBody))
            {
              /* Gets current position */
              vPos = pstEventStorage->poDestination->GetPosition();

              /* Grounds it*/
              vPos.y += 0.01f;

              /* Updates it */
              pstEventStorage->poDestination->SetTransform(vPos, pstEventStorage->poDestination->GetAngle());
            }
          }

          /* Sends event */
          orxEVENT_SEND(orxEVENT_TYPE_PHYSICS, pstEventStorage->eID, orxStructure_GetOwner(orxBODY(pstEventStorage->poSource->GetUserData())), orxStructure_GetOwner(orxBODY(pstEventStorage->poDestination->GetUserData())), &(pstEventStorage->stPayload));

          break;
        }

        default:
        {
          break;
        }
      }
    }

    /* Clears stored events */
    orxLinkList_Clean(&(sstPhysics.stEventList));
    orxBank_Clear(sstPhysics.pstEventBank);
  }

  /* Profiles */
  orxPROFILER_POP_MARKER();

  /* Done! */
  return;
}