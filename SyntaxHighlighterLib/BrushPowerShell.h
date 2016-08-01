
class BrushPowerShell : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushPowerShell()
        : Brush(L"PowerShell")
    {
        // Contributes by B.v.Zanten, Getronics
        // http://confluence.atlassian.com/display/CONFEXT/New+Code+Macro

        String keywords = L"Add-Content Add-History Add-Member Add-PSSnapin Clear(-Content)? Clear-Item "
            L"Clear-ItemProperty Clear-Variable Compare-Object ConvertFrom-SecureString Convert-Path "
            L"ConvertTo-Html ConvertTo-SecureString Copy(-Item)? Copy-ItemProperty Export-Alias "
            L"Export-Clixml Export-Console Export-Csv ForEach(-Object)? Format-Custom Format-List "
            L"Format-Table Format-Wide Get-Acl Get-Alias Get-AuthenticodeSignature Get-ChildItem Get-Command "
            L"Get-Content Get-Credential Get-Culture Get-Date Get-EventLog Get-ExecutionPolicy "
            L"Get-Help Get-History Get-Host Get-Item Get-ItemProperty Get-Location Get-Member "
            L"Get-PfxCertificate Get-Process Get-PSDrive Get-PSProvider Get-PSSnapin Get-Service "
            L"Get-TraceSource Get-UICulture Get-Unique Get-Variable Get-WmiObject Group-Object "
            L"Import-Alias Import-Clixml Import-Csv Invoke-Expression Invoke-History Invoke-Item "
            L"Join-Path Measure-Command Measure-Object Move(-Item)? Move-ItemProperty New-Alias "
            L"New-Item New-ItemProperty New-Object New-PSDrive New-Service New-TimeSpan "
            L"New-Variable Out-Default Out-File Out-Host Out-Null Out-Printer Out-String Pop-Location "
            L"Push-Location Read-Host Remove-Item Remove-ItemProperty Remove-PSDrive Remove-PSSnapin "
            L"Remove-Variable Rename-Item Rename-ItemProperty Resolve-Path Restart-Service Resume-Service "
            L"Select-Object Select-String Set-Acl Set-Alias Set-AuthenticodeSignature Set-Content "
            L"Set-Date Set-ExecutionPolicy Set-Item Set-ItemProperty Set-Location Set-PSDebug "
            L"Set-Service Set-TraceSource Set(-Variable)? Sort-Object Split-Path Start-Service "
            L"Start-Sleep Start-Transcript Stop-Process Stop-Service Stop-Transcript Suspend-Service "
            L"Tee-Object Test-Path Trace-Command Update-FormatData Update-TypeData Where(-Object)? "
            L"Write-Debug Write-Error Write(-Host)? Write-Output Write-Progress Write-Verbose Write-Warning";
        String alias = L"ac asnp clc cli clp clv cpi cpp cvpa diff epal epcsv fc fl "
            L"ft fw gal gc gci gcm gdr ghy gi gl gm gp gps group gsv "
            L"gsnp gu gv gwmi iex ihy ii ipal ipcsv mi mp nal ndr ni nv oh rdr "
            L"ri rni rnp rp rsnp rv rvpa sal sasv sc select si sl sleep sort sp "
            L"spps spsv sv tee cat cd cp h history kill lp ls "
            L"mount mv popd ps pushd pwd r rm rmdir echo cls chdir del dir "
            L"erase rd ren type % \\?";

        add(RegExpRule(L"#.*$", Pattern::MULTILINE, COMMENTS)); // one line comments
        add(RegExpRule(L"\\$[a-zA-Z0-9]+\\b", VALUE)); // variables $Computer1
        add(RegExpRule(L"\\-[a-zA-Z]+\\b", KEYWORD)); // Operators    -not  -and  -eq
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(getKeywords(keywords), Pattern::CASE_INSENSITIVE, KEYWORD));
        add(RegExpRule(getKeywords(alias), Pattern::CASE_INSENSITIVE, KEYWORD));
    }
};
