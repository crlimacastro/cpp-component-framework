#include "pch.h"
#include "Clipboard.h"

const char* rfe::Clipboard::GetText()
{
    return GetClipboardText();
}

void rfe::Clipboard::SetText(const char* value)
{
    SetClipboardText(value);
}
