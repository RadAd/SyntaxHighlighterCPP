
class BrushColdFusion : public Brush
{
public:
    static const wchar_t* exts[2];

    BrushColdFusion()
        : Brush(L"ColdFusion")
    {
        // Contributed by Jen
        // http://www.jensbits.com/2009/05/14/coldfusion-brush-for-syntaxhighlighter-plus

        String functions = L"Abs ACos AddSOAPRequestHeader AddSOAPResponseHeader AjaxLink AjaxOnLoad ArrayAppend ArrayAvg ArrayClear ArrayDeleteAt "
            L"ArrayInsertAt ArrayIsDefined ArrayIsEmpty ArrayLen ArrayMax ArrayMin ArraySet ArraySort ArraySum ArraySwap ArrayToList "
            L"Asc ASin Atn BinaryDecode BinaryEncode BitAnd BitMaskClear BitMaskRead BitMaskSet BitNot BitOr BitSHLN BitSHRN BitXor "
            L"Ceiling CharsetDecode CharsetEncode Chr CJustify Compare CompareNoCase Cos CreateDate CreateDateTime CreateObject "
            L"CreateODBCDate CreateODBCDateTime CreateODBCTime CreateTime CreateTimeSpan CreateUUID DateAdd DateCompare DateConvert "
            L"DateDiff DateFormat DatePart Day DayOfWeek DayOfWeekAsString DayOfYear DaysInMonth DaysInYear DE DecimalFormat DecrementValue "
            L"Decrypt DecryptBinary DeleteClientVariable DeserializeJSON DirectoryExists DollarFormat DotNetToCFType Duplicate Encrypt "
            L"EncryptBinary Evaluate Exp ExpandPath FileClose FileCopy FileDelete FileExists FileIsEOF FileMove FileOpen FileRead "
            L"FileReadBinary FileReadLine FileSetAccessMode FileSetAttribute FileSetLastModified FileWrite Find FindNoCase FindOneOf "
            L"FirstDayOfMonth Fix FormatBaseN GenerateSecretKey GetAuthUser GetBaseTagData GetBaseTagList GetBaseTemplatePath "
            L"GetClientVariablesList GetComponentMetaData GetContextRoot GetCurrentTemplatePath GetDirectoryFromPath GetEncoding "
            L"GetException GetFileFromPath GetFileInfo GetFunctionList GetGatewayHelper GetHttpRequestData GetHttpTimeString "
            L"GetK2ServerDocCount GetK2ServerDocCountLimit GetLocale GetLocaleDisplayName GetLocalHostIP GetMetaData GetMetricData "
            L"GetPageContext GetPrinterInfo GetProfileSections GetProfileString GetReadableImageFormats GetSOAPRequest GetSOAPRequestHeader "
            L"GetSOAPResponse GetSOAPResponseHeader GetTempDirectory GetTempFile GetTemplatePath GetTickCount GetTimeZoneInfo GetToken "
            L"GetUserRoles GetWriteableImageFormats Hash Hour HTMLCodeFormat HTMLEditFormat IIf ImageAddBorder ImageBlur ImageClearRect "
            L"ImageCopy ImageCrop ImageDrawArc ImageDrawBeveledRect ImageDrawCubicCurve ImageDrawLine ImageDrawLines ImageDrawOval "
            L"ImageDrawPoint ImageDrawQuadraticCurve ImageDrawRect ImageDrawRoundRect ImageDrawText ImageFlip ImageGetBlob ImageGetBufferedImage "
            L"ImageGetEXIFTag ImageGetHeight ImageGetIPTCTag ImageGetWidth ImageGrayscale ImageInfo ImageNegative ImageNew ImageOverlay ImagePaste "
            L"ImageRead ImageReadBase64 ImageResize ImageRotate ImageRotateDrawingAxis ImageScaleToFit ImageSetAntialiasing ImageSetBackgroundColor "
            L"ImageSetDrawingColor ImageSetDrawingStroke ImageSetDrawingTransparency ImageSharpen ImageShear ImageShearDrawingAxis ImageTranslate "
            L"ImageTranslateDrawingAxis ImageWrite ImageWriteBase64 ImageXORDrawingMode IncrementValue InputBaseN Insert Int IsArray IsBinary "
            L"IsBoolean IsCustomFunction IsDate IsDDX IsDebugMode IsDefined IsImage IsImageFile IsInstanceOf IsJSON IsLeapYear IsLocalHost "
            L"IsNumeric IsNumericDate IsObject IsPDFFile IsPDFObject IsQuery IsSimpleValue IsSOAPRequest IsStruct IsUserInAnyRole IsUserInRole "
            L"IsUserLoggedIn IsValid IsWDDX IsXML IsXmlAttribute IsXmlDoc IsXmlElem IsXmlNode IsXmlRoot JavaCast JSStringFormat LCase Left Len "
            L"ListAppend ListChangeDelims ListContains ListContainsNoCase ListDeleteAt ListFind ListFindNoCase ListFirst ListGetAt ListInsertAt "
            L"ListLast ListLen ListPrepend ListQualify ListRest ListSetAt ListSort ListToArray ListValueCount ListValueCountNoCase LJustify Log "
            L"Log10 LSCurrencyFormat LSDateFormat LSEuroCurrencyFormat LSIsCurrency LSIsDate LSIsNumeric LSNumberFormat LSParseCurrency LSParseDateTime "
            L"LSParseEuroCurrency LSParseNumber LSTimeFormat LTrim Max Mid Min Minute Month MonthAsString Now NumberFormat ParagraphFormat ParseDateTime "
            L"Pi PrecisionEvaluate PreserveSingleQuotes Quarter QueryAddColumn QueryAddRow QueryConvertForGrid QueryNew QuerySetCell QuotedValueList Rand "
            L"Randomize RandRange REFind REFindNoCase ReleaseComObject REMatch REMatchNoCase RemoveChars RepeatString Replace ReplaceList ReplaceNoCase "
            L"REReplace REReplaceNoCase Reverse Right RJustify Round RTrim Second SendGatewayMessage SerializeJSON SetEncoding SetLocale SetProfileString "
            L"SetVariable Sgn Sin Sleep SpanExcluding SpanIncluding Sqr StripCR StructAppend StructClear StructCopy StructCount StructDelete StructFind "
            L"StructFindKey StructFindValue StructGet StructInsert StructIsEmpty StructKeyArray StructKeyExists StructKeyList StructKeyList StructNew "
            L"StructSort StructUpdate Tan TimeFormat ToBase64 ToBinary ToScript ToString Trim UCase URLDecode URLEncodedFormat URLSessionFormat Val "
            L"ValueList VerifyClient Week Wrap Wrap WriteOutput XmlChildPos XmlElemNew XmlFormat XmlGetNodeType XmlNew XmlParse XmlSearch XmlTransform "
            L"XmlValidate Year YesNoFormat";
        String keywords = L"cfabort cfajaximport cfajaxproxy cfapplet cfapplication cfargument cfassociate cfbreak cfcache cfcalendar "
            L"cfcase cfcatch cfchart cfchartdata cfchartseries cfcol cfcollection cfcomponent cfcontent cfcookie cfdbinfo "
            L"cfdefaultcase cfdirectory cfdiv cfdocument cfdocumentitem cfdocumentsection cfdump cfelse cfelseif cferror "
            L"cfexchangecalendar cfexchangeconnection cfexchangecontact cfexchangefilter cfexchangemail cfexchangetask "
            L"cfexecute cfexit cffeed cffile cfflush cfform cfformgroup cfformitem cfftp cffunction cfgrid cfgridcolumn "
            L"cfgridrow cfgridupdate cfheader cfhtmlhead cfhttp cfhttpparam cfif cfimage cfimport cfinclude cfindex "
            L"cfinput cfinsert cfinterface cfinvoke cfinvokeargument cflayout cflayoutarea cfldap cflocation cflock cflog "
            L"cflogin cfloginuser cflogout cfloop cfmail cfmailparam cfmailpart cfmenu cfmenuitem cfmodule cfNTauthenticate "
            L"cfobject cfobjectcache cfoutput cfparam cfpdf cfpdfform cfpdfformparam cfpdfparam cfpdfsubform cfpod cfpop "
            L"cfpresentation cfpresentationslide cfpresenter cfprint cfprocessingdirective cfprocparam cfprocresult "
            L"cfproperty cfquery cfqueryparam cfregistry cfreport cfreportparam cfrethrow cfreturn cfsavecontent cfschedule "
            L"cfscript cfsearch cfselect cfset cfsetting cfsilent cfslider cfsprydataset cfstoredproc cfswitch cftable "
            L"cftextarea cfthread cfthrow cftimer cftooltip cftrace cftransaction cftree cftreeitem cftry cfupdate cfwddx "
            L"cfwindow cfxml cfzip cfzipparam";
        String operators = L"all and any between cross in join like not null or outer some";

        add(RegExpRule(L"--(.*)$", Pattern::MULTILINE, COMMENTS)); // one line and multiline comments
        add(RegExpRule(L"\\w+:\\/\\/[\\w-.\\/?%&=:@;]*", COMMENTS)); // single quoted strings
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(getKeywords(functions), Pattern::CASE_INSENSITIVE, FUNCTION));
        add(RegExpRule(getKeywords(operators), Pattern::CASE_INSENSITIVE, COLOR1));
        add(RegExpRule(getKeywords(keywords), Pattern::CASE_INSENSITIVE, KEYWORD));
    }
};
