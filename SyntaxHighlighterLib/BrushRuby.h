
class BrushRuby : public Brush
{
public:
    static const wchar_t* exts[2];

    BrushRuby()
        : Brush(L"Ruby")
    {
        // Contributed by Erik Peterson.

        String keywords = L"alias and BEGIN begin break case class def define_method defined do each else elsif "
            L"END end ensure false for if in module new next nil not or raise redo rescue retry return "
            L"self super then throw true undef unless until when while yield";
        String builtins = L"Array Bignum Binding Class Continuation Dir Exception FalseClass File::Stat File Fixnum Fload "
            L"Hash Integer IO MatchData Method Module NilClass Numeric Object Proc Range Regexp String Struct::TMS Symbol "
            L"ThreadGroup Thread Time TrueClass";

        add(RegExpRule(RegExpRule::singleLinePerlComments, COMMENTS));
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"\\b[A-Z0-9_]+\\b", CONSTANT)); // constants
        add(RegExpRule(L":[a-z][A-Za-z0-9_]*", COLOR2)); // symbols
        add(RegExpRule(L"(\\$|@@|@)\\w+", VARIABLE)); // $global, @instance, and @@class variables
        add(RegExpRule(getKeywords(keywords), KEYWORD));
        add(RegExpRule(getKeywords(builtins), COLOR1)); // builtins

        setHTMLScriptPattern(RegExpRule::aspScriptTags);
    }
};
