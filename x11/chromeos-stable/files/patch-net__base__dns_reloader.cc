--- ./net/base/dns_reloader.cc.orig	2014-03-04 03:16:05.000000000 +0100
+++ ./net/base/dns_reloader.cc	2014-03-07 14:10:34.000000000 +0100
@@ -7,6 +7,9 @@
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && \
     !defined(OS_ANDROID)
 
+#if defined(OS_FREEBSD)
+#include <netinet/in.h>
+#endif
 #include <resolv.h>
 
 #include "base/basictypes.h"
