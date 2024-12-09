void ViewPort::drawImgRegion(QPainter *painter)
{

	if (nbChannelOriginImage!=CV_8UC1 && nbChannelOriginImage!=CV_8UC3)
		return;

	qreal offsetX = param_matrixWorld.dx()/param_matrixWorld.m11();
	offsetX = offsetX - floor(offsetX);
	qreal offsetY = param_matrixWorld.dy()/param_matrixWorld.m11();
	offsetY = offsetY - floor(offsetY);

	QSize view = size();
	QVarLengthArray<QLineF, 30> linesX;
	for (qreal x = offsetX*param_matrixWorld.m11(); x < view.width(); x += param_matrixWorld.m11() )
		linesX.append(QLineF(x, 0, x, view.height()));

	QVarLengthArray<QLineF, 30> linesY;
	for (qreal y = offsetY*param_matrixWorld.m11(); y < view.height(); y += param_matrixWorld.m11() )
		linesY.append(QLineF(0, y, view.width(), y));


	QFont f = painter->font();
	int original_font_size = f.pointSize();
	//change font size
	//f.setPointSize(4+(param_matrixWorld.m11()-threshold_zoom_img_region)/5);
	f.setPixelSize(10+(param_matrixWorld.m11()-threshold_zoom_img_region)/5);
	painter->setFont(f);
	QString val;
	QRgb rgbValue;

	QPointF point1;//sorry, I do not know how to name it
	QPointF point2;//idem

	for (int j=-1;j<height()/param_matrixWorld.m11();j++)//-1 because display the pixels top rows left colums
		for (int i=-1;i<width()/param_matrixWorld.m11();i++)//-1
		{
			point1.setX((i+offsetX)*param_matrixWorld.m11());
			point1.setY((j+offsetY)*param_matrixWorld.m11());

			matrixWorld_inv.map(point1.x(),point1.y(),&point2.rx(),&point2.ry());

			point2.rx()= (long) (point2.x() + 0.5);
			point2.ry()= (long) (point2.y() + 0.5);

			if (point2.x() >= 0 && point2.y() >= 0)
				rgbValue = image2Draw_qt_resized.pixel(QPoint(point2.x(),point2.y()));
			else
				rgbValue = qRgb(0,0,0);

			if (nbChannelOriginImage==CV_8UC3)
			{
				//for debug
				/*
				val = tr("%1 %2").arg(point2.x()).arg(point2.y());
				painter->setPen(QPen(Qt::black, 1));
				painter->drawText(QRect(point1.x(),point1.y(),param_matrixWorld.m11(),param_matrixWorld.m11()/2),
					Qt::AlignCenter, val);
				*/

				val = tr("%1").arg(qRed(rgbValue));
				painter->setPen(QPen(Qt::red, 1));
				painter->drawText(QRect(point1.x(),point1.y(),param_matrixWorld.m11(),param_matrixWorld.m11()/3),
					Qt::AlignCenter, val);

				val = tr("%1").arg(qGreen(rgbValue));
				painter->setPen(QPen(Qt::green, 1));
				painter->drawText(QRect(point1.x(),point1.y()+param_matrixWorld.m11()/3,param_matrixWorld.m11(),param_matrixWorld.m11()/3),
					Qt::AlignCenter, val);

				val = tr("%1").arg(qBlue(rgbValue));
				painter->setPen(QPen(Qt::blue, 1));
				painter->drawText(QRect(point1.x(),point1.y()+2*param_matrixWorld.m11()/3,param_matrixWorld.m11(),param_matrixWorld.m11()/3),
					Qt::AlignCenter, val);

			}

			if (nbChannelOriginImage==CV_8UC1)
			{

				val = tr("%1").arg(qRed(rgbValue));
				painter->drawText(QRect(point1.x(),point1.y(),param_matrixWorld.m11(),param_matrixWorld.m11()),
					Qt::AlignCenter, val);
			}
		}

		painter->setPen(QPen(Qt::black, 1));
		painter->drawLines(linesX.data(), linesX.size());
		painter->drawLines(linesY.data(), linesY.size());

		//restore font size
		f.setPointSize(original_font_size);
		painter->setFont(f);

}