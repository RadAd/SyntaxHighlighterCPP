
class BrushBash : public Brush
{
public:
    static const wchar_t* exts[1];

    BrushBash()
        : Brush(L"Bash")
    {
        String keywords = L"if fi then elif else for do done until while break continue case function return in eq ne ge le";
        String commands = L"alias apropos awk basename bash bc bg builtin bzip2 cal cat cd cfdisk chgrp chmod chown chroot"
            L"cksum clear cmp comm command cp cron crontab csplit cut date dc dd ddrescue declare df "
            L"diff diff3 dig dir dircolors dirname dirs du echo egrep eject enable env ethtool eval "
            L"exec exit expand export expr false fdformat fdisk fg fgrep file find fmt fold format "
            L"free fsck ftp gawk getopts grep groups gzip hash head history hostname id ifconfig "
            L"import install join kill less let ln local locate logname logout look lpc lpr lprint "
            L"lprintd lprintq lprm ls lsof make man mkdir mkfifo mkisofs mknod more mount mtools "
            L"mv netstat nice nl nohup nslookup open op passwd paste pathchk ping popd pr printcap "
            L"printenv printf ps pushd pwd quota quotacheck quotactl ram rcp read readonly renice "
            L"remsync rm rmdir rsync screen scp sdiff sed select seq set sftp shift shopt shutdown "
            L"sleep sort source split ssh strace su sudo sum symlink sync tail tar tee test time "
            L"times touch top traceroute trap tr true tsort tty type ulimit umask umount unalias "
            L"uname unexpand uniq units unset unshar useradd usermod users uuencode uudecode v vdir "
            L"vi watch wc whereis which who whoami Wget xargs yes";

        add(RegExpRule(L"^#!.*$", Pattern::MULTILINE, PREPROCESSOR));
        //add(RegExpRule(L"\\/[\\w-\\/]+", Pattern::MULTILINE, PLAIN));
        add(RegExpRule(RegExpRule::singleLinePerlComments, COMMENTS));
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(getKeywords(keywords), KEYWORD));
        add(RegExpRule(getKeywords(commands), FUNCTION));
    }
};
