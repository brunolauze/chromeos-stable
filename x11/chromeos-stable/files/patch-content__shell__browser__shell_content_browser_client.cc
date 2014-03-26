--- content/shell/browser/shell_content_browser_client.cc.orig	2014-03-26 08:10:50.965622553 -0600
+++ content/shell/browser/shell_content_browser_client.cc	2014-03-26 08:12:58.760206850 -0600
@@ -41,8 +41,10 @@
 #if defined(OS_POSIX) && !defined(OS_MACOSX)
 #include "base/debug/leak_annotations.h"
 #include "base/platform_file.h"
+#if defined(OS_LINUX)
 #include "components/breakpad/app/breakpad_linux.h"
 #include "components/breakpad/browser/crash_handler_host_linux.h"
+#endif
 #include "content/public/common/content_descriptors.h"
 #endif
 
@@ -53,7 +55,7 @@
 ShellContentBrowserClient* g_browser_client;
 bool g_swap_processes_for_redirect = false;
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_FREEBSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path =
@@ -103,10 +105,9 @@
       crash_handler = CreateCrashHandlerHost(process_type);
     return crash_handler->GetDeathSignalSocket();
   }
-
   return -1;
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_FREEBSD)
 
 }  // namespace
 
