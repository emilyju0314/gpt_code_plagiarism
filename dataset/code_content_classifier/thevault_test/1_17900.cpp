ControllerEditWidget::ControllerEditWidget(QWidget* parent, const MoveItConfigDataPtr& config_data)
  : QWidget(parent), config_data_(config_data)
{
  // Basic widget container
  QVBoxLayout* layout = new QVBoxLayout();

  QGroupBox* controller_options_group = new QGroupBox("Controller Options");

  // Label ------------------------------------------------
  title_ = new QLabel(this);  // specify the title from the parent widget
  QFont group_title_font(QFont().defaultFamily(), 12, QFont::Bold);
  title_->setFont(group_title_font);
  layout->addWidget(title_);

  QFormLayout* form_layout = new QFormLayout();
  form_layout->setContentsMargins(0, 15, 0, 15);

  // Controller Name
  controller_name_field_ = new QLineEdit(this);
  controller_name_field_->setMaximumWidth(400);
  form_layout->addRow("Controller Name:", controller_name_field_);

  // Controller Type
  controller_type_field_ = new QComboBox(this);
  controller_type_field_->setEditable(false);
  controller_type_field_->setMaximumWidth(400);
  form_layout->addRow("Controller Type:", controller_type_field_);

  controller_options_group->setLayout(form_layout);

  layout->addWidget(controller_options_group);

  layout->setAlignment(Qt::AlignTop);

  // New Controller Options  ---------------------------------------------------------
  new_buttons_widget_ = new QWidget();
  QVBoxLayout* new_buttons_layout = new QVBoxLayout();

  QLabel* save_and_add = new QLabel("Next, Add Components To Controller:", this);
  QFont save_and_add_font(QFont().defaultFamily(), 12, QFont::Bold);
  save_and_add->setFont(save_and_add_font);
  new_buttons_layout->addWidget(save_and_add);

  QLabel* add_subtitle = new QLabel("Recommended: ", this);
  QFont add_subtitle_font(QFont().defaultFamily(), 10, QFont::Bold);
  add_subtitle->setFont(add_subtitle_font);
  new_buttons_layout->addWidget(add_subtitle);

  // Save and add groups
  QPushButton* btn_save_groups_joints = new QPushButton("Add Planning Group Joints", this);
  btn_save_groups_joints->setMaximumWidth(200);
  connect(btn_save_groups_joints, SIGNAL(clicked()), this, SIGNAL(saveJointsGroups()));
  new_buttons_layout->addWidget(btn_save_groups_joints);

  QLabel* add_subtitle2 = new QLabel("Advanced Options:", this);
  add_subtitle2->setFont(add_subtitle_font);
  new_buttons_layout->addWidget(add_subtitle2);

  // Save and add joints
  QPushButton* btn_save_joints = new QPushButton("Add Individual Joints", this);
  btn_save_joints->setMaximumWidth(200);
  connect(btn_save_joints, SIGNAL(clicked()), this, SIGNAL(saveJoints()));
  new_buttons_layout->addWidget(btn_save_joints);

  // Create widget and add to main layout
  new_buttons_widget_->setLayout(new_buttons_layout);
  layout->addWidget(new_buttons_widget_);

  // Vertical Spacer
  layout->addItem(new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));

  // Bottom Controls ---------------------------------------------------------
  QHBoxLayout* controls_layout = new QHBoxLayout();

  // Delete
  btn_delete_ = new QPushButton("&Delete Controller", this);
  btn_delete_->setMaximumWidth(200);
  connect(btn_delete_, SIGNAL(clicked()), this, SIGNAL(deleteController()));
  controls_layout->addWidget(btn_delete_);
  controls_layout->setAlignment(btn_delete_, Qt::AlignRight);

  // Horizontal Spacer
  controls_layout->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

  // Save
  btn_save_ = new QPushButton("&Save", this);
  btn_save_->setMaximumWidth(200);
  connect(btn_save_, SIGNAL(clicked()), this, SIGNAL(save()));
  controls_layout->addWidget(btn_save_);
  controls_layout->setAlignment(btn_save_, Qt::AlignRight);

  // Cancel
  QPushButton* btn_cancel = new QPushButton("&Cancel", this);
  btn_cancel->setMaximumWidth(200);
  connect(btn_cancel, SIGNAL(clicked()), this, SIGNAL(cancelEditing()));
  controls_layout->addWidget(btn_cancel);
  controls_layout->setAlignment(btn_cancel, Qt::AlignRight);

  // Add layout
  layout->addLayout(controls_layout);

  // Finish Layout --------------------------------------------------
  this->setLayout(layout);
}