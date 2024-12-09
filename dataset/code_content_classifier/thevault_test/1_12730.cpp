Node* Tree::SearchJoint(Node* node, int index)
{
	Node* ret;
	if (node != 0) {
		if (node->seqNumJoint == index) {
			return node;
		} else {
			if (ret = SearchJoint(node->left, index)) {
				return ret;
			}
			if (ret = SearchJoint(node->right, index)) {
				return ret;
			}
			return NULL;
		}
	} 
	else {
		return NULL;
	}
}