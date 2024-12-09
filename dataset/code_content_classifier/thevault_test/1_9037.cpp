static void engine_handle_cmd(struct android_app* app, int32_t cmd)
//-----------------------------------------------------------------------------
{
    struct Engine* engine = (struct Engine*)app->userData;

    // These commands are defined in "android_native_app_glue.h"
    switch (cmd)
    {
        case APP_CMD_INPUT_CHANGED:
            LOGE("Processing APP_CMD_INPUT_CHANGED");
            break;
        case APP_CMD_INIT_WINDOW:
        {
            LOGE("Processing APP_CMD_INIT_WINDOW");
            assert(!engine->initialized);

            // InitializeVulkan
            const int iDesiredMSAA = 4;   // 0 = off, -1 = best available, [2|4|8|16] = specified
            assert(engine->application);
            assert(engine->application->GetVulkan());
            assert(engine->app->window);

            if (!engine->application->GetVulkan()->Init( (uintptr_t)(void*)engine->app->window,
                                                   0,
                                                   iDesiredMSAA,
                                                   [engine](tcb::span<const VkSurfaceFormatKHR> x) { return engine->application->PreInitializeSelectSurfaceFormat(x); },
                                                   [engine](Vulkan::AppConfiguration& x) { return engine->application->PreInitializeSetVulkanConfiguration(x); }))
            {
                LOGE("Unable to initialize Vulkan!!");
                engine->initialized = false;    //assert above already checked this, but set anyhow
            }
            else if(!engine->application->Initialize( (uintptr_t)(void*)engine->app->window) )
            {
                LOGE("VkSample::Initialize Error");
                engine->initialized = false;    //assert above already checked this, but set anyhow
            }
            else
            {
                LOGI("VkSample::Initialize Success");
                engine->initialized = true;
            }
            engine->animating = true;
            break;
        }
        case APP_CMD_TERM_WINDOW:
            LOGE("Processing APP_CMD_TERM_WINDOW");
            engine->application->Destroy();
            engine->initialized = false;
            break;
        case APP_CMD_WINDOW_RESIZED:
            LOGE("Processing APP_CMD_WINDOW_RESIZED");
            break;
        case APP_CMD_WINDOW_REDRAW_NEEDED:
            LOGE("Processing APP_CMD_WINDOW_REDRAW_NEEDED");
            break;
        case APP_CMD_CONTENT_RECT_CHANGED:
            LOGE("Processing APP_CMD_CONTENT_RECT_CHANGED");
            break;
        case APP_CMD_GAINED_FOCUS:
            LOGE("Processing APP_CMD_GAINED_FOCUS");
            engine->animating = true;
            break;
        case APP_CMD_LOST_FOCUS:
            LOGE("Processing APP_CMD_LOST_FOCUS");
            engine->animating = false;
            break;
        case APP_CMD_CONFIG_CHANGED:
            LOGE("Processing APP_CMD_CONFIG_CHANGED");
            break;
        case APP_CMD_LOW_MEMORY:
            LOGE("Processing APP_CMD_LOW_MEMORY");
            break;
        case APP_CMD_START:
            LOGE("Processing APP_CMD_START");
            break;
        case APP_CMD_RESUME:
            LOGE("Processing APP_CMD_RESUME");
            break;
        case APP_CMD_SAVE_STATE:
            LOGE("Processing APP_CMD_SAVE_STATE");
            // Teardown, and recreate each time
            engine->animating = false;
            engine->application->Destroy();
            engine->initialized = false;
            break;
        case APP_CMD_PAUSE:
            LOGE("Processing APP_CMD_PAUSE");
            break;
        case APP_CMD_STOP:
            LOGE("Processing APP_CMD_STOP");
            break;
        case APP_CMD_DESTROY:
            LOGE("Processing APP_CMD_DESTROY");
            break;

        default:
            LOGE("Unknowns APP_CMD_XXXXXX = %d", cmd);
            break;
    }
}