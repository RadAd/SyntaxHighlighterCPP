#include "RegExpRule.h"

class BrushXml : public Brush
{
public:
    static const wchar_t* exts[2];
    static const wchar_t* extshtml[4];

    BrushXml(bool html)
        : Brush(html ? L"HTML" : L"XML")
    {
        add(RegExpRule(L"(\\&lt;|<)\\!--(.*?)--(\\&gt;|>)", Pattern::DOTALL, COMMENTS)); // <!-- ... -->
        add(RegExpRule(L"(\\&lt;|<)\\!\\[[\\w\\s]*?\\[(.*?)\\]\\](\\&gt;|>)", Pattern::DOTALL, PREPROCESSOR)); // <![ ... [ ... ]]>
        add(RegExpRule(L"(\\&lt;|<)\\![\\w\\s]*?(.*?)(\\&gt;|>)", Pattern::DOTALL, PREPROCESSOR)); // <! ... >

        // includes regular expression for highlighting the tag
        add(RegExpRule(L"(?:&lt;|<)[\\?\\/]?\\s*([:\\w-\\.]+)(.*?)\\s*[\\/\\?]?(?:&gt;|>)", Pattern::DOTALL, nullptr)
            .addGroupOperation(KEYWORD)
            // regular expression for highlighting the variable assignment
            .addGroupOperation(RegExpRule(L"([\\w:\\-\\.]+)\\s*=\\s*(\"[^\\\\\"\\n]*\"|'[^\\\\\'\\n]*')", nullptr)
                .addGroupOperation(VARIABLE)
                .addGroupOperation(STRING)));
    }

    void addHtmlScript(const Brush* other)
    {
        add(RegExpRule(other->getHTMLScriptPattern(), nullptr)
            .addGroupOperation(other));
    }
};
