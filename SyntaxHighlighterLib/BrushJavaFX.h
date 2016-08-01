
class BrushJavaFX : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushJavaFX()
        : Brush(L"JavaFX")
    {
        // Contributed by Patrick Webster
        // http://patrickwebster.blogspot.com/2009/04/javafx-brush-for-syntaxhighlighter.html

        String datatypes = L"Boolean Byte Character Double Duration "
            L"Float Integer Long Number Short String Void";
        String keywords = L"abstract after and as assert at before bind bound break catch class "
            L"continue def delete else exclusive extends false finally first for from "
            L"function if import in indexof init insert instanceof into inverse last "
            L"lazy mixin mod nativearray new not null on or override package postinit "
            L"protected public public-init public-read replace return reverse sizeof "
            L"step super then this throw true try tween typeof var where while with "
            L"attribute let private readonly static trigger";

        add(RegExpRule(RegExpRule::singleLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::multiLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(L"(-?\\.?)(\\b(\\d*\\.?\\d+|\\d+\\.?\\d*)(e[+-]?\\d+)?|0x[a-f\\d]+)\\b\\.?", Pattern::CASE_INSENSITIVE, VALUE));
        add(RegExpRule(getKeywords(datatypes), VARIABLE));
        add(RegExpRule(getKeywords(keywords), KEYWORD));

        setHTMLScriptPattern(RegExpRule::aspScriptTags);
    }
};
