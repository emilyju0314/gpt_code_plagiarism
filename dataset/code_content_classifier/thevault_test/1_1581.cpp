void PlotWindow::changePlotLabels() {
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Name Plot Labels");

    QGridLayout *dialogLayout = new QGridLayout;

    int row = 0;
    QLabel *plotLabel = new QLabel("Plot Title: ");
    dialogLayout->addWidget(plotLabel, row, 0);

    m_plotTitleText = new QLineEdit(plot()->title().text());
    dialogLayout->addWidget(m_plotTitleText, row, 1);
    row++;

    QLabel *xAxisLabel = new QLabel("X-Axis Label: ");
    dialogLayout->addWidget(xAxisLabel, row, 0);

    m_xAxisText = new QLineEdit(m_plot->axisTitle(QwtPlot::xBottom).text());
    dialogLayout->addWidget(m_xAxisText, row, 1);
    row++;

    QLabel *yAxisLabel = new QLabel("Y-Axis Label: ");
    dialogLayout->addWidget(yAxisLabel, row, 0);

    m_yAxisText = new QLineEdit(m_plot->axisTitle(QwtPlot::yLeft).text());
    dialogLayout->addWidget(m_yAxisText, row, 1);
    row++;

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch();

    QPushButton *okButton = new QPushButton("&Ok");
    okButton->setIcon(QIcon::fromTheme("dialog-ok"));
    connect(okButton, SIGNAL(clicked()), dialog, SLOT(accept()));
    connect(dialog, SIGNAL(accepted()), this, SLOT(setLabels()));
    okButton->setShortcut(Qt::Key_Enter);
    buttonsLayout->addWidget(okButton);

    QPushButton *cancelButton = new QPushButton("&Cancel");
    cancelButton->setIcon(QIcon::fromTheme("dialog-cancel"));
    connect(cancelButton, SIGNAL(clicked()), dialog, SLOT(reject()));
    buttonsLayout->addWidget(cancelButton);

    QWidget *buttonsWrapper = new QWidget;
    buttonsWrapper->setLayout(buttonsLayout);
    dialogLayout->addWidget(buttonsWrapper, row, 0, 1, 2);
    row++;

    dialog->setLayout(dialogLayout);
    dialog->show();
  }