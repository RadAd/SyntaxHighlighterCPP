
class BrushPython : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushPython()
        : Brush(L"Python")
    {
        // Contributed by Gheorghe Milas and Ahmad Sherif

        String keywords = L"and assert break class continue def del elif else "
            L"except exec finally for from global if import in is "
            L"lambda not or pass print raise return try yield while";
        String functions = L"__import__ abs all any apply basestring bin bool buffer callable "
            L"chr classmethod cmp coerce compile complex delattr dict dir "
            L"divmod enumerate eval execfile file filter float format frozenset "
            L"getattr globals hasattr hash help hex id input int intern "
            L"isinstance issubclass iter len list locals long map max min next "
            L"object oct open ord pow print property range raw_input reduce "
            L"reload repr reversed round set setattr slice sorted staticmethod "
            L"str sum super tuple type type unichr unicode vars xrange zip";
        String special = L"None True False self cls class_";

        add(RegExpRule(RegExpRule::singleLinePerlComments, COMMENTS));
        add(RegExpRule(L"^\\s*@\\w+", Pattern::MULTILINE, COLOR2));
        //add(RegExpRule(L"(['\\\"]{3})([^['\\\"]{3}])*?['\\\"]{3}", COMMENTS));
        add(RegExpRule(L"'(?!')(?:\\.|(\\\\\\')|[^\\''\\n])*'", STRING));
        add(RegExpRule(L"\\+|\\-|\\*|\\/|\\%|=|==", KEYWORD));
        add(RegExpRule(L"\\b\\d+\\.?\\w*", VALUE));
        add(RegExpRule(getKeywords(functions), Pattern::CASE_INSENSITIVE, FUNCTION));
        add(RegExpRule(getKeywords(keywords), KEYWORD));
        add(RegExpRule(getKeywords(special), COLOR1));

        setHTMLScriptPattern(RegExpRule::aspScriptTags);
    }
};
