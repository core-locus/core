#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Cacus
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1200, 720);
        CCS_TRACE(e);

        while (true);
    }
} // namespace Cacus
