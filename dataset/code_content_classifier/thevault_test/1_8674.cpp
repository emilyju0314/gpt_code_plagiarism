HRESULT EvaluateModel(
    const LearningModel& model,
    const CommandLineArgs& args,
    OutputHelper& output,
    DeviceType deviceType,
    InputBindingType inputBindingType,
    InputDataType inputDataType,
    DeviceCreationLocation deviceCreationLocation
)
{
    if (model == nullptr)
    {
        return hresult_invalid_argument().code();
    }

    LearningModelSession session = nullptr;
    IDirect3DDevice winrtDevice = nullptr;

    try
    {
        if (deviceCreationLocation == DeviceCreationLocation::ClientCode)
        {
            // Creating the device on the client and using it to create the video frame and initialize the session makes sure that everything is on
            // the same device. This usually avoids an expensive cross-device and cross-videoframe copy via the VideoFrame pipeline.
            com_ptr<ID3D11Device> d3d11Device;
            HRESULT hr = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_BGRA_SUPPORT, nullptr, 0, D3D11_SDK_VERSION, d3d11Device.put(), nullptr, nullptr);

            if (FAILED(hr))
            {
                throw hresult(hr);
            }

            com_ptr<IDXGIDevice> dxgiDevice;
            hr = d3d11Device->QueryInterface(IID_PPV_ARGS(dxgiDevice.put()));

            if (FAILED(hr))
            {
                throw hresult(hr);
            }

            com_ptr<IInspectable> inspectableDevice;
            hr = CreateDirect3D11DeviceFromDXGIDevice(dxgiDevice.get(), inspectableDevice.put());

            if (FAILED(hr))
            {
                throw hresult(hr);
            }

            winrtDevice = inspectableDevice.as<IDirect3DDevice>();
            LearningModelDevice learningModelDevice = LearningModelDevice::CreateFromDirect3D11Device(winrtDevice);
            session = LearningModelSession(model, learningModelDevice);
        }
        else
        {
            session = LearningModelSession(model, TypeHelper::GetWinmlDeviceKind(deviceType));
        }
    }
    catch (hresult_error hr)
    {
        std::cout << "Creating session [FAILED]" << std::endl;
        std::wcout << hr.message().c_str() << std::endl;
        return hr.code();
    }

    if (args.EnableDebugOutput())
    {
        // Enables trace log output. 
        session.EvaluationProperties().Insert(L"EnableDebugOutput", nullptr);
    }

    LearningModelBinding context(session);

    bool useInputData = false;
    
    // Add one more iteration if we ignore the first run
    uint32_t numIterations = args.NumIterations() + args.IgnoreFirstRun();

    bool isGarbageData = !args.CsvPath().empty() || !args.ImagePath().empty();

    // Run the binding + evaluate multiple times and average the results
    for (uint32_t i = 0; i < numIterations; i++)
    {
        bool captureIterationPerf = args.PerfCapture() && (!args.IgnoreFirstRun() || i > 0);

        output.PrintBindingInfo(i + 1, deviceType, inputBindingType, inputDataType, deviceCreationLocation);

        std::vector<ILearningModelFeatureValue> inputFeatures = GenerateInputFeatures(model, args, inputBindingType, inputDataType, winrtDevice);
        HRESULT bindInputResult = BindInputFeatures(model, context, inputFeatures, args, output, captureIterationPerf);

        if (FAILED(bindInputResult))
        {
            return bindInputResult;
        }

        output.PrintEvaluatingInfo(i + 1, deviceType, inputBindingType, inputDataType, deviceCreationLocation);

        HRESULT evalResult = EvaluateModel(model, context, session, isGarbageData, args, output, captureIterationPerf);

        if (FAILED(evalResult))
        {
            return evalResult;
        }
    }

    session.Close();

    return S_OK;
}