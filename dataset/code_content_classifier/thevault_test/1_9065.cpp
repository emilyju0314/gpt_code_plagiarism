void ImGui_ImplGlfw_RenderDrawLists(ImDrawData* draw_data)
{
    if (draw_data->CmdListsCount == 0)
        return;

    // Setup render state: alpha-blending enabled, no face culling, no depth testing, scissor enabled, vertex/texcoord/color pointers.
    GLint last_texture;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
    // glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_TRANSFORM_BIT);
    PushState blend(GL_BLEND), cull(GL_CULL_FACE), depthTest(GL_DEPTH_TEST),
        scissorTest(GL_SCISSOR_TEST), texture(GL_TEXTURE_2D);
    GLint prog = 0;
    glGetIntegerv(GL_CURRENT_PROGRAM, &prog);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_SCISSOR_TEST);
    glEnableVertexAttribArray(g->Position);
    glEnableVertexAttribArray(g->TexCoord);
    glEnableVertexAttribArray(g->Color);
    glEnable(GL_TEXTURE_2D);


    //glUseProgram(0); // You may want this if using this code in an OpenGL 3+ context
    glUseProgram(g->Program);
    glActiveTexture(GL_TEXTURE0);
    glUniform1i(g->Texture, 0);

    // Handle cases of screen coordinates != from framebuffer coordinates (e.g. retina displays)
    ImGuiIO& io = ImGui::GetIO();
    float fb_height = io.DisplaySize.y * io.DisplayFramebufferScale.y;
    draw_data->ScaleClipRects(io.DisplayFramebufferScale);

    glm::mat4 ortho = glm::ortho(0.0f, io.DisplaySize.x, io.DisplaySize.y, 0.0f);
    glUniformMatrix4fv(g->ModelViewProjection, 1, GL_FALSE, &ortho[0][0]);

    // Render command lists
    #define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))
    for (int n = 0; n < draw_data->CmdListsCount; n++)
    {
        const ImDrawList* cmd_list = draw_data->CmdLists[n];
        const unsigned char* vtx_buffer = (const unsigned char*)&cmd_list->VtxBuffer.front();
        const ImDrawIdx* idx_buffer = &cmd_list->IdxBuffer.front();
        glVertexAttribPointer(g->Position, 2, GL_FLOAT, GL_FALSE, sizeof(ImDrawVert), (void*)(vtx_buffer + OFFSETOF(ImDrawVert, pos)));
        glVertexAttribPointer(g->TexCoord, 2, GL_FLOAT, GL_FALSE, sizeof(ImDrawVert), (void*)(vtx_buffer + OFFSETOF(ImDrawVert, uv)));
        glVertexAttribPointer(g->Color, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(ImDrawVert), (void*)(vtx_buffer + OFFSETOF(ImDrawVert, col)));

        for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.size(); cmd_i++)
        {
            const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
            if (pcmd->UserCallback)
            {
                pcmd->UserCallback(cmd_list, pcmd);
            }
            else
            {
                glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
                glScissor((int)pcmd->ClipRect.x, (int)(fb_height - pcmd->ClipRect.w), (int)(pcmd->ClipRect.z - pcmd->ClipRect.x), (int)(pcmd->ClipRect.w - pcmd->ClipRect.y));
                glDrawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount, GL_UNSIGNED_SHORT, idx_buffer);
            }
            idx_buffer += pcmd->ElemCount;
        }
    }
    #undef OFFSETOF

    glDisableVertexAttribArray(g->Position);
    glDisableVertexAttribArray(g->TexCoord);
    glDisableVertexAttribArray(g->Color);

    // Restore modified state
    glBindTexture(GL_TEXTURE_2D, last_texture);

    // Restore GL state. PushState destructor automatically reset saved value.
    //glPopAttrib();
    glUseProgram(prog);
}