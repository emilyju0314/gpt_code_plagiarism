AZ::RPI::ViewPtr CreateView(float fovY, float aspectRatio)
    {
        using namespace AZ;
        using namespace RPI;

        ViewPtr view =  View::CreateView(AZ::Name("TestView"), RPI::View::UsageCamera);

        AZ::Matrix4x4 worldToView = AZ::Matrix4x4::CreateIdentity();

        const float nearDist = 0.1f;
        const float farDist = 100.0f;
        AZ::Matrix4x4 viewToClip = AZ::Matrix4x4::CreateProjection(fovY, aspectRatio, nearDist, farDist);

        view->SetWorldToViewMatrix(worldToView);
        view->SetViewToClipMatrix(viewToClip);

        return view;
    }