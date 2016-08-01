#include "stdafx.h"

#include "..\SyntaxHighlighterLib\include\Brush.h"
#include "..\SyntaxHighlighterLib\include\SyntaxHighlighter.h"
#include "..\SyntaxHighlighterLib\include\SyntaxHighlighterBrushes.h"

#include "FileIO.h"

const wchar_t* fg_black_dark = L"\x1b[30m";
const wchar_t* fg_red_dark = L"\x1b[31m";
const wchar_t* fg_green_dark = L"\x1b[32m";
const wchar_t* fg_yellow_dark = L"\x1b[33m";
const wchar_t* fg_blue_dark = L"\x1b[34m";
const wchar_t* fg_magenta_dark = L"\x1b[35m";
const wchar_t* fg_cyan_dark = L"\x1b[36m";
const wchar_t* fg_white_dark = L"\x1b[37m";
const wchar_t* fg_black_light = L"\x1b[30;1m";
const wchar_t* fg_red_light = L"\x1b[31;1m";
const wchar_t* fg_green_light = L"\x1b[32;1m";
const wchar_t* fg_yellow_light = L"\x1b[33;1m";
const wchar_t* fg_blue_light = L"\x1b[34;1m";
const wchar_t* fg_magenta_light = L"\x1b[35;1m";
const wchar_t* fg_cyan_light = L"\x1b[36;1m";
const wchar_t* fg_white_light = L"\x1b[37;1m";
const wchar_t* fg_normal1 = L"\x1b[0m";
const wchar_t* fg_normal = L"\x1b[39m";

const wchar_t* bg_black_dark = L"\x1b[40m";
const wchar_t* bg_red_dark = L"\x1b[41m";
const wchar_t* bg_green_dark = L"\x1b[42m";
const wchar_t* bg_yellow_dark = L"\x1b[43m";
const wchar_t* bg_blue_dark = L"\x1b[44m";
const wchar_t* bg_magenta_dark = L"\x1b[45m";
const wchar_t* bg_cyan_dark = L"\x1b[46m";
const wchar_t* bg_white_dark = L"\x1b[47m";
const wchar_t* bg_black_light = L"\x1b[40;1m";
const wchar_t* bg_red_light = L"\x1b[41;1m";
const wchar_t* bg_green_light = L"\x1b[42;1m";
const wchar_t* bg_yellow_light = L"\x1b[43;1m";
const wchar_t* bg_blue_light = L"\x1b[44;1m";
const wchar_t* bg_magenta_light = L"\x1b[45;1m";
const wchar_t* bg_cyan_light = L"\x1b[46;1m";
const wchar_t* bg_white_light = L"\x1b[47;1m";

template<class CharSequence>
void print(FILE* f, const CharSequence& s, const SyntaxHighlighterMapT& matches)
{
    // TODO Fix ansi escape sequences
    const wchar_t* fg_default = fg_black_light;
    fputws(fg_default, f);
    size_t current = 0;
    for (const auto& match : matches)
    {
        const Range& r = match.first;
        const String& type = match.second;
        if (r.start > current)
            fputws(String(s.begin() + current, s.begin() + r.start).c_str(), f);

        const wchar_t* fg = nullptr;
        if (type == Brush::PREPROCESSOR)
            fg = fg_white_dark;
        else if (type == Brush::COMMENTS)
            fg = fg_green_dark;
        else if (type == Brush::KEYWORD)
            fg = fg_cyan_light;
        else if (type == Brush::TYPE)
            fg = fg_yellow_light;
        else if (type == Brush::FUNCTION)
            fg = fg_yellow_dark;
        else if (type == Brush::STRING)
            fg = fg_magenta_light;
        else if (type == Brush::VALUE)
            fg = fg_magenta_light;
        else if (type == Brush::VARIABLE)
            fg = fg_yellow_light;
        else if (type == Brush::CONSTANT)
            fg = fg_red_light;
        else if (type == Brush::COLOR1)
            fg = fg_yellow_light;
        else if (type == Brush::COLOR2)
            fg = fg_white_light;
        else if (type == Brush::COLOR3)
            fg = fg_yellow_dark;
        if (fg != nullptr)
            fputws(fg, f);

        fputws(String(s.begin() + r.start, s.begin() + r.end).c_str(), f);

        if (fg != nullptr)
            fputws(fg_default, f);

        current = r.end;
    }

    if (s.size() > current)
        fputws(String(s.begin() + current, s.end()).c_str(), f);
    fputws(fg_normal, f);
}

int wmain(int argc, const wchar_t* argv[])
{
    try
    {
        const wchar_t* filename = argv[1];
        const wchar_t* ext = wcsrchr(filename, L'.');
        if (ext != nullptr)
            ++ext;

        SyntaxHighlighterBrushes shb;
        const Brush* b = shb.getBrushByExtension(ext);

        BOM bom = BOM_NONE;
        _locale_t l = _create_locale(LC_ALL, "C");
        std::vector<wchar_t> data = loadtextfile(filename, bom, l);
        SyntaxHighlighterMapT result = SyntaxHighlighter(b, data);
        print(stdout, data, result);
    }
    catch (std::exception& e)
    {
        printf(e.what());
    }
}
