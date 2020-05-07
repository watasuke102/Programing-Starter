#pragma once

constexpr int WINDOW_WIDTH  = 600;
constexpr int WINDOW_HEIGHT = 400;

#include <Siv3D.hpp>
#include "Button.h"

extern void drawExplanation(String, String);
extern void drawString(String, Vec2, bool);

extern void welcome(), selectLanguage(), selectEditor();