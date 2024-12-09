void SpotlightRenderInfos::clearRenderInfos(const DRBCameraDrawableList &infos)
	{
		SCOPE_profile_cpu_function("RenderTimer");

		AGE_ASSERT(IsRenderThread());

		for (auto &e : _spotlights)
		{
			if (e.meshs)
			{
				e.meshs->reset();
				BasicCommandGeneration::MeshShadowOutput::RecycleOutput(e.meshs);
			}
			if (e.skinnedMeshs)
			{
				e.skinnedMeshs->reset();
				BasicCommandGeneration::SkinnedShadowOutput::RecycleOutput(e.skinnedMeshs);
			}
		}
		_cameras.clear();
		_spotlights.clear();
	}