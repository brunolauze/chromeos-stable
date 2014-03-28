--- chrome/browser/memory_details.cc.orig	2014-03-14 21:22:08.000000000 -0600
+++ chrome/browser/memory_details.cc	2014-03-27 13:18:39.298509433 -0600
@@ -31,7 +31,7 @@
 #include "grit/generated_resources.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include "content/public/browser/zygote_host_linux.h"
 #endif
 
@@ -203,7 +203,7 @@
 void MemoryDetails::CollectChildInfoOnUIThread() {
   DCHECK(BrowserThread::CurrentlyOn(BrowserThread::UI));
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   const pid_t zygote_pid = content::ZygoteHost::GetInstance()->GetPid();
   const pid_t sandbox_helper_pid =
       content::ZygoteHost::GetInstance()->GetSandboxHelperPid();
@@ -344,7 +344,7 @@
       }
     }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     if (process.pid == zygote_pid) {
       process.process_type = content::PROCESS_TYPE_ZYGOTE;
     } else if (process.pid == sandbox_helper_pid) {
@@ -462,7 +462,7 @@
   }
   UMA_HISTOGRAM_MEMORY_KB("Memory.BackingStore",
                           RenderWidgetHost::BackingStoreMemorySize() / 1024);
-#if defined(OS_CHROMEOS)
+#if defined(OS_CHROMEOS) && !defined(OS_FREEBSD)
   // Chrome OS exposes system-wide graphics driver memory which has historically
   // been a source of leak/bloat.
   base::SystemMemoryInfoKB meminfo;
