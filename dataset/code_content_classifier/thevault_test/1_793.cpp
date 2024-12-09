foreach (QWidget *widget, QApplication::topLevelWidgets())
	{

		if (widget->isWindow() && !widget->parentWidget ())//is a window without parent
		{
			temp = (CvWinModel*) widget;
			if (temp->type == type_CvWindow)
			{
			w = (CvWindow*) temp;
			if (name.compare(w->param_name)==0)
			{
				window = w;
				break;
			}
			}
		}
	}