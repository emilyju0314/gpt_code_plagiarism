void SceneDemo::render() {

    // Update the VBO for the debug infos
    updateDebugVBO();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glClearColor(mBackgroundColor.r, mBackgroundColor.g, mBackgroundColor.b, mBackgroundColor.a);

	Matrix4 shadowMapProjMatrix[NB_SHADOW_MAPS];
	openglframework::Matrix4 worldToLightCameraMatrix[NB_SHADOW_MAPS];
	for (int i = 0; i < NB_SHADOW_MAPS; i++) {

		shadowMapProjMatrix[i] = mShadowMapLightCameras[i].getProjectionMatrix();
		worldToLightCameraMatrix[i] = mShadowMapLightCameras[i].getTransformMatrix().getInverse();
	}

    // ---------- Render the scene to generate the shadow map (first pass) ----------- //

    // If Shadow Mapping is enabled
    if (mIsShadowMappingEnabled) {

        // Culling switching, rendering only backface, this is done to avoid self-shadowing
        glCullFace(GL_BACK);

		// For each shadow map
		for (int i = 0; i < NB_SHADOW_MAPS; i++) {

			mFBOShadowMap[i].bind();

			// Bind the shader
			mDepthShader.bind();

			// Set the variables of the shader
			mDepthShader.setMatrix4x4Uniform("projectionMatrix", shadowMapProjMatrix[i]);

			// Set the viewport to render into the shadow map texture
			glViewport(0, 0, SHADOWMAP_WIDTH, SHADOWMAP_HEIGHT);

			// Clear previous frame values
			glClear(GL_DEPTH_BUFFER_BIT);

			// Disable color rendering, we only want to write to the Z-Buffer
			glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

			// Render the objects of the scene
			renderSinglePass(mDepthShader, worldToLightCameraMatrix[i]);

			// Unbind the shader
			mDepthShader.unbind();

			mFBOShadowMap[i].unbind();
		}

        glDisable(GL_POLYGON_OFFSET_FILL);
    }

    // ---------- Render the scene for final rendering (second pass) ----------- //

    glCullFace(GL_BACK);

    // Get the world-space to camera-space matrix
    const openglframework::Matrix4 worldToCameraMatrix = mCamera.getTransformMatrix().getInverse();

    mPhongShader.bind();

	// Is shadow mapping is enabled
	GLint textureUnits[NB_SHADOW_MAPS];
	if (mIsShadowMappingEnabled) {

		for (int i = 0; i < NB_SHADOW_MAPS; i++) {
			mShadowMapTexture[i].bind();
		}
		for (int i = 0; i < NB_SHADOW_MAPS; i++) {
			textureUnits[i] = mShadowMapTexture[i].getUnit();
		}
	}

    // Set the variables of the phong shader
    mPhongShader.setMatrix4x4Uniform("projectionMatrix", mCamera.getProjectionMatrix());
    mPhongShader.setMatrix4x4Uniform("shadowMapLight0ProjectionMatrix", mShadowMapBiasMatrix * shadowMapProjMatrix[0]);
    mPhongShader.setMatrix4x4Uniform("shadowMapLight1ProjectionMatrix", mShadowMapBiasMatrix * shadowMapProjMatrix[1]);
    mPhongShader.setMatrix4x4Uniform("worldToLight0CameraMatrix", worldToLightCameraMatrix[0]);
    mPhongShader.setMatrix4x4Uniform("worldToLight1CameraMatrix", worldToLightCameraMatrix[1]);
    mPhongShader.setVector3Uniform("light0PosCameraSpace", worldToCameraMatrix * mLight0.getOrigin());
    mPhongShader.setVector3Uniform("light1PosCameraSpace", worldToCameraMatrix * mLight1.getOrigin());
    mPhongShader.setVector3Uniform("light2PosCameraSpace", worldToCameraMatrix * mLight2.getOrigin());
    mPhongShader.setVector3Uniform("lightAmbientColor", Vector3(0.1f, 0.1f, 0.1f));
    mPhongShader.setVector3Uniform("light0DiffuseColor", Vector3(mLight0.getDiffuseColor().r, mLight0.getDiffuseColor().g, mLight0.getDiffuseColor().b));
    mPhongShader.setVector3Uniform("light1DiffuseColor", Vector3(mLight1.getDiffuseColor().r, mLight1.getDiffuseColor().g, mLight1.getDiffuseColor().b));
    mPhongShader.setVector3Uniform("light2DiffuseColor", Vector3(mLight2.getDiffuseColor().r, mLight2.getDiffuseColor().g, mLight2.getDiffuseColor().b));
    mPhongShader.setIntUniform("shadowMapSampler0", textureUnits[0]);
    mPhongShader.setIntUniform("shadowMapSampler1", textureUnits[1]);
    mPhongShader.setIntUniform("isShadowEnabled", mIsShadowMappingEnabled);
    mPhongShader.setVector2Uniform("shadowMapDimension", Vector2(SHADOWMAP_WIDTH, SHADOWMAP_HEIGHT));
	mPhongShader.unbind();

	// Set the variables of the color shader
	mColorShader.bind();
	mColorShader.setMatrix4x4Uniform("projectionMatrix", mCamera.getProjectionMatrix());
	mColorShader.unbind();

    // Set the viewport to render the scene
    glViewport(mViewportX, mViewportY, mViewportWidth, mViewportHeight);

    //Enabling color write (previously disabled for light POV z-buffer rendering)
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

    // Clear previous frame values
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Render the objects of the scene
    renderSinglePass(mPhongShader, worldToCameraMatrix);

    // Render the snapshots contact points
    renderSnapshotsContactPoints(mPhongShader, worldToCameraMatrix);

    // Render the debug infos
    if (mPhysicsWorld->getIsDebugRenderingEnabled()) {
        renderDebugInfos(mColorShader, worldToCameraMatrix);
    }

	// Is shadow mapping is enabled
	if (mIsShadowMappingEnabled) {

		for (int i = 0; i < NB_SHADOW_MAPS; i++) {
			mShadowMapTexture[i].unbind();
		}
	}

    mPhongShader.unbind();

   //drawTextureQuad();
}