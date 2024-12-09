void Player::AddMovementInput(const EMovementInputDirection& Direction, float Value)
{
	if (!Input::IsGameFrozen)
	{
		m_OldPosition = m_Position;
		switch (Direction)
		{
			case MID_FORWARD:
			{
				m_Position += m_MovementSpeed * m_pPlayerCamera->m_Front * Value;
				break;
			}
			case MID_BACKWARD:
			{
				m_Position -= m_MovementSpeed * m_pPlayerCamera->m_Front * Value;
				break;
			}
			case MID_RIGHT:
			{
				m_Position += m_MovementSpeed * m_pPlayerCamera->m_Right * Value;
				break;
			}
			case MID_LEFT:
			{
				m_Position -= m_MovementSpeed * m_pPlayerCamera->m_Right * Value;
				break;
			}
		}
		m_pPlayerCamera->UpdatePosition(m_Position);
	}
}