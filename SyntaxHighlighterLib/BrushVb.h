
class BrushVb : public Brush
{
public:
    static const wchar_t* exts[2];

    BrushVb()
        : Brush(L"VbScript")
    {
        String keywords = L"AddHandler AddressOf AndAlso Alias And Ansi As Assembly Auto "
            L"Boolean ByRef Byte ByVal Call Case Catch CBool CByte CChar CDate "
            L"CDec CDbl Char CInt Class CLng CObj Const CShort CSng CStr CType "
            L"Date Decimal Declare Default Delegate Dim DirectCast Do Double Each "
            L"Else ElseIf End Enum Erase Error Event Exit False Finally For Friend "
            L"Function Get GetType GoSub GoTo Handles If Implements Imports In "
            L"Inherits Integer Interface Is Let Lib Like Long Loop Me Mod Module "
            L"MustInherit MustOverride MyBase MyClass Namespace New Next Not Nothing "
            L"NotInheritable NotOverridable Object On Option Optional Or OrElse "
            L"Overloads Overridable Overrides ParamArray Preserve Private Property "
            L"Protected Public RaiseEvent ReadOnly ReDim REM RemoveHandler Resume "
            L"Return Select Set Shadows Shared Short Single Static Step Stop String "
            L"Structure Sub SyncLock Then Throw To True Try TypeOf Unicode Until "
            L"Variant When While With WithEvents WriteOnly Xor";

        add(RegExpRule(L"'.*$", Pattern::MULTILINE, COMMENTS)); // one line comments
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING)); // strings
        add(RegExpRule(L"^\\s*#.*$", Pattern::MULTILINE, PREPROCESSOR)); // preprocessor tags like #region and #endregion
        add(RegExpRule(getKeywords(keywords), KEYWORD)); // vb keyword

        setHTMLScriptPattern(RegExpRule::aspScriptTags);
    }
};
