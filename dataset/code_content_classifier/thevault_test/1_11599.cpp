void Sphere::MakeGizmo()
{
	// Add a 2d circe gizmo.
	aie::Gizmos::add2DCircle(m_v2Position, m_fRadius, 12, m_v4Color);
}