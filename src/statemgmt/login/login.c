#include "login.h"
#include "../../abs/rayguiabs.h"
#include "../../network/network.h"
#include "../../instance/instance.h"
#include <string.h>
static char username[512] = "UNKNOWN";
static char ip[1024] = "\0";
static bool fail = false;
static uint8_t state = 0;

static inline void RenderIPScreen(){
    InsDrawText("Enter IP", 10, 500, 40, RED);
    RayGUIDrawTextBox(10, 110, 900, 100, ip, 30, true);
    int button = RayGUIDrawButton(GetScreenWidth() - 200, GetScreenHeight() - 100, 200, 90, "Enter");
    if(button == 1){
        if(strcmp(username, "") == 0){
            ChangeUsername("USERNAME\n");
        } 
        ChangeIPAddress(ip);
        int result = LoginToServer();
        if(result != 0){
            fail = true;
        } else ChangeState(1);
    }
}

static inline void RenderUsernameScreen(){
    InsDrawText("Enter Username", 10, 500, 40, RED);
    RayGUIDrawTextBox(10, 110, 900, 100, username, 30, true);
    int button = RayGUIDrawButton(GetScreenWidth() - 200, GetScreenHeight() - 100, 200, 90, "Enter");
    if(button == 1){
        int result = ChangeUsername(username);
        if(result != 0){
            fail = true;
            printf("h");
        } else state = 1;
        
        // ChangeIPAddress(ip);
        // int result = LoginToServer();
        // if(result != 0){
        //     fail = true;
        // } else ChangeState(1);
    }
}

void RenderLoginScreen(){
    if(fail == true){
        int i = RayGUIMessageBox(GetScreenWidth() / 2, GetScreenHeight() / 2, 
                                400, 200, "Error", "Failure to Login", "Ok");
        if(i != -1){
            fail = false;
        }
        return;
    }
    switch(state){
        case 0:
            RenderUsernameScreen();
            break;
        case 1:
            RenderIPScreen();
            break;
        default:
            state = 0;
    }
    //DrawText(ReturnIpAddress(), 1000, 1000, 90, RED);
    
}