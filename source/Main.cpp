/* #include <GamerText.hpp> */
/* #include <switch.h> */
#include <stdlib.h>
#include "../include/Twilio.hpp"
#include <iostream>

/*
// If you would like to initialize and finalize stuff before or after Plutonium, you can use libnx's userAppInit/userAppExit

extern "C" void userAppInit() {
    // Initialize stuff
}

extern "C" void userAppExit() {
    // Cleanup/finalize stuff
}
*/

// Main entrypoint
int main() {
     // First create our renderer, where one can customize SDL or other stuff's initialization.
     /* auto renderer_opts = pu::ui::render::RendererInitOptions(SDL_INIT_EVERYTHING, pu::ui::render::RendererHardwareFlags); */
     /* renderer_opts.UseImage(pu::ui::render::IMGAllFlags); */
     /* renderer_opts.UseAudio(pu::ui::render::MixerAllFlags); */
     /* renderer_opts.UseTTF(); */
     /* auto renderer = pu::ui::render::Renderer::New(renderer_opts); */

     /* // Create our main application from the renderer */
     /* auto main = MainApplication::New(renderer); */

     /* // Prepare out application. This MUST be called or Show() will exit and nothing will be rendered. */
     /* main->Prepare(); */

     /* // Show -> start rendering in an "infinite" loop */
     /* // If wou would like to show with a "fade in" from black-screen to the UI, use instead ->ShowWithFadeIn(); */
     /* main->Show(); */


    // Exit homebrew (Plutonium will handle all disposing of UI and renderer/application, don't worry!
    //std::cout << "ligma" << std::endl;
    /* std::string text = "ligma1"; */
    /* send_message(text); */
    std::string account_sid("48d506c54c7b41dcb3dfc600384ff842CA");
    std::string auth_token("92a624ff895c02b0d57419106b35fac2");

    std::string temp = "";

    for (int i=account_sid.length()-1; i>=0; i--)
             temp += account_sid[i];

    account_sid = temp;

    temp = "";
    for (int i=auth_token.length()-1; i>=0; i--)
            temp +=  auth_token[i];

    auth_token = temp;

    get_messages(account_sid, auth_token);
    return 0;
}
