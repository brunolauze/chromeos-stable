--- chrome/browser/chromeos/camera_detector.cc.orig	2014-03-26 20:37:08.104668930 -0600
+++ chrome/browser/chromeos/camera_detector.cc	2014-03-26 20:38:09.485645926 -0600
@@ -12,7 +12,9 @@
 #include "base/strings/string_util.h"
 #include "base/task_runner_util.h"
 #include "base/threading/sequenced_worker_pool.h"
+#if defined(OS_LINUX)
 #include "chrome/browser/storage_monitor/udev_util_linux.h"
+#endif
 #include "content/public/browser/browser_thread.h"
 
 namespace chromeos {
@@ -65,6 +67,7 @@
 
 // static
 bool CameraDetector::CheckPresence() {
+#if defined(OS_LINUX)
   // We do a quick check using udev database because opening each /dev/videoX
   // device may trigger costly device initialization.
   base::FileEnumerator file_enum(
@@ -82,6 +85,7 @@
       }
     }
   }
+#endif
   return false;
 }
 
