void  ViewPort::siftWindowOnRight()
{
	float delta = -2*width()/(100.0*param_matrixWorld.m11());
	moveView(QPointF(delta,0));
}