
class BrushJScript : public Brush
{
public:
    static const wchar_t* exts[2];

    BrushJScript()
        : Brush(L"JavaScript")
    {
        String keywords = L"break case catch continue "
            L"default delete do else false  "
            L"for function if in instanceof "
            L"new null return super switch "
            L"this throw true try typeof var while with";

        add(RegExpRule(RegExpRule::singleLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::multiLineCComments, COMMENTS));
        // it's a standard not to use multi-line string
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"\\s*#.*", PREPROCESSOR)); // preprocessor tags like #region and #endregion
        add(RegExpRule(getKeywords(keywords), KEYWORD));

        setHTMLScriptPattern(RegExpRule::createScriptPattern(L"script", L"(?:text/)?javascript"));
    }
};
