void Node::ComputeS(void)
{
	Node* y = this->realparent;
	updateLocal();
	if (y)
		_global.mult(y->_global,_local);
	else
		_global=_local;
}