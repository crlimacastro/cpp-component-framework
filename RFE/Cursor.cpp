#include "pch.h"
#include "Cursor.hpp"

void rfe::Cursor::Show()
{
    ShowCursor();
}

void rfe::Cursor::Hide()
{
    HideCursor();
}

bool rfe::Cursor::IsVisible()
{
    return !IsCursorHidden();
}

void rfe::Cursor::ToggleVisible()
{
    IsCursorHidden() ? ShowCursor() : HideCursor();
}

void rfe::Cursor::Enable()
{
    EnableCursor();
}

void rfe::Cursor::Disable()
{
    DisableCursor();
}

bool rfe::Cursor::IsOnScreen()
{
    return IsCursorOnScreen();
}

void rfe::Cursor::Set(Type type)
{
    SetMouseCursor((int)type);
}
