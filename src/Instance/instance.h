#ifndef INSTANCE_H_INCLUDED
#define INSTANCE_H_INCLUDED

#pragma once



#include "../superheader.h"


void SetupApplication();
void InsDrawText(const char* text, float posX, float posY, float size, Color color);
void CloseApplication();
Font InsGetFont();
#endif