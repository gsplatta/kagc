#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([KAGC], [0.001], [gsplatta@acm.org])
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_CACHE_SAVE

# Checks for libraries.
AC_ARG_WITH([gtk3], AS_HELP_STRING([--with-gtk3], [Builds kagc against GTK+ 3]), [with_gtk3=$withval], [with_gtk3=no])

if test "x$with_gtk" = "xyes"; then
	gtk_requirement="gtk+-3.0 >= 3.10.8 gtksourceview-3.0 >= 3.10.2"
	gtk_version=3
else
	gtk_requirement="gtk+-2.0 >= 2.12.0 gtksourceview-2.0 >= 2.4"
	gtk_version=2
fi

required_libs="$gtk_requirement"

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
