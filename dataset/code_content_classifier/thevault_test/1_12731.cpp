Node* Tree::GetEffector(int index)
{
	assert(effectors[index]->seqNumEffector==index);
	return effectors[index];
}