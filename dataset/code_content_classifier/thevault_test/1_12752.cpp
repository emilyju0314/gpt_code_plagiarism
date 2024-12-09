void HingeJoint::ComputeW(void)
{
	Node* y = this->realparent;
	vector3 temp;
	temp.rotate(_global.rotation,v);
	//printf("%s %s\n", w.output().ptr(), temp.output().ptr());
	w=temp;
}