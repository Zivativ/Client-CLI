#include "ui.h"
#include "../network/network.h"


static char text[512];
static char buffer[512];
static int scrollindex;
static int active;

void RenderUI(){
    RayGUIDrawLists(10, 10, GetScreenWidth() - 20,GetScreenHeight() - 115, ReturnList(), &scrollindex, &active);
    RayGUIDrawTextBox(10, GetScreenHeight() - 100, GetScreenWidth() - 200, 90, text, 30, true);
    int button = RayGUIDrawButton(GetScreenWidth() - 200, GetScreenHeight() - 100, 200, 90, "Send");

    if(button == 1 || IsKeyPressed(KEY_ENTER)){
       netlib_tcp_send(ReturnSocket(), text, sizeof(text));
       printf("%s\n", text);
       sprintf(buffer, "");

       int result = netlib_tcp_recv(ReturnSocket(), buffer, UINT16_MAX);
       while(result == 512){
            continue;
       }
       printf("%s\n", buffer);
       ChangeList(buffer);
       printf("%s\n", ReturnList());
       sprintf(buffer, "");
       sprintf(text, "");

    }
}