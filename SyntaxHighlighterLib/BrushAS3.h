
class BrushAS3 : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushAS3()
        : Brush(L"AS3")
    {
        // Created by Peter Atoria @ http://iAtoria.com

        String initializations = L"class interface function package";
        String keywords = L"-Infinity ...rest Array as AS3 Boolean break case catch const continue Date decodeURI "
            L"decodeURIComponent default delete do dynamic each else encodeURI encodeURIComponent escape "
            L"extends false final finally flash_proxy for get if implements import in include Infinity "
            L"instanceof int internal is isFinite isNaN isXMLName label namespace NaN native new null "
            L"Null Number Object object_proxy override parseFloat parseInt private protected public "
            L"return set static String super switch this throw true try typeof uint undefined unescape "
            L"use void while with";

        add(RegExpRule(RegExpRule::singleLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::multiLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"\\b([\\d]+(\\.[\\d]+)?|0x[a-f0-9]+)\\b", Pattern::CASE_INSENSITIVE, VALUE)); // numbers
        add(RegExpRule(getKeywords(initializations), COLOR3));
        add(RegExpRule(getKeywords(keywords), KEYWORD));
        add(RegExpRule(L"var", VARIABLE));
        add(RegExpRule(L"trace", COLOR1));

        //setHTMLScriptRegExp(HTMLScriptRegExp.createScriptRegExp(L"script", "text/as3"));
    }
};
