#!/usr/bin/perl
open(MYOUTFILE,">fileList_data.txt");
open(MYINPUTFILE,"dirList_data.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
open(MYOUTFILE,">fileList_TTpow.txt");
open(MYINPUTFILE,"dirList_TTpow.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
open(MYOUTFILE,">fileList_TTnlo.txt");
open(MYINPUTFILE,"dirList_TTnlo.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_TTJetsSplit.txt");
open(MYINPUTFILE,"dirList_TTJetsSplit.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_TTW.txt");
open(MYINPUTFILE,"dirList_TTW.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_TTZ.txt");
open(MYINPUTFILE,"dirList_TTZ.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_TTH.txt");
open(MYINPUTFILE,"dirList_TTH.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_DY.txt");
open(MYINPUTFILE,"dirList_DY.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);

open(MYOUTFILE,">fileList_t.txt");
open(MYINPUTFILE,"dirList_t.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_tbar.txt");
open(MYINPUTFILE,"dirList_tbar.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_tW.txt");
open(MYINPUTFILE,"dirList_tW.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_tWbar.txt");
open(MYINPUTFILE,"dirList_tWbar.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_s.txt");
open(MYINPUTFILE,"dirList_s.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_sbar.txt");
open(MYINPUTFILE,"dirList_sbar.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_H90.txt");
open(MYINPUTFILE,"dirList_H90.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);

open(MYOUTFILE,">fileList_H100.txt");
open(MYINPUTFILE,"dirList_H100.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_H110.txt");
open(MYINPUTFILE,"dirList_H110.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_H120.txt");
open(MYINPUTFILE,"dirList_H120.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);

open(MYOUTFILE,">fileList_H130.txt");
open(MYINPUTFILE,"dirList_H130.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_H140.txt");
open(MYINPUTFILE,"dirList_H140.txt");
my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_H150.txt");
open(MYINPUTFILE,"dirList_H150.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_H155.txt");
open(MYINPUTFILE,"dirList_H155.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_H160.txt");
open(MYINPUTFILE,"dirList_H160.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);

open(MYOUTFILE,">fileList_WJets.txt");
open(MYINPUTFILE,"dirList_WJets.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);

open(MYOUTFILE,">fileList_Wbb.txt");
open(MYINPUTFILE,"dirList_Wbb.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);
open(MYOUTFILE,">fileList_Zbb.txt");
open(MYINPUTFILE,"dirList_Zbb.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);

open(MYOUTFILE,">fileList_QCD.txt");
open(MYINPUTFILE,"dirList_QCD.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);

open(MYOUTFILE,">fileList_ZZ.txt");
open(MYINPUTFILE,"dirList_ZZ.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);


open(MYOUTFILE,">fileList_WZ.txt");
open(MYINPUTFILE,"dirList_WZ.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);

open(MYOUTFILE,">fileList_WW.txt");
open(MYINPUTFILE,"dirList_WW.txt");

my(@lines) = <MYINPUTFILE>;
my($line);
foreach $line (@lines)
{
chomp($line);
my(@files) =<$line/*/*/*\n>;
print MYOUTFILE join "\n", (@files) ;
print MYOUTFILE "\n";
} 
close(MYINPUTFILE);
close(MYOUTFILE);

