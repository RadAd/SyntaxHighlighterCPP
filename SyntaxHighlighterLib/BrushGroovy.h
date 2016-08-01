
class BrushGroovy : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushGroovy()
        : Brush(L"Groovy")
    {
        // Contributed by Andres Almiray
        // http://jroller.com/aalmiray/entry/nice_source_code_syntax_highlighter

        String keywords = L"as assert break case catch class continue def default do else extends finally "
            L"if in implements import instanceof interface new package property return switch "
            L"throw throws try while public protected private static";
        String types = L"void boolean byte char short int long float double";
        String constants = L"null";
        String methods = L"allProperties count get size "
            L"collect each eachProperty eachPropertyName eachWithIndex find findAll "
            L"findIndexOf grep inject max min reverseEach sort "
            L"asImmutable asSynchronized flatten intersect join pop reverse subMap toList "
            L"padRight padLeft contains eachMatch toCharacter toLong toUrl tokenize "
            L"eachFile eachFileRecurse eachB yte eachLine readBytes readLine getText "
            L"splitEachLine withReader append encodeBase64 decodeBase64 filterLine "
            L"transformChar transformLine withOutputStream withPrintWriter withStream "
            L"withStreams withWriter withWriterAppend write writeLine "
            L"dump inspect invokeMethod print println step times upto use waitForOrKill "
            L"getText";

        add(RegExpRule(RegExpRule::singleLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::multiLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"\"\"\".*\"\"\"", STRING)); // GStrings
        add(RegExpRule(L"\\b([\\d]+(\\.[\\d]+)?|0x[a-f0-9]+)\\b", Pattern::CASE_INSENSITIVE, VALUE)); // numbers
        add(RegExpRule(getKeywords(keywords), KEYWORD));
        add(RegExpRule(getKeywords(types), COLOR1));
        add(RegExpRule(getKeywords(constants), CONSTANT));
        add(RegExpRule(getKeywords(methods), FUNCTION));

        setHTMLScriptPattern(RegExpRule::aspScriptTags);
    }
};
