DialoguePanel::DialoguePanel(wxWindow *parentWindow)
                : wxPanel(parentWindow)
                {
                    //this->SetBackgroundColour(wxColour(0, 255, 0)); // Makes the background green so that it's easy to see

                    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

                    scWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);
                    //scWindow->SetScrollRate(0,5); //Maybe useless
                    scWindow->SetScrollbars(0, 20, 0, 50);

                    lblHistory = new wxStaticText(scWindow, wxID_ANY, wxT("CHAT HISTORY"), wxDefaultPosition, wxSize(650, -1), 0);
                    //lblHistory = new wxStaticText(scWindow, wxID_ANY, wxT("wxTextCtrl text format The multiline text controls always store the text as a sequence of lines separated by \n characters, i.e. in the Unix text format even on non-Unix platforms. This allows the user code to ignore the differences between the platforms but at a price: the indices in the control such as those returned by GetInsertionPoint or GetSelection can not be used as indices into the string returned by GetValue as they're going to be slightly off for platforms using \r\n as separator (as Windows does), for example.Instead, if you need to obtain a substring between the 2 indices obtained from the control with the help of the functions mentioned above, you should use GetRange. And the indices themselves can only be passed to other methods, for example SetInsertionPoint or SetSelection.To summarize: never use the indices returned by (multiline) wxTextCtrl as indices into the string it contains, but only as arguments to be passed back to the other wxTextCtrl methods."), wxDefaultPosition, wxSize(650,-1),0);
                    lblHistory->Wrap(650);

                    txtInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(650, -1), wxTE_PROCESS_ENTER);
                    txtInput->SetMaxLength(128);

                    sizer->Add(txtInput, 0, wxALL, 5);
                    sizer->Add(scWindow, 1, wxALL, 5);

                    this->SetSizer(sizer);
                    this->Layout();

                    txtInput->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(DialoguePanel::onEnterPressed), NULL, this);

                    publisher = eu::nifti::ocu::NIFTiROSUtil::getNodeHandle()->advertise<eu_nifti_ocu_msg_ros::DialogueUtteranceMessage > (DIALOGUE_TOPIC, 1);
                    subscriber = eu::nifti::ocu::NIFTiROSUtil::getNodeHandle()->subscribe(DIALOGUE_TOPIC, 10, &DialoguePanel::onDialogueUtteranceMessageReceived, this);
                }