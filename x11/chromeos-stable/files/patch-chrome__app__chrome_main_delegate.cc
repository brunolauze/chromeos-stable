--- ./chrome/app/chrome_main_delegate.cc.orig	2014-03-04 03:16:34.000000000 +0100
+++ ./chrome/app/chrome_main_delegate.cc	2014-03-07 14:10:32.000000000 +0100
@@ -97,7 +97,7 @@
 #include "ui/base/x/x11_util.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "components/breakpad/app/breakpad_linux.h"
 #endif
 
@@ -115,7 +115,7 @@
     g_chrome_content_plugin_client = LAZY_INSTANCE_INITIALIZER;
 #endif
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
 base::LazyInstance<chrome::ChromeBreakpadClient>::Leaky
     g_chrome_breakpad_client = LAZY_INSTANCE_INITIALIZER;
 #endif
@@ -235,7 +235,7 @@
       // Mac needs them for the plugin process name.
       process_type == switches::kPluginProcess ||
 #endif
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == switches::kZygoteProcess ||
 #endif
@@ -392,7 +392,7 @@
       std::string format_str =
           command_line.GetSwitchValueASCII(switches::kDiagnosticsFormat);
       if (format_str == "machine") {
-        format = diagnostics::DiagnosticsWriter::MACHINE;
+        format = diagnostics::DiagnosticsWriter::THEMACHINE;
       } else if (format_str == "log") {
         format = diagnostics::DiagnosticsWriter::LOG;
       } else {
@@ -433,7 +433,7 @@
       std::string format_str =
           command_line.GetSwitchValueASCII(switches::kDiagnosticsFormat);
       if (format_str == "machine") {
-        format = diagnostics::DiagnosticsWriter::MACHINE;
+        format = diagnostics::DiagnosticsWriter::THEMACHINE;
       } else if (format_str == "human") {
         format = diagnostics::DiagnosticsWriter::HUMAN;
       } else {
@@ -564,7 +564,7 @@
   std::string process_type =
       command_line.GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   breakpad::SetBreakpadClient(g_chrome_breakpad_client.Pointer());
 #endif
 
@@ -703,7 +703,7 @@
 #endif
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_FREEBSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != switches::kZygoteProcess) {
 #if defined(OS_ANDROID)
@@ -715,7 +715,7 @@
     breakpad::InitCrashReporter(process_type);
 #endif  // defined(OS_ANDROID)
   }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_FREEBSD)
 
   // After all the platform Breakpads have been initialized, store the command
   // line for crash reporting.
@@ -800,7 +800,7 @@
   return process_type == switches::kNaClLoaderProcess ||
       process_type == switches::kRelauncherProcess;
 }
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 content::ZygoteForkDelegate* ChromeMainDelegate::ZygoteStarting() {
 #if defined(DISABLE_NACL)
   return NULL;
