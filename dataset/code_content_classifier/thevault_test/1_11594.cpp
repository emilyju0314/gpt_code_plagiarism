bool aieProject2D1App::startup() 
{
	// Create a new instance of the Renderer2D.
	m_2dRenderer = new aie::Renderer2D();
	
	// increase the 2d line count to maximize the number of objects we can draw
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	// Set up the physics scene
	m_pPhysicsScene = new PhysicsScene();
	m_pPhysicsScene->SetGravity(glm::vec2(0, -10));
	m_pPhysicsScene->SetTimeStep(0.003f);








	Sphere* ball1 = new Sphere(glm::vec2(-16, 0), glm::vec2(0, 0), 3.0f, 1.0f, glm::vec4(1, 0, 0, 1));
	Sphere* ball2 = new Sphere(glm::vec2(16, 0), glm::vec2(0, 0), 3.0f, 1.0f, glm::vec4(0, 1, 0, 1));
	Sphere* ball3 = new Sphere(glm::vec2(32, 16), glm::vec2(0, 0), 3.0f, 1.0f, glm::vec4(0.75f, 0.75f, 0.75f, 1));
	Sphere* ball4 = new Sphere(glm::vec2(-16, 16), glm::vec2(0, 0), 3.0f, 1.0f, glm::vec4(1, 0.5f, 0, 1));

	Box* box1 = new Box(glm::vec2(-16, 32), glm::vec2(0, 0), 3.0f, 1.0f, 1.0f, glm::vec4(0, 0, 1, 1));
	Box* box2 = new Box(glm::vec2(16, 32), glm::vec2(0, 0), 3.0f, 1.0f, 1.0f, glm::vec4(1, 1, 0, 1));
	Box* box3 = new Box(glm::vec2(-32, 16), glm::vec2(0, 0), 3.0f, 1.0f, 1.0f, glm::vec4(1, 0.5f, 0.76f, 1));
	Box* box4 = new Box(glm::vec2(16, 16), glm::vec2(0, 0), 3.0f, 1.0f, 1.0f, glm::vec4(0.5f, 0, 0.7f, 1));

	Plane* plane1 = new Plane(glm::normalize(glm::vec2(-1, 10)), -30);
	Plane* plane2 = new Plane(glm::normalize(glm::vec2(-10, 10)), -30);
	Plane* plane3 = new Plane(glm::normalize(glm::vec2(10, 0)), -50);

	m_pPhysicsScene->AddActor(ball1);
	m_pPhysicsScene->AddActor(ball2);
	m_pPhysicsScene->AddActor(ball3);
	m_pPhysicsScene->AddActor(ball4);
					 
	m_pPhysicsScene->AddActor(box1);
	m_pPhysicsScene->AddActor(box2);
	m_pPhysicsScene->AddActor(box3);
	m_pPhysicsScene->AddActor(box4);

	m_pPhysicsScene->AddActor(plane1);
	m_pPhysicsScene->AddActor(plane2);
	m_pPhysicsScene->AddActor(plane3);

	ball1->ApplyForce(glm::vec2(50, 0));
	ball2->ApplyForce(glm::vec2(-50, 0));
	ball3->ApplyForce(glm::vec2(0, -25));
	ball4->ApplyForce(glm::vec2(50, 0));

	box1->ApplyForce(glm::vec2(50, 0));
	box2->ApplyForce(glm::vec2(-50, 0));
	box3->ApplyForce(glm::vec2(0, -25));
	box4->ApplyForce(glm::vec2(-50, 0));










	// return
	return true;
}