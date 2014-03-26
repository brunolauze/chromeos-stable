--- ./gpu/config/gpu_control_list.cc.orig	2014-03-04 03:17:33.000000000 +0100
+++ ./gpu/config/gpu_control_list.cc	2014-03-07 14:10:34.000000000 +0100
@@ -1344,10 +1344,10 @@
   return kOsWin;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
-  return kOsLinux;
 #elif defined(OS_MACOSX)
   return kOsMacosx;
+#elif defined(OS_POSIX)
+  return kOsLinux;
 #else
   return kOsUnknown;
 #endif
