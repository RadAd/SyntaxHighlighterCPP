
class BrushJava : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushJava()
        : Brush(L"Java")
    {

        String datatypes = L"Boolean Byte Character Class Double Enum Float Integer Long Number String";
        String keyworddatatypes = L"boolean byte char double float int long short void";
        String keywords = L"abstract assert break case catch class const "
            L"continue default do else enum extends "
            L"final finally for goto if implements "
            L"instanceof interface native new "
            L"private protected public return "
            L"static strictfp super switch synchronized this throw throws "
            L"transient try volatile while";

        add(RegExpRule(RegExpRule::singleLineCComments, COMMENTS));
        add(RegExpRule(L"\\/\\*(?!\\*\\/)\\*.*?\\*\\/", Pattern::DOTALL, PREPROCESSOR)); // documentation comments
        add(RegExpRule(getKeywords(L"import package"), PREPROCESSOR));
        add(RegExpRule(RegExpRule::multiLineCComments, COMMENTS)); // multiline comments
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"\\b([\\d]+(\\.[\\d]+)?|0x[a-f0-9]+)\\b", Pattern::CASE_INSENSITIVE, VALUE)); // numbers
        add(RegExpRule(getKeywords(L"true false null"), VALUE));
        //add(RegExpRule(L"(?!\\@interface\\b)\\@[\\$\\w]+\\b", COLOR1)); // annotation @anno
        //add(RegExpRule(L"\\@interface\\b", COLOR2)); // @interface keyword
        add(RegExpRule(L"\\@\\w+", PREPROCESSOR)); // annotation
        add(RegExpRule(getKeywords(keywords), KEYWORD));
        add(RegExpRule(getKeywords(datatypes), TYPE));
        add(RegExpRule(getKeywords(keyworddatatypes), TYPE));
        add(RegExpRule(L"\\b(\\w)+(\\s)*(?=\\()", FUNCTION));

        setHTMLScriptPattern(L"(?:&lt;|<)%[@!=]?(.*?)%(?:&gt;|>)", Pattern::CASE_INSENSITIVE | Pattern::DOTALL);
    }
};
