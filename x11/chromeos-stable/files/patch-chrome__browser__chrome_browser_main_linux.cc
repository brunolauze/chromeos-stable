--- chrome/browser/chrome_browser_main_linux.cc.orig	2014-03-27 13:42:20.253412085 -0600
+++ chrome/browser/chrome_browser_main_linux.cc	2014-03-27 13:43:09.666411465 -0600
@@ -14,8 +14,9 @@
 #include "chrome/common/chrome_switches.h"
 #include "chrome/common/env_vars.h"
 #include "chrome/common/pref_names.h"
+#if defined(OS_LINUX)
 #include "components/breakpad/app/breakpad_linux.h"
-
+#endif
 #if !defined(OS_CHROMEOS)
 #include "chrome/browser/storage_monitor/storage_monitor_linux.h"
 #include "chrome/browser/sxs_linux.h"
@@ -61,5 +62,10 @@
   ChromeBrowserMainPartsPosix::PostProfileInit();
 
   g_browser_process->metrics_service()->RecordBreakpadRegistration(
-      breakpad::IsCrashReporterEnabled());
+#if defined(OS_LINUX)
+      breakpad::IsCrashReporterEnabled()
+#else
+      false
+#endif
+  );
 }
