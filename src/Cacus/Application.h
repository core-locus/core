#pragma once

#include "Core.h"

#include "Window.h"
#include "Cacus/LayerStack.h"
#include "Cacus/Events/ApplicationEvent.h"

namespace Cacus
{
    class CACUS_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);
        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
        // To be defined by client
    private:
        bool OnWindowClosed(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        LayerStack m_LayerStack;
        bool m_Running = true;
        
    };
    
    Application* CreateApplication();
} // namespace Cacus
