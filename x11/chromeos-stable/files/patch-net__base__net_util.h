--- ./net/base/net_util.h.orig	2014-03-04 03:16:06.000000000 +0100
+++ ./net/base/net_util.h	2014-03-07 14:10:34.000000000 +0100
@@ -13,6 +13,9 @@
 #elif defined(OS_POSIX)
 #include <sys/types.h>
 #include <sys/socket.h>
+#if defined(OS_BSD)
+#include <netinet/in.h>
+#endif
 #endif
 
 #include <string>
