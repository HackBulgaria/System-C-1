# Makefiles

http://wiki.wlug.org.nz/MakefileHowto


http://mrbook.org/tutorials/make/



Makefile.am is a programmer-defined file and is used by automake to generate the Makefile.in file. The ./configure script typically seen in source tarballs will use the Makefile.in to generate a Makefile.

The ./configure script itself is generated from a programmer-defined file named either configure.ac or configure.in , I prefer .ac (for AutoConf) since it differentiates it from the generated Makefile.in files and that way I can have rules such as make dist-clean which rm -f *.in . Since it is a generated file it is not typically stored in a revision system such as SVN or CVS, rather the .ac file would be.

Read more on GNU Autotools. Read about make and Makefile first, then learn about automake, autoconf, libtool, etc.

