--- device/media_transfer_protocol/media_transfer_protocol_manager.h.orig	2014-03-27 12:22:07.480743592 -0600
+++ device/media_transfer_protocol/media_transfer_protocol_manager.h	2014-03-27 12:22:30.540746724 -0600
@@ -12,8 +12,8 @@
 #include "base/memory/ref_counted.h"
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
-#error "Only used on Linux and ChromeOS"
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
+#error "Only used on FreeBSD, Linux and ChromeOS"
 #endif
 
 class MtpFileEntry;
