#include "exheaders/netlib.h"
#include "instance/instance.h"
#include "exheaders/raylib.h"
#include "abs/rayguiabs.h"
#include <stdio.h>
#include <string.h>
#include "network/network.h"
#include "statemgmt/statemgmt.h"
char buffer[512];

int main(){
    SetTraceLogLevel(LOG_ERROR);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1600, 900, "h");
    SetupApplication();
    RayGUIInitialize();
    
    //char buddy[UINT16_MAX];
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        StateRenderer();

        EndDrawing();
    }
    
    CloseApplication();
}
