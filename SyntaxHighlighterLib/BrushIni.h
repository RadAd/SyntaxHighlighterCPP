
class BrushIni : public Brush
{
public:
    static const wchar_t* exts[3];

    BrushIni()
        : Brush(L"Conf")
    {
        add(RegExpRule(L"^\\s*\\[(\\s|\\w)*\\]", Pattern::MULTILINE, PREPROCESSOR));
        add(RegExpRule(L"^\\s*(;|#).*", Pattern::MULTILINE, COMMENTS));

        add(RegExpRule(L"([\\w:\\-\\.]+)\\s*=\\s*(.*)", nullptr)
            .addGroupOperation(VARIABLE)
            .addGroupOperation(VALUE));
    }
};
