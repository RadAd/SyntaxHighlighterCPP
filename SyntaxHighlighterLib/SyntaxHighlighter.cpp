#include "stdafx.h"

#include "include\SyntaxHighlighter.h"

#include <iterator>

#include "RegExpRule.h"
#include "include\Brush.h"

template<class V>
void MapRangeRemove(std::map<Range, V>& map, const Range& range)
{
    auto e = map.lower_bound(range);
    if (!map.empty() && e != map.begin())
    {
        const auto ep = std::prev(e);
        if (ep->first.end > range.end)
        {
            Range rn(ep->first);
            rn.start = range.end;
            e = map.insert(e, std::map<Range, V>::value_type(rn, ep->second));
        }
        if (ep->first.end > range.start)
        {
            Range rp(ep->first);
            V styleKeyp = ep->second;
            rp.end = range.start;
            map.erase(ep);
            if (!rp.empty())
                map[rp] = styleKeyp;
        }
    }
    while (e != map.end() && e->first.end <= range.end)
    {
        e = map.erase(e);
    }
    if (e != map.end() && e->first.start < range.end)
    {
        Range rn(e->first);
        V styleKeyn = e->second;
        e = map.erase(e);
        rn.start = range.end;
        if (!rn.empty())
            map[rn] = styleKeyn;
    }
}

template<class V>
void MapRangeAdd(std::map<Range, V>& map, const Range& range, const V& value)
{
    MapRangeRemove(map, range);
    map[range] = value;
}

template<class CharSequence>
SyntaxHighlighterMapT SyntaxHighlighter(const Brush* brush, const CharSequence& content)
{
    return SyntaxHighlighter(brush, content, 0, content.size());
}

template<class CharSequence>
SyntaxHighlighterMapT SyntaxHighlighter(const Brush* brush, const CharSequence& content, size_t allstart, size_t allend)
{
    SyntaxHighlighterMapT matches;
    SyntaxHighlighter1(matches, brush, content, allstart, allend);
    return matches;
}

template<class CharSequence>
void SyntaxHighlighter1(SyntaxHighlighterMapT& matches, const Brush* brush, const CharSequence& content, size_t allstart, size_t allend)
{
    const std::vector<RegExpRule>& regExpRuleList = brush->getRegExpRuleList();
    //for (const RegExpRule& regExpRule : reverse(regExpRuleList))
    for (auto it = regExpRuleList.rbegin(); it != regExpRuleList.rend(); ++it)
    {
        const RegExpRule& regExpRule = *it;
        SyntaxHighlighter2(matches, regExpRule, content, allstart, allend);
    }
}

template<class CharSequence>
void SyntaxHighlighter2(SyntaxHighlighterMapT& matches, const RegExpRule& regExpRule, const CharSequence& content, size_t allstart, size_t allend)
{
    const std::vector<RegExpRule::Op>& groupOperations = regExpRule.getGroupOperations();

    const Pattern& regExpPattern = regExpRule.getPattern();
    std::regex_iterator<CharSequence::const_iterator> matcher = std::regex_iterator<CharSequence::const_iterator>(content.begin() + allstart, content.begin() + allend, regExpPattern);
    while (matcher != std::regex_iterator<CharSequence::const_iterator>()) {
        // deal with the matched result
        for (size_t groupId = 0; groupId < groupOperations.size(); ++groupId)
            //for (size_t groupId = 0; groupId < matcher->size(); ++groupId)
        {
            const RegExpRule::Op& operation = groupOperations[groupId];

            // the start and end position of the match
            size_t start = matcher->position(groupId);
            size_t end = start + matcher->length(groupId);
            start += allstart;
            end += allstart;

            if (operation.object != nullptr)
            {
                switch (operation.type)
                {
                case RegExpRule::Op::T_STRING:
                    // add the style to the match
                    MapRangeAdd(matches, Range(start, end), static_cast<const wchar_t*>(operation.object));
                    break;
                case RegExpRule::Op::T_RULE:
                    // parse the result using the <code>operation</code> RegExpRule
                    SyntaxHighlighter2(matches, *static_cast<const RegExpRule*>(operation.object), content, start, end);
                    break;
                case RegExpRule::Op::T_BRUSH:
                    // parse the result using the <code>operation</code> RegExpRule
                    MapRangeRemove(matches, Range(start, end));
                    SyntaxHighlighter1(matches, static_cast<const Brush*>(operation.object), content, start, end);
                    break;
                }
            }
        }
        ++matcher;
    }
}


SyntaxHighlighterMapT SyntaxHighlighter(const Brush* brush, const std::wstring& content)
{
    return SyntaxHighlighter<std::wstring>(brush, content);
}

SyntaxHighlighterMapT SyntaxHighlighter(const Brush* brush, const std::wstring& content, size_t allstart, size_t allend)
{
    return SyntaxHighlighter<std::wstring>(brush, content, allstart, allend);
}

SyntaxHighlighterMapT SyntaxHighlighter(const Brush* brush, const std::vector<wchar_t>& content)
{
    return SyntaxHighlighter<std::vector<wchar_t>>(brush, content);
}

SyntaxHighlighterMapT SyntaxHighlighter(const Brush* brush, const std::vector<wchar_t>& content, size_t allstart, size_t allend)
{
    return SyntaxHighlighter<std::vector<wchar_t>>(brush, content, allstart, allend);
}
