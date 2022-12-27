#include "pch.h"
#include "Clipboard.h"

std::string rfe::Clipboard::GetText()
{
	return GetClipboardText();
}

void rfe::Clipboard::SetText(std::string value)
{
	SetClipboardText(value.c_str());
}
