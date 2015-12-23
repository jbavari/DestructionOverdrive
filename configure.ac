#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# Prelude.
AC_PREREQ([2.59])
AC_INIT([doverdrive], [0.0.1], [charles.shuller@gmail.com])

# place to put some extra build scripts installed
AC_CONFIG_AUX_DIR([build-aux])

# really severe build strictness
AM_INIT_AUTOMAKE([-Wall -Werror gnits 1.9.6])


# Checks for programs.
AC_PROG_AWK
#AC_PROG_CC
AC_PROG_CXX
#AM_PROG_CC_C_O
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_LIBTOOL
if test -n "$GCC"; then
  CFLAGS="$CFLAGS -Wall -Wstrict-prototypes -Wmissing-prototypes -Wwrite-strings"
fi


AM_PATH_CPPUNIT(1.12)

# Checks for libraries.
PKG_CHECK_MODULES([LIBXML2], [libxml-2.0 >= 2.6.0])


# Output files
AC_CONFIG_HEADERS([config.h])


AC_OUTPUT(	[./Makefile] [./lib/Makefile] [./test/Makefile] [./test/OutOfDomainExceptionTest/Makefile] 
		[./test/LDExceptionTest/Makefile] [./test/PowerTest/Makefile] [./test/XmlSerializationTest/Makefile]
		[./test/PowerSuppliableTest/Makefile] [./test/CapacitorTest/Makefile] [./test/DamageTypeTest/Makefile]
		[./test/DamageTest/Makefile] [./test/ModuleTest/Makefile]  [./test/NetworkTest/Makefile]
		[./test/CombatUnitIdTest/Makefile] [./test/MessageTest/Makefile] [./test/DumbMovementTest/Makefile]
		[./test/ECMTest/Makefile] [./test/ShieldTest/Makefile] [./test/XmlSerializationExceptionTest/Makefile]
	 )
