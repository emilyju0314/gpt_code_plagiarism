void aieProject2D1App::shutdown() 
{
	// delete renderer
	delete m_2dRenderer;

	// delete gizmos
	aie::Gizmos::destroy();

	// delete scene
	delete m_pPhysicsScene;
}