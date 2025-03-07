#include "exheaders/netlib.h"
#include "instance/instance.h"
#include "exheaders/raylib.h"
#include "abs/rayguiabs.h"
#include <string.h>


char list[UINT16_MAX] = "System - System";


int main(){
    // just testing stuff
    netlib_init();
    ip_address ip;
    if(netlib_resolve_host(&ip, "127.0.0.1", 6942) < 0){
        return -1;
    }
    tcp_socket client = netlib_tcp_open(&ip);
    if(!client){
        return -2;
    }
    SetTraceLogLevel(LOG_ERROR);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1600, 900, "h");
    SetupApplication();
    RayGUIInitialize();
    char text[512];
    int scrollIndex = 0;
    int active = 0;
    int focus = 0;

    //char buddy[UINT16_MAX];
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        //RayGUIDrawTextBox(10, 10, GetScreenWidth() - 20, GetScreenHeight() - 115, buddy, 30, false);
        RayGUIDrawLists(10, 10, GetScreenWidth() - 20,GetScreenHeight() - 115, list, &scrollIndex, &active);
        RayGUIDrawTextBox(10, GetScreenHeight() - 100, GetScreenWidth() - 200, 90, text, 30, true);
        int button = RayGUIDrawButton(GetScreenWidth() - 200, GetScreenHeight() - 100, 200, 90, "Send");
        if(button == 1 || IsKeyPressed(KEY_ENTER)){
            printf("%s\n", text);
            sprintf(list, "%s;User - %s", list, text);
            char serverres[512];
            sprintf(serverres, "User - %s;", text);
            netlib_tcp_send(client, serverres, strlen(serverres));
            sprintf(text, "");
        }

        EndDrawing();
    }
    
    CloseApplication();
}
