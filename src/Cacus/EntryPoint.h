#pragma once

#ifdef _WIN32
extern Cacus::Application* Cacus::CreateApplication();

int main (int argc, char** argv)
{
    auto app = Cacus::CreateApplication();
    app->Run();
    delete app;
}
#else

extern Cacus::Application* Cacus::CreateApplication();

int main (int argc, char** argv)
{
    Cacus::Log::Init();
    CCS_CORE_WARN("Initialized Log");
    int a = 5;
    CCS_INFO("Hello, World! {0}", a);

    auto app = Cacus::CreateApplication();
    app->Run();
    delete app;
}
#endif