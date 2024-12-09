void CameraRenderInfos::clearRenderInfos(const DRBCameraDrawableList &infos)
	{
		SCOPE_profile_cpu_function("RenderTimer");

		AGE_ASSERT(IsRenderThread());

		for (auto &e : _meshs)
		{
			if (e.meshs)
			{
				e.meshs->reset();
				MeshOutput::RecycleOutput(e.meshs);
			}
			if (e.skinnedMeshs)
			{
				e.skinnedMeshs->reset();
				SkinnedOutput::RecycleOutput(e.skinnedMeshs);
			}
		}
		_cameras.clear();
		_meshs.clear();
	}