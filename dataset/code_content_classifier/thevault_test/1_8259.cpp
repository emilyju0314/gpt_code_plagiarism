void ScribbleArea::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() == Qt::LeftButton) && isDrawing)
        drawLineTo(event->pos());
}