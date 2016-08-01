
class BrushJava : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushJava()
        : Brush(L"Java")
    {

        String datatypes = L"Boolean Byte Character Class Double Enum Float Integer Long Number String";
        String keywords = L"abstract assert boolean break byte case catch char class const "
            L"continue default do double else enum extends "
            L"false final finally float for goto if implements import "
            L"instanceof int interface long native new null "
            L"package private protected public return "
            L"short static strictfp super switch synchronized this throw throws true "
            L"transient try void volatile while";

        add(RegExpRule(RegExpRule::singleLineCComments, COMMENTS));
        add(RegExpRule(L"\\/\\*(?!\\*\\/)\\*.*?\\*\\/", Pattern::DOTALL, PREPROCESSOR)); // documentation comments
        add(RegExpRule(RegExpRule::multiLineCComments, COMMENTS)); // multiline comments
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"\\b([\\d]+(\\.[\\d]+)?|0x[a-f0-9]+)\\b", Pattern::CASE_INSENSITIVE, VALUE)); // numbers
        //add(RegExpRule(L"(?!\\@interface\\b)\\@[\\$\\w]+\\b", COLOR1)); // annotation @anno
        //add(RegExpRule(L"\\@interface\\b", COLOR2)); // @interface keyword
        add(RegExpRule(L"\\@\\w+", PREPROCESSOR)); // annotation
        add(RegExpRule(getKeywords(keywords), KEYWORD));
        add(RegExpRule(getKeywords(datatypes), TYPE));
        add(RegExpRule(L"\\b(\\w)+(\\s)*(?=\\()", FUNCTION));

        setHTMLScriptPattern(L"(?:&lt;|<)%[@!=]?(.*?)%(?:&gt;|>)", Pattern::CASE_INSENSITIVE | Pattern::DOTALL);
    }
};
