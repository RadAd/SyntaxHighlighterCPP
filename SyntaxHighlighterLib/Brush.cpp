#include "stdafx.h"

#include "include\Brush.h"
#include "BrushPlain.h"
#include "BrushXml.h"
#include "RegExpRule.h"

#include <algorithm>

const wchar_t* Brush::PREPROCESSOR = L"preprocessor";
const wchar_t* Brush::COMMENTS = L"comments";
const wchar_t* Brush::KEYWORD = L"keyword";
const wchar_t* Brush::TYPE = L"type";
const wchar_t* Brush::FUNCTION = L"function";
const wchar_t* Brush::STRING = L"string";
const wchar_t* Brush::VALUE = L"value";
const wchar_t* Brush::VARIABLE = L"variable";
const wchar_t* Brush::CONSTANT = L"constant";
const wchar_t* Brush::COLOR1 = L"color1";
const wchar_t* Brush::COLOR2 = L"color2";
const wchar_t* Brush::COLOR3 = L"color3";

Brush::Brush(const wchar_t* name)
    : name(name)
{
}

Brush::~Brush()
{
    delete htmlScriptPattern;
}

void Brush::add(const RegExpRule& rule)
{
    regExpRuleList.push_back(rule);
}

void Brush::setHTMLScriptPattern(const Pattern& htmlScriptPattern)
{
    delete this->htmlScriptPattern;
    this->htmlScriptPattern = new Pattern(htmlScriptPattern);
}

void Brush::setHTMLScriptPattern(const String& regExp, int regFlags)
{
    delete htmlScriptPattern;
    htmlScriptPattern = new Pattern(regExp, regFlags);
}

void Brush::replace(String& p, wchar_t c, const String& replacement)
{
    for (size_t i = 0; i < p.length(); ++i)
    {
        if (p[i] == L'\\')
            ++i;
        else if (p[i] == c)
        {
            p.erase(i, 1);
            p.insert(i, replacement);
            i += replacement.length() - 1;
        }
    }
}

void Brush::tidySpaces(String& str)
{
    while (!str.empty() && str.front() == L' ')
        str.erase(str.begin());
    while (!str.empty() && str.back() == L' ')
        str.erase(std::prev(str.end()));

    {
        wchar_t last = L'\0';
        auto it = str.begin();
        while (it != str.end())
        {
            if (last == L' ' && *it == L' ')
                it = str.erase(it);
            else
            {
                last = *it;
                ++it;
            }
        }
    }
}

String Brush::getKeywords(String str)
{
    tidySpaces(str);
    std::replace(str.begin(), str.end(), L' ', L'|');
    return L"\\b(?:" + str + L")\\b";
}

String Brush::getKeywordsCSS(String str)
{
    tidySpaces(str);
    replace(str, L' ', L"(?=:)\\\\b|\\\\b([a-z_\\\\*]|\\\\*|)");
    return L"\\b([a-z_]|)" + str + L"(?=:)\\b";
}

String Brush::getValuesCSS(String str)
{
    tidySpaces(str);
    replace(str, L' ', L"(?!-)(?!:)\\\\b|\\\\b()");
    return L"\\b" + str + L":\\b";
}

#include "BrushAppleScript.h"
const wchar_t* BrushAppleScript::exts[] = { L"applescript", L"scpt" };

#include "BrushAS3.h"
const wchar_t* BrushAS3::exts[] = { L"as" };

#include "BrushBash.h"
const wchar_t* BrushBash::exts[] = { L"sh" };

#include "BrushBatch.h"
const wchar_t* BrushBatch::exts[] = { L"bat", L"cmd" };

#include "BrushColdFusion.h"
const wchar_t* BrushColdFusion::exts[] = { L"cfm", L"cfml" };

#include "BrushCpp.h"
const wchar_t* BrushCpp::exts[] = { L"c", L"h", L"cc", L"cpp" };

#include "BrushCSharp.h"
const wchar_t* BrushCSharp::exts[] = { L"cs" };

#include "BrushCss.h"
const wchar_t* BrushCss::exts[] = { L"css" };

#include "BrushDelphi.h"
const wchar_t* BrushDelphi::exts[] = { L"pas" };

#include "BrushDiff.h"
const wchar_t* BrushDiff::exts[] = { L"diff", L"patch" };

#include "BrushErlang.h"
const wchar_t* BrushErlang::exts[] = { L"erl" };

#include "BrushGroovy.h"
const wchar_t* BrushGroovy::exts[] = { L"groovy" };

#include "BrushIni.h"
const wchar_t* BrushIni::exts[] = { L"ini", L"cfg", L"conf" };

#include "BrushJava.h"
const wchar_t* BrushJava::exts[] = { L"java" };

#include "BrushJavaFX.h"
const wchar_t* BrushJavaFX::exts[] = { L"fx" };

#include "BrushJScript.h"
const wchar_t* BrushJScript::exts[] = { L"js", L"es" };

#include "BrushPerl.h"
const wchar_t* BrushPerl::exts[] = { L"pl", L"pm", L"t" };

#include "BrushPhp.h"
const wchar_t* BrushPhp::exts[] = { L"php", L"php3", L"php4", L"php5", L"phps", L"phtml" };

#include "BrushPowerShell.h"
const wchar_t* BrushPowerShell::exts[] = { L"ps1" };

#include "BrushPython.h"
const wchar_t* BrushPython::exts[] = { L"py" };

#include "BrushRuby.h"
const wchar_t* BrushRuby::exts[] = { L"rb", L"rbw" };

#include "BrushSass.h"
const wchar_t* BrushSass::exts[] = { L"sass", L"scss" };

#include "BrushScala.h"
const wchar_t* BrushScala::exts[] = { L"scl", L"scala" };

#include "BrushSql.h"
const wchar_t* BrushSql::exts[] = { L"sql" };

#include "BrushVb.h"
const wchar_t* BrushVb::exts[2] = { L"vb", L"vbs" };

#include "include\SyntaxHighlighterBrushes.h"
#include <set>

//#include "BrushXml.h"
const wchar_t* BrushXml::exts[] = { L"xml", L"xslt" };
const wchar_t* BrushXml::extshtml[] = { L"htm", L"html", L"xhtml", L"hta" };

SyntaxHighlighterBrushes::SyntaxHighlighterBrushes()
{
    plainBrush = new BrushPlain();
    BrushXml* htmlBrush = new BrushXml(true);

    registerBrush(BrushAppleScript::exts, new BrushAppleScript(), *htmlBrush);
    registerBrush(BrushAS3::exts, new BrushAS3(), *htmlBrush);
    registerBrush(BrushBash::exts, new BrushBash(), *htmlBrush);
    registerBrush(BrushBatch::exts, new BrushBatch(), *htmlBrush);
    registerBrush(BrushColdFusion::exts, new BrushColdFusion(), *htmlBrush);
    registerBrush(BrushCpp::exts, new BrushCpp(), *htmlBrush);
    registerBrush(BrushCSharp::exts, new BrushCSharp(), *htmlBrush);
    registerBrush(BrushCss::exts, new BrushCss(), *htmlBrush);
    registerBrush(BrushDelphi::exts, new BrushDelphi(), *htmlBrush);
    registerBrush(BrushDiff::exts, new BrushDiff(), *htmlBrush);
    registerBrush(BrushErlang::exts, new BrushErlang(), *htmlBrush);
    registerBrush(BrushGroovy::exts, new BrushGroovy(), *htmlBrush);
    registerBrush(BrushIni::exts, new BrushIni(), *htmlBrush);
    registerBrush(BrushJava::exts, new BrushJava(), *htmlBrush);
    registerBrush(BrushJavaFX::exts, new BrushJavaFX(), *htmlBrush);
    registerBrush(BrushJScript::exts, new BrushJScript(), *htmlBrush);
    registerBrush(BrushPerl::exts, new BrushPerl(), *htmlBrush);
    registerBrush(BrushPhp::exts, new BrushPhp(), *htmlBrush);
    registerBrush(BrushPowerShell::exts, new BrushPowerShell(), *htmlBrush);
    registerBrush(BrushPython::exts, new BrushPython(), *htmlBrush);
    registerBrush(BrushRuby::exts, new BrushRuby(), *htmlBrush);
    registerBrush(BrushSass::exts, new BrushSass(), *htmlBrush);
    registerBrush(BrushScala::exts, new BrushScala(), *htmlBrush);
    registerBrush(BrushSql::exts, new BrushSql(), *htmlBrush);
    registerBrush(BrushVb::exts, new BrushVb(), *htmlBrush);
    registerBrush(BrushXml::exts, new BrushXml(false), *htmlBrush);

    registerBrush(BrushXml::extshtml, htmlBrush, *htmlBrush);
}

SyntaxHighlighterBrushes::~SyntaxHighlighterBrushes()
{
    delete plainBrush;

    std::set<const Brush*> todelete;
    for (auto& item : brushes)
    {
        todelete.insert(item.second);
    }
    for (const Brush* b : todelete)
        delete b;
}

void SyntaxHighlighterBrushes::registerBrush(BrushXml& htmlBrush, const Brush* brush)
{
    htmlBrush.addHtmlScript(brush);
}
