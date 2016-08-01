#ifndef SYNTAXHIGHLIGHTERBRUSHES_H
#define SYNTAXHIGHLIGHTERBRUSHES_H

#include "Brush.h"
#include <map>

class BrushXml;

class SyntaxHighlighterBrushes
{
private:
    const Brush* plainBrush;
    std::map<String, const Brush*> brushes;

    template< size_t N >
    void registerBrush(const wchar_t*(&exts)[N], const Brush* brush, BrushXml& htmlBrush)
    {
        for (String ext : exts) {
            brushes[ext] = brush;
        }
        if (brush->hasHTMLScriptPattern())
        {
            registerBrush(htmlBrush, brush);
        }
    }
    void registerBrush(BrushXml& htmlBrush, const Brush* brush);

public:
    const Brush* getBrushByExtension(const String& ext)
    {
        auto it = brushes.find(ext);
        if (it == brushes.end())
            return plainBrush;
        else
            return it->second;
    }

    const Brush* getBrushByName(const String& name)
    {
        const Brush* brush = plainBrush;
        for (auto it : brushes) {
            if (it.second->getName() == name)
            {
                brush = it.second;
                break;
            }
        }
        return brush;
    }

    const std::map<String, const Brush*>& getBrushes()
    {
        return brushes;
    }

    SyntaxHighlighterBrushes();
    ~SyntaxHighlighterBrushes();
};

#endif
