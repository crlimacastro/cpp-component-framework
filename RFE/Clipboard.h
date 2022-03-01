#pragma once

// Copy/Paste Clipboard Logic
namespace rfe
{
    class RFE_API Clipboard
    {
    public:
        static const char* GetText();
        static void SetText(const char* value);
    private:
        Clipboard() = delete;
        Clipboard(const Clipboard&) = delete;
        Clipboard& operator=(const Clipboard&) = delete;
        ~Clipboard() = delete;
    };
    
}