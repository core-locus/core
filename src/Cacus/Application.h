#pragma once

#include "Core.h"

namespace Cacus
{
    class CACUS_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        // To be defined by client
    };
    
    Application* CreateApplication();
} // namespace Cacus
