void  ViewPort::siftWindowOnDown()
{
	float delta = -2*height()/(100.0*param_matrixWorld.m11());
	moveView(QPointF(0,delta));
}