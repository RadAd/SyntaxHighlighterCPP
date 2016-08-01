
class BrushCss : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushCss()
        : Brush(L"CSS")
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
            L"vertical-align visibility voice-family volume white-space widows width widths word-spacing x-height z-index";
        String values = L"above absolute all always aqua armenian attr aural auto avoid baseline behind below bidi-override black blink block blue bold bolder "
            L"both bottom braille capitalize caption center center-left center-right circle close-quote collapse compact condensed "
            L"continuous counter counters crop cross crosshair cursive dashed decimal decimal-leading-zero default digits disc dotted double "
            L"embed embossed e-resize expanded extra-condensed extra-expanded fantasy far-left far-right fast faster fixed format fuchsia "
            L"gray green groove handheld hebrew help hidden hide high higher icon inline-table inline inset inside invert italic "
            L"justify landscape large larger left-side left leftwards level lighter lime line-through list-item local loud lower-alpha "
            L"lowercase lower-greek lower-latin lower-roman lower low ltr marker maroon medium message-box middle mix move narrower "
            L"navy ne-resize no-close-quote none no-open-quote no-repeat normal nowrap n-resize nw-resize oblique olive once open-quote outset "
            L"outside overline pointer portrait print projection purple red relative repeat repeat-x repeat-y rgb ridge right right-side "
            L"rightwards rtl run-in screen scroll semi-condensed semi-expanded separate se-resize show silent silver slower slow "
            L"small small-caps small-caption smaller soft solid speech spell-out square s-resize static status-bar sub super sw-resize "
            L"table-caption table-cell table-column table-column-group table-footer-group table-header-group table-row table-row-group teal "
            L"text-bottom text-top thick thin top transparent tty tv ultra-condensed ultra-expanded underline upper-alpha uppercase upper-latin "
            L"upper-roman url visible wait white wider w-resize x-fast x-high x-large x-loud x-low x-slow x-small x-soft xx-large xx-small yellow";
        String htmltags = L"body a code div h1 h2 h3 h4 h5 h6 img li ol p pre span table th td tr ul";
        String fonts = L"[mM]onospace [tT]ahoma [vV]erdana [aA]rial [hH]elvetica [sS]ans-serif [sS]erif [cC]ourier mono sans serif";

        add(RegExpRule(RegExpRule::multiLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"\\#[a-fA-F0-9]{3,6}", VALUE)); // html colors
        add(RegExpRule(L"(-?\\d+)(\\.\\d+)?(px|em|pt|\\:|\\%|)", VALUE)); // sizes
        add(RegExpRule(L"!important", COLOR3)); // !important
        add(RegExpRule(getKeywordsCSS(keywords), KEYWORD));
        add(RegExpRule(getValuesCSS(values), VALUE));
        add(RegExpRule(getKeywords(htmltags), COLOR1));
        add(RegExpRule(getKeywords(fonts), COLOR2));

        setHTMLScriptPattern(RegExpRule::createScriptPattern(L"style", L"text/css"));
    }
};
