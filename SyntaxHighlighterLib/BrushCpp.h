
class BrushCpp : public Brush
{
public:
    static const wchar_t* exts[4];

    BrushCpp()
        : Brush(L"C/C++")
    {
        String datatypes = L"ATOM BOOL BOOLEAN BYTE CHAR COLORREF DWORD DWORDLONG DWORD_PTR "
            L"DWORD32 DWORD64 FLOAT HACCEL HALF_PTR HANDLE HBITMAP HBRUSH "
            L"HCOLORSPACE HCONV HCONVLIST HCURSOR HDC HDDEDATA HDESK HDROP HDWP "
            L"HENHMETAFILE HFILE HFONT HGDIOBJ HGLOBAL HHOOK HICON HINSTANCE HKEY "
            L"HKL HLOCAL HMENU HMETAFILE HMODULE HMONITOR HPALETTE HPEN HRESULT "
            L"HRGN HRSRC HSZ HWINSTA HWND INT INT_PTR INT32 INT64 LANGID LCID LCTYPE "
            L"LGRPID LONG LONGLONG LONG_PTR LONG32 LONG64 LPARAM LPBOOL LPBYTE LPCOLORREF "
            L"LPCSTR LPCTSTR LPCVOID LPCWSTR LPDWORD LPHANDLE LPINT LPLONG LPSTR LPTSTR "
            L"LPVOID LPWORD LPWSTR LRESULT PBOOL PBOOLEAN PBYTE PCHAR PCSTR PCTSTR PCWSTR "
            L"PDWORDLONG PDWORD_PTR PDWORD32 PDWORD64 PFLOAT PHALF_PTR PHANDLE PHKEY PINT "
            L"PINT_PTR PINT32 PINT64 PLCID PLONG PLONGLONG PLONG_PTR PLONG32 PLONG64 POINTER_32 "
            L"POINTER_64 PSHORT PSIZE_T PSSIZE_T PSTR PTBYTE PTCHAR PTSTR PUCHAR PUHALF_PTR "
            L"PUINT PUINT_PTR PUINT32 PUINT64 PULONG PULONGLONG PULONG_PTR PULONG32 PULONG64 "
            L"PUSHORT PVOID PWCHAR PWORD PWSTR SC_HANDLE SC_LOCK SERVICE_STATUS_HANDLE SHORT "
            L"SIZE_T SSIZE_T TBYTE TCHAR UCHAR UHALF_PTR UINT UINT_PTR UINT32 UINT64 ULONG "
            L"ULONGLONG ULONG_PTR ULONG32 ULONG64 USHORT USN VOID WCHAR WORD WPARAM WPARAM WPARAM "
            L"char bool short int __int32 __int64 __int8 __int16 long float double __wchar_t "
            L"clock_t _complex _dev_t _diskfree_t div_t ldiv_t _exception exception _EXCEPTION_POINTERS "
            L"FILE _finddata_t _finddatai64_t _wfinddata_t _wfinddatai64_t __finddata64_t "
            L"__wfinddata64_t _FPIEEE_RECORD fpos_t _HEAPINFO _HFILE lconv intptr_t _locale_t "
            L"jmp_buf mbstate_t _off_t _onexit_t _PNH ptrdiff_t _purecall_handler "
            L"sig_atomic_t size_t _stat __stat64 _stati64 terminate_function "
            L"time_t __time64_t _timeb __timeb64 tm uintptr_t _utimbuf "
            L"va_list wchar_t wctrans_t wctype_t wint_t signed "
            L"std const_iterator deque iterator list multimap map pair set string stringstream vector wstring wstringstream";
        String keywords = L"break case catch class const __finally __exception __try "
            L"const_cast continue private public protected __declspec "
            L"default delete deprecated dllexport dllimport do dynamic_cast "
            L"else enum explicit extern if for friend goto inline "
            L"mutable naked namespace new noinline noreturn nothrow "
            L"register reinterpret_cast return selectany "
            L"sizeof static static_cast struct switch template "
            L"thread throw try typedef typeid typename union "
            L"using uuid virtual void volatile whcar_t while";
#if 0
        String functions = L"assert isalnum isalpha iscntrl isdigit isgraph islower isprint"
            L"ispunct isspace isupper isxdigit tolower toupper errno localeconv "
            L"setlocale acos asin atan atan2 ceil cos cosh exp fabs floor fmod "
            L"frexp ldexp log log10 modf pow sin sinh sqrt tan tanh jmp_buf "
            L"longjmp setjmp raise signal sig_atomic_t va_arg va_end va_start "
            L"clearerr fclose feof ferror fflush fgetc fgetpos fgets fopen "
            L"fprintf fputc fputs fread freopen fscanf fseek fsetpos ftell "
            L"fwrite getc getchar gets perror printf putc putchar puts remove "
            L"rename rewind scanf setbuf setvbuf sprintf sscanf tmpfile tmpnam "
            L"ungetc vfprintf vprintf vsprintf abort abs atexit atof atoi atol "
            L"bsearch calloc div exit free getenv labs ldiv malloc mblen mbstowcs "
            L"mbtowc qsort rand realloc srand strtod strtol strtoul system "
            L"wcstombs wctomb memchr memcmp memcpy memmove memset strcat strchr "
            L"strcmp strcoll strcpy strcspn strerror strlen strncat strncmp "
            L"strncpy strpbrk strrchr strspn strstr strtok strxfrm asctime "
            L"clock ctime difftime gmtime localtime mktime strftime time";
#endif

        // TODO Add something for "TODO" ???
        // TODO Separate keyword type into other types???
        // TODO Separate type for operators???
        // TODO Open ended strings???

        add(RegExpRule(RegExpRule::singleLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::multiLineCComments, COMMENTS));
        //add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        //add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"L?" L"\"([^\\\\\"\\r\\n]|\\\\.)*\"", STRING)); // "L?" + RegExpRule::doubleQuotedString
        add(RegExpRule(L"L?" L"'([^\\\\'\\r\\n]|\\\\.)*'", STRING)); // "L?" + RegExpRule::singleQuotedString
        add(RegExpRule(L"include\\s+(<([^\\\\'\\r\\n]|\\\\.)*>)", nullptr).addGroupOperation(STRING)); // include <>
        add(RegExpRule(L"[+-]?\\b(\\d+(\\.\\d+)?f?|0x[a-f0-9]+|0b[\\d]+)\\b", Pattern::CASE_INSENSITIVE, VALUE)); // numbers
        add(RegExpRule(getKeywords(L"true false nullptr this TRUE FALSE NULL"), VALUE));
        add(RegExpRule(L"^\\s*#.*$", Pattern::MULTILINE, PREPROCESSOR));
        add(RegExpRule(getKeywords(datatypes), TYPE));
        add(RegExpRule(L"[\\!=\\+\\-<>*&%]", KEYWORD)); // OPERATORS
        add(RegExpRule(getKeywords(keywords), KEYWORD));
        //add(RegExpRule(getKeywords(functions), FUNCTION));
        add(RegExpRule(L"\\b(\\w)+(\\s)*(?=\\()", FUNCTION));
    }
};
