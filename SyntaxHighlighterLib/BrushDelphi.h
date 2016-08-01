
class BrushDelphi : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushDelphi()
        : Brush(L"Pascal")
    {
        String keywords = L"abs addr and ansichar ansistring array as asm begin boolean byte cardinal "
            L"case char class comp const constructor currency destructor div do double "
            L"downto else end except exports extended false file finalization finally "
            L"for function goto if implementation in inherited int64 initialization "
            L"integer interface is label library longint longword mod nil not object "
            L"of on or packed pansichar pansistring pchar pcurrency pdatetime pextended "
            L"pint64 pointer private procedure program property pshortstring pstring "
            L"pvariant pwidechar pwidestring protected public published raise real real48 "
            L"record repeat set shl shortint shortstring shr single smallint string then "
            L"threadvar to true try type unit until uses val var varirnt while widechar "
            L"widestring with word write writeln xor";

        add(RegExpRule(L"\\(\\*.*?\\*\\)", Pattern::DOTALL, COMMENTS)); // multiline comments (* *)
        add(RegExpRule(L"\\{(?!\\$).*?\\}", Pattern::DOTALL, COMMENTS)); // multiline comments { }
        add(RegExpRule(RegExpRule::singleLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"\\{\\$[a-zA-Z]+ .+\\}", COLOR1)); // compiler Directives and Region tags
        add(RegExpRule(L"\\b[\\d\\.]+\\b", VALUE)); // numbers 12345
        add(RegExpRule(L"\\$[a-zA-Z0-9]+\\b", VALUE)); // numbers $F5D3
        add(RegExpRule(getKeywords(keywords), Pattern::CASE_INSENSITIVE, KEYWORD));
    }
};
