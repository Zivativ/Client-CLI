#include "statemgmt.h"
#include "login/login.h"
#include "../ui/ui.h"




static uint8_t currentstate = 0;


void ChangeState(uint8_t state){
    currentstate = state;
}

uint8_t ReturnState(){
    return currentstate;
}
void StateRenderer(){
    switch(currentstate){
        case 0:
            RenderLoginScreen();
            break;
        case 1:
            RenderUI();
            break;
        default:
            ChangeState(0);
            break;
    }
}