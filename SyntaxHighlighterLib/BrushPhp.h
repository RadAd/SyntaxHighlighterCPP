
class BrushPhp : public Brush
{
public:
    static const wchar_t* exts[6];

    BrushPhp()
        : Brush(L"PHP")
    {

        String functions = L"abs acos acosh addcslashes addslashes "
            L"array_change_key_case array_chunk array_combine array_count_values array_diff "
            L"array_diff_assoc array_diff_key array_diff_uassoc array_diff_ukey array_fill "
            L"array_filter array_flip array_intersect array_intersect_assoc array_intersect_key "
            L"array_intersect_uassoc array_intersect_ukey array_key_exists array_keys array_map "
            L"array_merge array_merge_recursive array_multisort array_pad array_pop array_product "
            L"array_push array_rand array_reduce array_reverse array_search array_shift "
            L"array_slice array_splice array_sum array_udiff array_udiff_assoc "
            L"array_udiff_uassoc array_uintersect array_uintersect_assoc "
            L"array_uintersect_uassoc array_unique array_unshift array_values array_walk "
            L"array_walk_recursive atan atan2 atanh base64_decode base64_encode base_convert "
            L"basename bcadd bccomp bcdiv bcmod bcmul bindec bindtextdomain bzclose bzcompress "
            L"bzdecompress bzerrno bzerror bzerrstr bzflush bzopen bzread bzwrite ceil chdir "
            L"checkdate checkdnsrr chgrp chmod chop chown chr chroot chunk_split class_exists "
            L"closedir closelog copy cos cosh count count_chars date decbin dechex decoct "
            L"deg2rad delete ebcdic2ascii echo empty end ereg ereg_replace eregi eregi_replace error_log "
            L"error_reporting escapeshellarg escapeshellcmd eval exec exit exp explode extension_loaded "
            L"feof fflush fgetc fgetcsv fgets fgetss file_exists file_get_contents file_put_contents "
            L"fileatime filectime filegroup fileinode filemtime fileowner fileperms filesize filetype "
            L"floatval flock floor flush fmod fnmatch fopen fpassthru fprintf fputcsv fputs fread fscanf "
            L"fseek fsockopen fstat ftell ftok getallheaders getcwd getdate getenv gethostbyaddr gethostbyname "
            L"gethostbynamel getimagesize getlastmod getmxrr getmygid getmyinode getmypid getmyuid getopt "
            L"getprotobyname getprotobynumber getrandmax getrusage getservbyname getservbyport gettext "
            L"gettimeofday gettype glob gmdate gmmktime ini_alter ini_get ini_get_all ini_restore ini_set "
            L"interface_exists intval ip2long is_a is_array is_bool is_callable is_dir is_double "
            L"is_executable is_file is_finite is_float is_infinite is_int is_integer is_link is_long "
            L"is_nan is_null is_numeric is_object is_readable is_real is_resource is_scalar is_soap_fault "
            L"is_string is_subclass_of is_uploaded_file is_writable is_writeable mkdir mktime nl2br "
            L"parse_ini_file parse_str parse_url passthru pathinfo print readlink realpath rewind rewinddir rmdir "
            L"round str_ireplace str_pad str_repeat str_replace str_rot13 str_shuffle str_split "
            L"str_word_count strcasecmp strchr strcmp strcoll strcspn strftime strip_tags stripcslashes "
            L"stripos stripslashes stristr strlen strnatcasecmp strnatcmp strncasecmp strncmp strpbrk "
            L"strpos strptime strrchr strrev strripos strrpos strspn strstr strtok strtolower strtotime "
            L"strtoupper strtr strval substr substr_compare";
        String keywords = L"abstract and array as break case catch cfunction class clone const continue declare default die do "
            L"else elseif enddeclare endfor endforeach endif endswitch endwhile extends final for foreach "
            L"function include include_once global goto if implements interface instanceof namespace new "
            L"old_function or private protected public return require require_once static switch "
            L"throw try use var while xor";
        String constants = L"__FILE__ __LINE__ __METHOD__ __FUNCTION__ __CLASS__";

        add(RegExpRule(RegExpRule::singleLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::multiLineCComments, COMMENTS));
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"\\$\\w+", VARIABLE)); // variables
        add(RegExpRule(getKeywords(functions), Pattern::CASE_INSENSITIVE, FUNCTION));
        add(RegExpRule(getKeywords(constants), Pattern::CASE_INSENSITIVE, CONSTANT));
        add(RegExpRule(getKeywords(keywords), KEYWORD));

        setHTMLScriptPattern(RegExpRule::phpScriptTags);
    }
};
