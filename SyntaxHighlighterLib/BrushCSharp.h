
class BrushCSharp : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushCSharp()
        : Brush(L"C#")
    {
        String keywords = L"abstract as base bool break byte case catch char checked class const "
            L"continue decimal default delegate do double else enum event explicit "
            L"extern false finally fixed float for foreach get goto if implicit in int "
            L"interface internal is lock long namespace new null object operator out "
            L"override params private protected public readonly ref return sbyte sealed set "
            L"short sizeof stackalloc static string struct switch this throw true try "
            L"typeof uint ulong unchecked unsafe ushort using virtual void while var";

        add(RegExpRule(L"\\/\\/\\/.*$", Pattern::MULTILINE, COLOR1)); // documents
        add(RegExpRule(RegExpRule::singleLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::multiLineCComments, COMMENTS));
        add(RegExpRule(L"@\"(?:[^\"]|\"\")*\"", STRING)); // @-quoted strings
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"^\\s*#.*", Pattern::MULTILINE, PREPROCESSOR)); // preprocessor tags like #region and #endregion
        add(RegExpRule(getKeywords(keywords), KEYWORD));
        add(RegExpRule(L"\\bpartial(?=\\s+(?:class|interface|struct)\\b)", KEYWORD)); // contextual keyword: 'partial'
        add(RegExpRule(L"\\byield(?=\\s+(?:return|break)\\b)", KEYWORD)); // contextual keyword: 'yield'

        setHTMLScriptPattern(RegExpRule::aspScriptTags);
    }
};
