physx::PxCookingParams GetEditTimeCookingParams()
        {
            physx::PxCookingParams params{ physx::PxTolerancesScale() };
            // when set, mesh welding is performed - clean mesh must be enabled
            params.meshPreprocessParams |= physx::PxMeshPreprocessingFlag::eWELD_VERTICES;
            // note: default value in PxCookingParams is 0.0f;
            const float physx_CookWeldTolerance = 0.0001f;
            params.meshWeldTolerance = physx_CookWeldTolerance;

            return params;
        }