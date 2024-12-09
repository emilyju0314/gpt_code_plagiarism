void SmokeRenderer::drawPointSprites(GLSLProgram *prog, int start, int count, bool shadowed)
{
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);  // don't write depth
    glEnable(GL_BLEND);

    prog->enable();
    prog->setUniform1f("pointRadius", mParticleRadius);
	if (shadowed) {
		prog->bindTexture("shadowTex", m_lightTexture[m_srcLightTexture], GL_TEXTURE_2D, 0);
	}

    // draw points
    drawPoints(start, count, true);

    prog->disable();

    glDepthMask(GL_TRUE);
    glDisable(GL_BLEND);
}