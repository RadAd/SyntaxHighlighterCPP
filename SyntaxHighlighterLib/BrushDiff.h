
class BrushDiff : public Brush
{
public:
    static const wchar_t* exts[2];

    BrushDiff()
        : Brush(L"Diff")
    {
        add(RegExpRule(L"^\\+\\+\\+\\s.*$", Pattern::MULTILINE, COLOR2)); // new file
        add(RegExpRule(L"^\\-\\-\\-\\s.*$", Pattern::MULTILINE, COLOR2)); // old file
        add(RegExpRule(L"^\\s.*$", Pattern::MULTILINE, COLOR1)); // unchanged
        add(RegExpRule(L"^@@.*@@$", Pattern::MULTILINE, VARIABLE)); // location
        add(RegExpRule(L"^\\+.*$", Pattern::MULTILINE, STRING)); // additions
        add(RegExpRule(L"^\\-.*$", Pattern::MULTILINE, COLOR3)); // deletions
    }
};
