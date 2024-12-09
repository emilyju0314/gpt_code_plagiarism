void ChunkManager::render(GraphicsContext& context, const glm::mat4& vp)
{
  for (auto& chunk : chunks)
  {
    if (chunk != nullptr)
    {
      auto position = chunk->getPosition();
      auto model = glm::translate(glm::mat4(1.0f), position);
      auto mvp = vp * model;
      glUniformMatrix4fv(context.mvp(), 1, GL_FALSE, &mvp[0][0]);
      chunk->render(context);
    }
  }
}