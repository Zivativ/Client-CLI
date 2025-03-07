#ifndef RAYGUIABS_H_INCLUDED
#define RAYGUIABS_H_INCLUDED






#include "../superheader.h"


int RayGUIDrawButton(int x, int y, int sizeX, int sizeY, const char* text);
int RayGUIDrawTextBox(int x, int y, int sizeX, int sizeY, char* text, int textSize, bool editMode);
void RayGUIInitialize();
int RayGUIMessageBox(int x, int y, int sizeX, int sizeY, char* title, char* text, char* buttons);
int RayGUIDrawLists(int x, int y, int sizeX, int sizeY, char* list, int* scrollIndex, int* active);
#endif