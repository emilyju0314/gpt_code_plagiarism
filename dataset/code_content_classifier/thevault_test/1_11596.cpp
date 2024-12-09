void aieProject2D1App::update(float deltaTime) 
{







	//ImGui::ColorEdit3("clear colour", glm::value_ptr(m_v4ClearColor));

	// clear the OpenGL backbuffer in preparation for rendering
	//glClearColor(m_v4ClearColor.r, m_v4ClearColor.g, m_v4ClearColor.b, 1);





	
	// clear gizmos
	aie::Gizmos::clear();
	
	// Update scene
	m_pPhysicsScene->Update(deltaTime);
	m_pPhysicsScene->UpdateGizmos();

	// get input instance
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}