#include "stdafx.h"

#include "RegExpRule.h"

const Pattern RegExpRule::multiLineCComments(L"\\/\\*.*?\\*\\/", Pattern::DOTALL);
const Pattern RegExpRule::singleLineCComments(L"\\/\\/.*$", Pattern::MULTILINE);
const Pattern RegExpRule::singleLinePerlComments(L"#.*$", Pattern::MULTILINE);
const Pattern RegExpRule::doubleQuotedString(L"\"([^\\\\\"\\r\\n]|\\\\.)*\"");
const Pattern RegExpRule::singleQuotedString(L"'([^\\\\'\\r\\n]|\\\\.)*'");
const Pattern RegExpRule::multiLineDoubleQuotedString(L"\"([^\\\\\"]|\\\\.)*\"", Pattern::DOTALL);
const Pattern RegExpRule::multiLineSingleQuotedString(L"'([^\\\\']|\\\\.)*'", Pattern::DOTALL);
const Pattern RegExpRule::phpScriptTags(L"(?:&lt;|<)\\?(?:=|php)(.*?)\\?(?:&gt;|>)", Pattern::CASE_INSENSITIVE | Pattern::DOTALL);
const Pattern RegExpRule::aspScriptTags(L"(?:&lt;|<)%=?(.*?)%(?:&gt;|>)", Pattern::CASE_INSENSITIVE | Pattern::DOTALL);
