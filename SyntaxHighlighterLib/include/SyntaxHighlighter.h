#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <map>
#include <vector>
#include <string>

#include "Range.h"

class Brush;

typedef std::map<Range, const wchar_t*> SyntaxHighlighterMapT;

SyntaxHighlighterMapT SyntaxHighlighter(const Brush* brush, const std::wstring& content);
SyntaxHighlighterMapT SyntaxHighlighter(const Brush* brush, const std::wstring& content, size_t allstart, size_t allend);

SyntaxHighlighterMapT SyntaxHighlighter(const Brush* brush, const std::vector<wchar_t>& content);
SyntaxHighlighterMapT SyntaxHighlighter(const Brush* brush, const std::vector<wchar_t>& content, size_t allstart, size_t allend);

#endif
