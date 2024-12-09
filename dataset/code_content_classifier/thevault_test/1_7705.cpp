void T02_PM_01_Base::RenderScene(std::shared_ptr<Shader> shader)
	{
		glm::mat4 matrix_temp = glm::mat4(1.0f);
		RenderScene(shader, matrix_temp, matrix_temp, true);
	}