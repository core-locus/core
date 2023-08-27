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
    printf("Cacus Engine Starting...\n");
    auto app = Cacus::CreateApplication();
    app->Run();
    delete app;
}
#endif