
class BrushSql : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushSql()
        : Brush(L"SQL")
    {
        String functions = L"abs avg case cast coalesce convert count current_timestamp "
            L"current_user day isnull left lower month nullif replace right "
            L"session_user space substring sum system_user upper user year";
        String keywords = L"absolute action add after alter as asc at authorization begin bigint "
            L"binary bit by cascade char character check checkpoint close collate "
            L"column commit committed connect connection constraint contains continue "
            L"create cube current current_date current_time cursor database date "
            L"deallocate dec decimal declare default delete desc distinct double drop "
            L"dynamic else end end-exec escape except exec execute false fetch first "
            L"float for force foreign forward free from full function global goto grant "
            L"group grouping having hour ignore index inner insensitive insert instead "
            L"int integer intersect into is isolation key last level load local max min "
            L"minute modify move name national nchar next no numeric of off on only "
            L"open option order out output partial password precision prepare primary "
            L"prior privileges procedure public read real references relative repeatable "
            L"restrict return returns revoke rollback rollup rows rule schema scroll "
            L"second section select sequence serializable set size smallint static "
            L"statistics table temp temporary then time timestamp to top transaction "
            L"translation trigger true truncate uncommitted union unique update values "
            L"varchar varying view when where with work";
        String operators = L"all and any between cross in join like not null or outer some";

        add(RegExpRule(L"--(.*)$", Pattern::MULTILINE, COMMENTS)); // one line and multiline comments
        add(RegExpRule(RegExpRule::multiLineDoubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::multiLineSingleQuotedString, STRING));
        add(RegExpRule(getKeywords(functions), Pattern::CASE_INSENSITIVE, FUNCTION));
        add(RegExpRule(getKeywords(operators), Pattern::CASE_INSENSITIVE, COLOR1));
        add(RegExpRule(getKeywords(keywords), Pattern::CASE_INSENSITIVE, KEYWORD));
    }
};
