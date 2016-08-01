#ifndef PATTERN_H
#define PATTERN_H

#include <regex>

typedef std::wstring String;

class Pattern : public std::wregex
{
public:
    enum flags
    {
        MULTILINE = 1,  // ECMAScript is always multiline
        DOTALL = 2,
        CASE_INSENSITIVE = 4,
    };

    Pattern(const String& p, int f = 0)
        : std::wregex(pattern(p, f), flags(f))
    {

    }

private:
    static void replace(String& p, wchar_t c, const String& replacement);
    static String pattern(String p, int f);
    static flag_type flags(int f);
};

#endif
