bool Context::applyRenderTarget(bool ignoreViewport)
{
    IDirect3DDevice9 *device = getDevice();

    Framebuffer *framebufferObject = getDrawFramebuffer();

    if (!framebufferObject || framebufferObject->completeness() != GL_FRAMEBUFFER_COMPLETE)
    {
        error(GL_INVALID_FRAMEBUFFER_OPERATION);

        return false;
    }

    IDirect3DSurface9 *renderTarget = framebufferObject->getRenderTarget();

    if (!renderTarget)
    {
        return false;   // Context must be lost
    }

    IDirect3DSurface9 *depthStencil = NULL;

    unsigned int renderTargetSerial = framebufferObject->getRenderTargetSerial();
    if (renderTargetSerial != mAppliedRenderTargetSerial)
    {
        device->SetRenderTarget(0, renderTarget);
        mAppliedRenderTargetSerial = renderTargetSerial;
        mScissorStateDirty = true; // Scissor area must be clamped to render target's size-- this is different for different render targets.
    }

    unsigned int depthbufferSerial = 0;
    unsigned int stencilbufferSerial = 0;
    if (framebufferObject->getDepthbufferType() != GL_NONE)
    {
        depthStencil = framebufferObject->getDepthbuffer()->getDepthStencil();
        if (!depthStencil)
        {
            ERR("Depth stencil pointer unexpectedly null.");
            return false;
        }
        
        depthbufferSerial = framebufferObject->getDepthbuffer()->getSerial();
    }
    else if (framebufferObject->getStencilbufferType() != GL_NONE)
    {
        depthStencil = framebufferObject->getStencilbuffer()->getDepthStencil();
        if (!depthStencil)
        {
            ERR("Depth stencil pointer unexpectedly null.");
            return false;
        }
        
        stencilbufferSerial = framebufferObject->getStencilbuffer()->getSerial();
    }

    if (depthbufferSerial != mAppliedDepthbufferSerial ||
        stencilbufferSerial != mAppliedStencilbufferSerial ||
        !mDepthStencilInitialized)
    {
        device->SetDepthStencilSurface(depthStencil);
        mAppliedDepthbufferSerial = depthbufferSerial;
        mAppliedStencilbufferSerial = stencilbufferSerial;
        mDepthStencilInitialized = true;
    }

    D3DVIEWPORT9 viewport;
    D3DSURFACE_DESC desc;
    renderTarget->GetDesc(&desc);

    float zNear = clamp01(mState.zNear);
    float zFar = clamp01(mState.zFar);

    if (ignoreViewport)
    {
        viewport.X = 0;
        viewport.Y = 0;
        viewport.Width = desc.Width;
        viewport.Height = desc.Height;
        viewport.MinZ = 0.0f;
        viewport.MaxZ = 1.0f;
    }
    else
    {
        viewport.X = std::max(mState.viewportX, 0);
        viewport.Y = std::max(mState.viewportY, 0);
        viewport.Width = std::min(mState.viewportWidth, (int)desc.Width - (int)viewport.X);
        viewport.Height = std::min(mState.viewportHeight, (int)desc.Height - (int)viewport.Y);
        viewport.MinZ = zNear;
        viewport.MaxZ = zFar;
    }

    if (viewport.Width <= 0 || viewport.Height <= 0)
    {
        return false;   // Nothing to render
    }

    device->SetViewport(&viewport);

    if (mScissorStateDirty)
    {
        if (mState.scissorTest)
        {
            RECT rect = {mState.scissorX,
                         mState.scissorY,
                         mState.scissorX + mState.scissorWidth,
                         mState.scissorY + mState.scissorHeight};
            rect.right = std::min(static_cast<UINT>(rect.right), desc.Width);
            rect.bottom = std::min(static_cast<UINT>(rect.bottom), desc.Height);
            device->SetScissorRect(&rect);
            device->SetRenderState(D3DRS_SCISSORTESTENABLE, TRUE);
        }
        else
        {
            device->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
        }

        mScissorStateDirty = false;
    }

    if (mState.currentProgram)
    {
        Program *programObject = getCurrentProgram();

        GLint halfPixelSize = programObject->getDxHalfPixelSizeLocation();
        GLfloat xy[2] = {1.0f / viewport.Width, 1.0f / viewport.Height};
        programObject->setUniform2fv(halfPixelSize, 1, xy);

        GLint viewport = programObject->getDxViewportLocation();
        GLfloat whxy[4] = {mState.viewportWidth / 2.0f, mState.viewportHeight / 2.0f, 
                          (float)mState.viewportX + mState.viewportWidth / 2.0f, 
                          (float)mState.viewportY + mState.viewportHeight / 2.0f};
        programObject->setUniform4fv(viewport, 1, whxy);

        GLint depth = programObject->getDxDepthLocation();
        GLfloat dz[2] = {(zFar - zNear) / 2.0f, (zNear + zFar) / 2.0f};
        programObject->setUniform2fv(depth, 1, dz);

        GLint depthRange = programObject->getDxDepthRangeLocation();
        GLfloat nearFarDiff[3] = {zNear, zFar, zFar - zNear};
        programObject->setUniform3fv(depthRange, 1, nearFarDiff);
    }

    return true;
}