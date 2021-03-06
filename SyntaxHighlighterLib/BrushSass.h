
class BrushSass : public Brush
{
public:
    static const wchar_t* exts[2];

    BrushSass()
        : Brush(L"Sass")
    {
        String keywords = L"ascent azimuth background-attachment background-color background-image background-position "
            L"background-repeat background baseline bbox border-collapse border-color border-spacing border-style border-top "
            L"border-right border-bottom border-left border-top-color border-right-color border-bottom-color border-left-color "
            L"border-top-style border-right-style border-bottom-style border-left-style border-top-width border-right-width "
            L"border-bottom-width border-left-width border-width border bottom cap-height caption-side centerline clear clip color "
            L"content counter-increment counter-reset cue-after cue-before cue cursor definition-src descent direction display "
            L"elevation empty-cells float font-size-adjust font-family font-size font-stretch font-style font-variant font-weight font "
            L"height left letter-spacing line-height list-style-image list-style-position list-style-type list-style margin-top "
            L"margin-right margin-bottom margin-left margin marker-offset marks mathline max-height max-width min-height min-width orphans "
            L"outline-color outline-style outline-width outline overflow padding-top padding-right padding-bottom padding-left padding page "
            L"page-break-after page-break-before page-break-inside pause pause-after pause-before pitch pitch-range play-during position "
            L"quotes right richness size slope src speak-header speak-numeral speak-punctuation speak speech-rate stemh stemv stress "
            L"table-layout text-align top text-decoration text-indent text-shadow text-transform unicode-bidi unicode-range units-per-em "
            L"vertical-align visibility voice-family volume white-space widows width widths word-spacing x-height z-index zoom";
        String values = L"above absolute all always aqua armenian attr aural auto avoid baseline behind below bidi-override black blink block blue bold bolder "
            L"both bottom braille capitalize caption center center-left center-right circle close-quote code collapse compact condensed "
            L"continuous counter counters crop cross crosshair cursive dashed decimal decimal-leading-zero digits disc dotted double "
            L"embed embossed e-resize expanded extra-condensed extra-expanded fantasy far-left far-right fast faster fixed format fuchsia "
            L"gray green groove handheld hebrew help hidden hide high higher icon inline-table inline inset inside invert italic "
            L"justify landscape large larger left-side left leftwards level lighter lime line-through list-item local loud lower-alpha "
            L"lowercase lower-greek lower-latin lower-roman lower low ltr marker maroon medium message-box middle mix move narrower "
            L"navy ne-resize no-close-quote none no-open-quote no-repeat normal nowrap n-resize nw-resize oblique olive once open-quote outset "
            L"outside overline pointer portrait pre print projection purple red relative repeat repeat-x repeat-y rgb ridge right right-side "
            L"rightwards rtl run-in screen scroll semi-condensed semi-expanded separate se-resize show silent silver slower slow "
            L"small small-caps small-caption smaller soft solid speech spell-out square s-resize static status-bar sub super sw-resize "
            L"table-caption table-cell table-column table-column-group table-footer-group table-header-group table-row table-row-group teal "
            L"text-bottom text-top thick thin top transparent tty tv ultra-condensed ultra-expanded underline upper-alpha uppercase upper-latin "
            L"upper-roman url visible wait white wider w-resize x-fast x-high x-large x-loud x-low x-slow x-small x-soft xx-large xx-small yellow";
        String fonts = L"[mM]onospace [tT]ahoma [vV]erdana [aA]rial [hH]elvetica [sS]ans-serif [sS]erif [cC]ourier mono sans serif";
        String statements = L"!important !default";
        String preprocessors = L"import extend debug warn if for while mixin include";

        add(RegExpRule(RegExpRule::multiLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::singleLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"\\#[a-fA-F0-9]{3,6}", VALUE)); // html colors
        add(RegExpRule(L"\\b(-?\\d+)(\\.\\d+)?(px|em|pt|\\:|\\%|)\\b", VALUE)); // sizes
        add(RegExpRule(L"(\\$|!)\\w+", VARIABLE)); // variables
        add(RegExpRule(getKeywords(statements), COLOR3));
        add(RegExpRule(getKeywordsPrependedBy(preprocessors, L"@"), PREPROCESSOR));
        add(RegExpRule(L"(^|\\n)\\s*=.*", FUNCTION)); // short mixin declarations
        add(RegExpRule(L"(^|\\n)\\s*\\+.*", FUNCTION)); // short mixin call
        add(RegExpRule(L"&amp;", KEYWORD)); // &
        add(RegExpRule(L"#(\\w|-|_)+", COLOR2)); // ids
        // original code uses 'color4' which do not exist yet, here uses color1 as a temporary replacement
        add(RegExpRule(L"(\\.(\\w|-|_)+)", COLOR1)); // classes
        add(RegExpRule(getKeywordsCSS(keywords), KEYWORD));
        add(RegExpRule(getKeywordsPrependedBy(keywords, L":"), KEYWORD)); // :keyword value
        add(RegExpRule(getValuesCSS(values), VALUE));
        add(RegExpRule(getKeywords(fonts), COLOR1));
    }

protected:
    static String getKeywordsPrependedBy(String keywords, const String& by)
    {
        tidySpaces(keywords);
        replace(keywords, L' ', L"|" + by + L"\\b");
        return L"(?:" + by + L"\\b" + keywords + L")\\b";
    }
};
