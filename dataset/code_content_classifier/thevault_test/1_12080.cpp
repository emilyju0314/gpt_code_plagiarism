void TressFXSimulation::UpdateHairSkinning(EI_CommandContext& commandContext, std::vector<TressFXHairObject*>& hairObjects)
{
    // Adi: binding the m_SimCB buffers (matrices, wind parameters..) to the GPU 
    for (int i = 0; i < hairObjects.size(); ++i)
    {
        hairObjects[i]->UpdateConstantBuffer(commandContext);
    }

    // Adi: only skin hair vertices without any physics. 
    DispatchComputeShader(commandContext, mSkinHairVerticesTestPSO.get(), DISPATCHLEVEL_VERTEX, hairObjects);
    GetDevice()->GetTimeStamp("SkinHairVerticesTestPSO");
    

    // UpdateFollowHairVertices - This part is embedded in the single pass shader
//    DispatchComputeShader(commandContext, mUpdateFollowHairVerticesPSO.get(), DISPATCHLEVEL_VERTEX, hairObjects);
//    GetDevice()->GetTimeStamp("UpdateFollowHairVertices");

    // Adi: make sure the dual buffers are updated properly - advance the current frame 
    for (int i = 0; i < hairObjects.size(); ++i)
    {
        hairObjects[i]->IncreaseSimulationFrame();
    }
}