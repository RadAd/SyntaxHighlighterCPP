
class BrushBatch : public Brush
{
public:
    static const wchar_t* exts[2];

    BrushBatch()
        : Brush(L"Batch")
    {
        String keywords = L"assoc break call cd chdir cls color copy date del dir "
            L"echo endlocal erase exit for ftype goto graftabl if md mkdir "
            L"mklink move path pause popd prompt pushd rd rem ren rename "
            L"rmdir set setlocal shift start time title type ver verify vol";
        String devices = L"AUX COM(\\d)? CON NUL LPT(\\d)? PRN";

        add(RegExpRule(L"^\\s*rem\\s.*$", Pattern::MULTILINE, PREPROCESSOR));
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L":[^\\s]*", COLOR1));  // labels
        add(RegExpRule(L"%(~\\w*)?\\d", VARIABLE));
        add(RegExpRule(L"%%\\w", VARIABLE));
        add(RegExpRule(L"%\\w*(:.*)?%", VARIABLE));
        add(RegExpRule(L"!\\w*(:.*)?!", VARIABLE));
        add(RegExpRule(getKeywords(keywords), Pattern::CASE_INSENSITIVE, KEYWORD));
        add(RegExpRule(getKeywords(devices), Pattern::CASE_INSENSITIVE, CONSTANT));

        add(RegExpRule(L"(?:[^\\^])(&|>|<|2>|2>&1|\\|)", nullptr)
            .addGroupOperation(COLOR2));
    }
};
