#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Cacus
{
    class CACUS_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        // To be defined by client
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
    
    Application* CreateApplication();
} // namespace Cacus
