#!/usr/bin/perl

open(MYOUTFILE,">fileList_TTnoJer.txt");
open(MYINPUTFILE,"dirList_TTnojer.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 


