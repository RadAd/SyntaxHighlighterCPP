
class BrushPerl : public Brush
{
public:
    static const wchar_t* exts[3];

    BrushPerl()
        : Brush(L"Perl")
    {

        // Contributed by David Simmons-Duffin and Marty Kube

        String functions = L"abs accept alarm atan2 bind binmode chdir chmod chomp chop chown chr "
            L"chroot close closedir connect cos crypt defined delete each endgrent "
            L"endhostent endnetent endprotoent endpwent endservent eof exec exists "
            L"exp fcntl fileno flock fork format formline getc getgrent getgrgid "
            L"getgrnam gethostbyaddr gethostbyname gethostent getlogin getnetbyaddr "
            L"getnetbyname getnetent getpeername getpgrp getppid getpriority "
            L"getprotobyname getprotobynumber getprotoent getpwent getpwnam getpwuid "
            L"getservbyname getservbyport getservent getsockname getsockopt glob "
            L"gmtime grep hex index int ioctl join keys kill lc lcfirst length link "
            L"listen localtime lock log lstat map mkdir msgctl msgget msgrcv msgsnd "
            L"oct open opendir ord pack pipe pop pos print printf prototype push "
            L"quotemeta rand read readdir readline readlink readpipe recv rename "
            L"reset reverse rewinddir rindex rmdir scalar seek seekdir select semctl "
            L"semget semop send setgrent sethostent setnetent setpgrp setpriority "
            L"setprotoent setpwent setservent setsockopt shift shmctl shmget shmread "
            L"shmwrite shutdown sin sleep socket socketpair sort splice split sprintf "
            L"sqrt srand stat study substr symlink syscall sysopen sysread sysseek "
            L"system syswrite tell telldir time times tr truncate uc ucfirst umask "
            L"undef unlink unpack unshift utime values vec wait waitpid warn write";
        String keywords = L"bless caller continue dbmclose dbmopen die do dump else elsif eval exit "
            L"for foreach goto if import last local my next no our package redo ref "
            L"require return sub tie tied unless untie until use wantarray while";

        add(RegExpRule(L"#[^!].*$", Pattern::MULTILINE, COMMENTS));
        add(RegExpRule(L"^\\s*#!.*$", Pattern::MULTILINE, PREPROCESSOR)); // shebang
        add(RegExpRule(RegExpRule::doubleQuotedString, STRING));
        add(RegExpRule(RegExpRule::singleQuotedString, STRING));
        add(RegExpRule(L"(\\$|@|%)\\w+", VARIABLE));
        add(RegExpRule(getKeywords(functions), Pattern::CASE_INSENSITIVE, FUNCTION));
        add(RegExpRule(getKeywords(keywords), KEYWORD));

        setHTMLScriptPattern(RegExpRule::aspScriptTags);
    }
};
