Sphere::Sphere(glm::vec2 v2Position, glm::vec2 v2Velocity, float fMass, float fRadius, glm::vec4 v4Color) : Rigidbody(ESHAPETYPE_SPHERE, v2Position, v2Velocity, 0, fMass, 0.2f, 0.2f, 0.8f)
{
	// set sphere radius
	m_fRadius = fRadius;
	
	// set sphere color.
	m_v4Color = v4Color;
}