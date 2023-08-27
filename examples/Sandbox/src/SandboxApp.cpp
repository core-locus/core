#include "Cacus.h"

class Sandbox : public Cacus::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {
        
    }
};

Cacus::Application* Cacus::CreateApplication()
{
    return new Sandbox();
}