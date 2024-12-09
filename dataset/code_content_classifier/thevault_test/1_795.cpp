void CvWindow::readSettings()
{
	//organisation and application's name
	QSettings settings("OpenCV2", QFileInfo(QApplication::applicationFilePath()).fileName());
	QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
	QSize size = settings.value("size", QSize(400, 400)).toSize();
	//param_name = settings.value("name_window",param_name).toString();
	param_flags = settings.value("mode_resize",param_flags).toInt();
	param_gui_mode = settings.value("mode_gui",param_gui_mode).toInt();

	param_ratio_mode = settings.value("mode_ratio",param_ratio_mode).toInt();
	myview->param_keepRatio = settings.value("view_aspectRatio",myview->param_keepRatio).toInt();

	param_flags = settings.value("mode_resize",param_flags).toInt();
	qreal m11 = settings.value("matrix_view.m11",myview->param_matrixWorld.m11()).toDouble();
	qreal m12 = settings.value("matrix_view.m12",myview->param_matrixWorld.m12()).toDouble();
	qreal m13 = settings.value("matrix_view.m13",myview->param_matrixWorld.m13()).toDouble();
	qreal m21 = settings.value("matrix_view.m21",myview->param_matrixWorld.m21()).toDouble();
	qreal m22 = settings.value("matrix_view.m22",myview->param_matrixWorld.m22()).toDouble();
	qreal m23 = settings.value("matrix_view.m23",myview->param_matrixWorld.m23()).toDouble();
	qreal m31 = settings.value("matrix_view.m31",myview->param_matrixWorld.m31()).toDouble();
	qreal m32 = settings.value("matrix_view.m32",myview->param_matrixWorld.m32()).toDouble();
	qreal m33 = settings.value("matrix_view.m33",myview->param_matrixWorld.m33()).toDouble();
	myview->param_matrixWorld = QTransform(m11,m12,m13,m21,m22,m23,m31,m32,m33);

	//trackbar here
	icvLoadTrackbars(&settings);

	resize(size);
	move(pos);

	if (global_control_panel)
	{
		icvLoadControlPanel();
		global_control_panel->move(settings.value("posPanel", global_control_panel->pos()).toPoint());
	}
}