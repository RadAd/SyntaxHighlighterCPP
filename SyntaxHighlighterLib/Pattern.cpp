#include "stdafx.h"

#include "Pattern.h"

void Pattern::replace(String& p, wchar_t c, const String& replacement)
{
    for (size_t i = 0; i < p.length(); ++i)
    {
        if (p[i] == L'\\')
            ++i;
        else if (p[i] == c)
        {
            p.erase(i, 1);
            p.insert(i, replacement);
            i += replacement.length() - 1;
        }
    }
}

String Pattern::pattern(String p, int f)
{
    if (f & MULTILINE && (p.front() != L'^' && p.back() != L'$'))
        throw std::exception("Not a multiline");
    if ((f & MULTILINE) == 0 && (p.front() == L'^' || p.back() == L'$'))
        throw std::exception("Is a multiline");
    if (f & MULTILINE && p.back() == L'$')
        p.insert(p.length() - 1, L"(\\r)?");
    if (f & DOTALL)
        replace(p, L'.', L"[\\s\\S]");

    return p;
}

Pattern::flag_type Pattern::flags(int f)
{
    flag_type flag = ECMAScript | optimize;
    if (f & CASE_INSENSITIVE) flag |= icase;
    return flag;
}
