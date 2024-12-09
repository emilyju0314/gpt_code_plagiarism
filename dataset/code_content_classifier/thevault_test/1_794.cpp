foreach (QWidget *widget, QApplication::topLevelWidgets())
	{

		if (widget->isWindow() && !widget->parentWidget ())//is a window without parent
		{
			temp = (CvWinModel*) widget;
			if (temp->type == type_CvWindow)
			{
				w = (CvWindow*) widget;
				//active window properties button
				w->vect_QActions[9]->setDisabled(false);
			}
		}
	}