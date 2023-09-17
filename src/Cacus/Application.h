#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Cacus/Events/ApplicationEvent.h"

#include "Window.h"

namespace Cacus
{
    class CACUS_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);
        // To be defined by client
    private:
        bool OnWindowClosed(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };
    
    Application* CreateApplication();
} // namespace Cacus
