--- ./base/process/process_metrics.h.orig	2014-03-04 03:16:26.000000000 +0100
+++ ./base/process/process_metrics.h	2014-03-07 14:10:31.000000000 +0100
@@ -17,6 +17,13 @@
 #include "base/time/time.h"
 #include "base/values.h"
 
+#if defined(OS_BSD)
+#include <kvm.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
+
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
 #endif
