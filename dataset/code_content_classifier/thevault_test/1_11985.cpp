void GLSLShader::SetUniformTextureID(const char* name, uint32 textureID)
    {
        const size_t index = FindUniformIndex(name);
        if (index == InvalidIndex)
        {
            return;
        }

        m_uniforms[index].m_type = GL_SAMPLER_2D; // why is this being set here?

        // if the texture doesn't have a sampler unit assigned, give it one
        if (m_uniforms[index].m_textureUnit == MCORE_INVALIDINDEX32)
        {
            m_uniforms[index].m_textureUnit = m_textureUnit;
            m_textureUnit++;
        }

        if (textureID == MCORE_INVALIDINDEX32)
        {
            textureID = GetGraphicsManager()->GetTextureCache()->GetWhiteTexture()->GetID();
        }

        glActiveTexture(GL_TEXTURE0 + m_uniforms[index].m_textureUnit);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glUniform1i(m_uniforms[index].m_location, m_uniforms[index].m_textureUnit);

        m_activatedTextures.emplace_back(index);
    }