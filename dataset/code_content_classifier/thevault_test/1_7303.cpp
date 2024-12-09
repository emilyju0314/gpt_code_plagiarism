void Fl_File_Chooser::preview(int e)
{
  previewButton->value(e);
  prefs_.set("preview", e);
  prefs_.flush();

  Fl_Group *p = previewBox->parent();
  if (e) {
    int w = p->w() * 2 / 3;
    fileList->resize(fileList->x(), fileList->y(),
                     w, fileList->h());
    previewBox->resize(fileList->x()+w, previewBox->y(),
                       p->w()-w, previewBox->h());
    previewBox->show();
    update_preview();
  } else {
    fileList->resize(fileList->x(), fileList->y(),
                     p->w(), fileList->h());
    previewBox->resize(p->x()+p->w(), previewBox->y(),
                       0, previewBox->h());
    previewBox->hide();
  }
  p->init_sizes();

  fileList->parent()->redraw();
}