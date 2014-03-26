--- content/shell/app/shell_main_delegate.cc.orig	2014-03-26 08:14:01.272585938 -0600
+++ content/shell/app/shell_main_delegate.cc	2014-03-26 08:15:51.258226850 -0600
@@ -15,7 +15,9 @@
 #include "content/public/common/content_switches.h"
 #include "content/public/common/url_constants.h"
 #include "content/public/test/layouttest_support.h"
+#if !defined(OS_FREEBSD)
 #include "content/shell/app/shell_breakpad_client.h"
+#endif
 #include "content/shell/app/webkit_test_platform_support.h"
 #include "content/shell/browser/shell_browser_main.h"
 #include "content/shell/browser/shell_content_browser_client.h"
@@ -58,14 +60,16 @@
 #include "components/breakpad/app/breakpad_win.h"
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_FREEBSD)
 #include "components/breakpad/app/breakpad_linux.h"
 #endif
 
 namespace {
 
+#if !defined(OS_FREEBSD)
 base::LazyInstance<content::ShellBreakpadClient>::Leaky
     g_shell_breakpad_client = LAZY_INSTANCE_INITIALIZER;
+#endif
 
 #if defined(OS_WIN)
 // If "Content Shell" doesn't show up in your list of trace providers in
@@ -195,12 +199,14 @@
     std::string process_type =
         CommandLine::ForCurrentProcess()->GetSwitchValueASCII(
             switches::kProcessType);
+#if !defined(OS_FREEBSD)
     breakpad::SetBreakpadClient(g_shell_breakpad_client.Pointer());
+#endif
 #if defined(OS_MACOSX)
     base::mac::DisableOSCrashDumps();
     breakpad::InitCrashReporter(process_type);
     breakpad::InitCrashProcessInfo(process_type);
-#elif defined(OS_POSIX) && !defined(OS_MACOSX)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_FREEBSD)
     if (process_type != switches::kZygoteProcess) {
 #if defined(OS_ANDROID)
       if (process_type.empty())
@@ -239,7 +245,7 @@
   return ShellBrowserMain(main_function_params, browser_runner_);
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_FREEBSD)
 void ShellMainDelegate::ZygoteForked() {
   if (CommandLine::ForCurrentProcess()->HasSwitch(
           switches::kEnableCrashReporter)) {
