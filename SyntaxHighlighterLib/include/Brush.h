#ifndef BRUSH_H
#define BRUSH_H

#include <string>
#include <vector>

typedef std::wstring String;

class Pattern;
class RegExpRule;

class Brush
{
public:
    static const wchar_t* PREPROCESSOR;
    static const wchar_t* COMMENTS;
    static const wchar_t* KEYWORD;
    static const wchar_t* TYPE;
    static const wchar_t* FUNCTION;
    static const wchar_t* STRING;
    static const wchar_t* VALUE;
    static const wchar_t* VARIABLE;
    static const wchar_t* CONSTANT;
    static const wchar_t* COLOR1;
    static const wchar_t* COLOR2;
    static const wchar_t* COLOR3;

private:
    const wchar_t* name;
    std::vector<RegExpRule> regExpRuleList;
    const Pattern* htmlScriptPattern = nullptr;

protected:
    Brush(const wchar_t* name);

public:
    ~Brush();

    const wchar_t* getName() const
    {
        return name;
    }

    const std::vector<RegExpRule>& getRegExpRuleList() const
    {
        return regExpRuleList;
    }

    bool hasHTMLScriptPattern() const
    {
        return htmlScriptPattern != nullptr;
    }

    const Pattern& getHTMLScriptPattern() const
    {
        return *htmlScriptPattern;
    }

protected:
    void add(const RegExpRule& rule);

    void setHTMLScriptPattern(const Pattern& htmlScriptPattern);
    void setHTMLScriptPattern(const String& regExp, int regFlags);

    static void replace(String& p, wchar_t c, const String& replacement);

    static void tidySpaces(String& str);

    static String getKeywords(String str);
    static String getKeywordsCSS(String str);
    static String getValuesCSS(String str);
};

#endif
