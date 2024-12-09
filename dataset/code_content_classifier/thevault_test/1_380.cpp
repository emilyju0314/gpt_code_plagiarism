P4RInitBlockNode::P4RInitBlockNode(AstNode* name, AstNode* body) {
    nodeType_ = typeid(*this).name();
    name_ = dynamic_cast<NameNode*>(name);
    name_->parent_ = this;
    body_ = dynamic_cast<BodyNode*>(body);
    body_->parent_ = this;
}