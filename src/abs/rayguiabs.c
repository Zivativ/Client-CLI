#include <stdbool.h>
#define RAYGUI_IMPLEMENTATION
#include "../exheaders/raygui.h"
#include "../instance/instance.h"
#include "rayguiabs.h"



void RayGUIInitialize(){
    GuiSetFont(InsGetFont());
    GuiSetStyle(DEFAULT, TEXT_SIZE, 25); 
    GuiSetStyle(LISTVIEW, TEXT_ALIGNMENT, TEXT_ALIGN_LEFT); 

}

int RayGUIDrawButton(int x, int y, int sizeX, int sizeY, const char* text){
    Rectangle rec = {x, y, sizeX, sizeY};
    return GuiButton(rec, text);
}

int RayGUIDrawTextBox(int x, int y, int sizeX, int sizeY, char* text, int textSize, bool editMode){
    Rectangle rec = {x, y, sizeX, sizeY};
    return GuiTextBox(rec, text, textSize, editMode);
    
}

int RayGUIMessageBox(int x, int y, int sizeX, int sizeY, char* title, char* text, char* buttons){
    Rectangle rec = {x, y, sizeX, sizeY};
    return GuiMessageBox(rec, title, text, buttons);
}

int RayGUIDrawLists(int x, int y, int sizeX, int sizeY, char* list, int* scrollIndex, int* active){
    Rectangle rec = {x, y, sizeX, sizeY};
    return GuiListView(rec, list, scrollIndex, active);
}