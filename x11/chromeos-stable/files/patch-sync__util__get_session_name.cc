--- ./sync/util/get_session_name.cc.orig	2014-03-04 03:17:50.000000000 +0100
+++ ./sync/util/get_session_name.cc	2014-03-07 14:10:34.000000000 +0100
@@ -11,7 +11,7 @@
 #include "base/sys_info.h"
 #include "base/task_runner.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "sync/util/get_session_name_linux.h"
 #elif defined(OS_IOS)
 #include "sync/util/get_session_name_ios.h"
@@ -36,7 +36,7 @@
   // like "stumpy-signed-mp-v2keys" etc. The information can be checked on
   // "CHROMEOS_RELEASE_BOARD" line in chrome://system.
   session_name = board.substr(0, 6) == "stumpy" ? "Chromebox" : "Chromebook";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   session_name = internal::GetHostname();
 #elif defined(OS_IOS)
   session_name = internal::GetComputerName();
