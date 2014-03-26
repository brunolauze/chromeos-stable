--- base/process/process_metrics.cc.orig	2014-03-26 07:07:03.146513979 -0600
+++ base/process/process_metrics.cc	2014-03-26 07:07:35.138556962 -0600
@@ -20,7 +20,7 @@
   GetSystemMemoryInfo(&system_metrics.memory_info_);
   GetSystemDiskInfo(&system_metrics.disk_info_);
 #endif
-#if defined(OS_CHROMEOS)
+#if defined(OS_CHROMEOS) && !defined(OS_FREEBSD)
   GetSwapInfo(&system_metrics.swap_info_);
 #endif
 
@@ -35,7 +35,7 @@
   res->Set("meminfo", memory_info_.ToValue().release());
   res->Set("diskinfo", disk_info_.ToValue().release());
 #endif
-#if defined(OS_CHROMEOS)
+#if defined(OS_CHROMEOS) && !defined(OS_FREEBSD)
   res->Set("swapinfo", swap_info_.ToValue().release());
 #endif
 
