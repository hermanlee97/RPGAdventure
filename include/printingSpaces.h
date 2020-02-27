#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

#include "menuOrLayout.h"

using namespace std;

void TextWindow(int position, string story);
float CalculateLines(string story, int divider);

#endif