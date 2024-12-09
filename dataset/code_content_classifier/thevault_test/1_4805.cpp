BencEntity::BencEntity(const BencEntity& be)
{
	ZeroOut();
	MoveFrom( const_cast<BencEntity&>( be ) );
}