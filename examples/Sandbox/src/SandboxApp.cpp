#include "Cacus.h"

class ExampleLayer : public Cacus::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override 
    {
        CCS_INFO("ExampleLayer::Update");
    }

    void OnEvent(Cacus::Event& event) override
    {
        CCS_TRACE("{0}", event);
    }
};

class Sandbox : public Cacus::Application
{
public:

    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {
        
    }
};

Cacus::Application* Cacus::CreateApplication()
{
    return new Sandbox();
}