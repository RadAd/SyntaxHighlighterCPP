
class BrushScala : public Brush
{

public:
    static const wchar_t* exts[2];

    BrushScala()
        : Brush(L"Scala")
    {
        // Contributed by Yegor Jbanov and David Bernard.

        String keywords = L"val sealed case def true trait implicit forSome import match object null finally super "
            L"override try lazy for var catch throw type extends class while with new final yield abstract "
            L"else do if return protected private this package false";
        String keyops = L"[_:=><%#@]+";

        add(RegExpRule(RegExpRule::singleLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::multiLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::multiLineSingleQuotedString, STRING));
        // problem: scala should start multiple line string with triple double-quote
        add(RegExpRule(RegExpRule::multiLineDoubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"0x[a-f0-9]+|\\d+(\\.\\d+)?", Pattern::CASE_INSENSITIVE, VALUE));
        add(RegExpRule(getKeywords(keywords), KEYWORD));
        add(RegExpRule(keyops, KEYWORD));
    }
};
