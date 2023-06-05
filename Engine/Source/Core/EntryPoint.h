#pragma once

#ifdef CORE_WINDOWS_PLATFORM

extern Core::Application *Core::CreateApplication();

int main()
{
    auto app = Core::CreateApplication();
    app->Run();
    delete app;

    return 0;
};  

#endif