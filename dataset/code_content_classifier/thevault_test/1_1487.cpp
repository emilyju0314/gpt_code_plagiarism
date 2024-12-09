ProjectItem::ProjectItem(TemplateList *templateList) {

    setTextColor(Qt::black);
    setEditable(false);
    setTemplateList(templateList);
    foreach (Template *currentTemplate, *templateList) {
      appendRow(new ProjectItem(currentTemplate));
    }
  }