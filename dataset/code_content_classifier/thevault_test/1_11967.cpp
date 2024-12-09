static void ForceWidgetRedraw(QWidget* widget)
    {
        widget->hide();
        widget->resize(widget->size());
        widget->show();
    }