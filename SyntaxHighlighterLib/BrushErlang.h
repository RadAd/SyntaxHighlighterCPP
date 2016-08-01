
class BrushErlang : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushErlang()
        : Brush(L"Erlang")
    {
        // Contributed by Jean-Lou Dupont
        // http://jldupont.blogspot.com/2009/06/erlang-syntax-highlighter.html

        // According to: http://erlang.org/doc/reference_manual/introduction.html#1.5
        String keywords = L"after and andalso band begin bnot bor bsl bsr bxor "
            L"case catch cond div end fun if let not of or orelse "
            L"query receive rem try when xor"
            // additional
            L" module export import define";

        add(RegExpRule(L"[A-Z][A-Za-z0-9_]+", CONSTANT));
        add(RegExpRule(L"\\%.+", COMMENTS));
        add(RegExpRule(L"\\?[A-Za-z0-9_]+", PREPROCESSOR));
        add(RegExpRule(L"[a-z0-9_]+:[a-z0-9_]+", FUNCTION));
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(getKeywords(keywords), KEYWORD));
    }
};
