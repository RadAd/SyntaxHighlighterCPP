#ifndef REGEXPRULE_H
#define REGEXPRULE_H

#include <vector>
#include "Pattern.h"

class Brush;

class RegExpRule
{
public:
    static const Pattern multiLineCComments;
    static const Pattern singleLineCComments;
    static const Pattern singleLinePerlComments;
    static const Pattern doubleQuotedString;
    static const Pattern singleQuotedString;
    static const Pattern multiLineDoubleQuotedString;
    static const Pattern multiLineSingleQuotedString;
    static const Pattern phpScriptTags;
    static const Pattern aspScriptTags;

    static Pattern createScriptPattern(const String& tag, const String& type)
    {
        return Pattern(L"(?:&lt;|<)\\s*" + tag + L".*?type=\"" + type + L"\".*?(?:&gt;|>)(.*?)(?:&lt;|<)\\/\\s*" + tag + L"\\s*(?:&gt;|>)", Pattern::CASE_INSENSITIVE | Pattern::DOTALL);
    }

    class Op
    {
    public:
        enum Type
        {
            T_STRING,
            T_RULE,
            T_BRUSH,
        };

        Op(const wchar_t* s)
        {
            type = T_STRING;
            object = s;
        }

        Op(const RegExpRule* r)
        {
            type = T_RULE;
            object = r;
        }

        Op(const Brush* b)
        {
            type = T_BRUSH;
            object = b;
        }

        Type type;
        const void* object;
    };

private:
    const Pattern pattern;
    std::vector<Op> groupOperations;

public:
    RegExpRule(String regExp, const wchar_t* styleKey)
        : RegExpRule(regExp, 0, styleKey)
    {
    }

    RegExpRule(String regExp, int regFlags, const wchar_t* styleKey)
        : RegExpRule(Pattern(regExp, regFlags), styleKey)
    {
    }

    RegExpRule(const Pattern& pattern, const wchar_t* styleKey)
        : pattern(pattern)
    {
        addGroupOperation(styleKey);
    }

    const Pattern& getPattern() const
    {
        return pattern;
    }

    const std::vector<Op>& getGroupOperations() const
    {
        return groupOperations;
    }

    RegExpRule& addGroupOperation(const wchar_t* styleKey)
    {
        groupOperations.push_back(styleKey);
        return *this;
    }

    RegExpRule& addGroupOperation(const RegExpRule& subRule)
    {
        // TODO Delete the rule
        groupOperations.push_back(new RegExpRule(subRule));
        return *this;
    }

    RegExpRule& addGroupOperation(const Brush* brush)
    {
        groupOperations.push_back(brush);
        return *this;
    }
};

#endif
