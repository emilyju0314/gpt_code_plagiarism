void SubsDataGroupManager::initialize()
	{
		initializeCBStore(8000);

		UEContextManagerm_p = new UEContextManager(8000);
		MmContextManagerm_p = new MmContextManager(8000);
		SessionContextManagerm_p = new SessionContextManager(8000);
		BearerContextManagerm_p = new BearerContextManager(8000);
		MmeProcedureCtxtManagerm_p = new MmeProcedureCtxtManager(8000);
		MmeAttachProcedureCtxtManagerm_p = new MmeAttachProcedureCtxtManager(8000);
		MmeDetachProcedureCtxtManagerm_p = new MmeDetachProcedureCtxtManager(8000);
		MmeS1RelProcedureCtxtManagerm_p = new MmeS1RelProcedureCtxtManager(8000);
		MmeSvcReqProcedureCtxtManagerm_p = new MmeSvcReqProcedureCtxtManager(8000);
		MmeTauProcedureCtxtManagerm_p = new MmeTauProcedureCtxtManager(8000);
		S1HandoverProcedureContextManagerm_p = new S1HandoverProcedureContextManager(8000);
		MmeErabModIndProcedureCtxtManagerm_p = new MmeErabModIndProcedureCtxtManager(8000);
	}