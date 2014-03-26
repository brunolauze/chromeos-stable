--- ./third_party/libjingle/source/talk/base/linux.h.orig	2014-03-04 03:18:12.000000000 +0100
+++ ./third_party/libjingle/source/talk/base/linux.h	2014-03-07 14:10:35.000000000 +0100
@@ -28,7 +28,7 @@
 #ifndef TALK_BASE_LINUX_H_
 #define TALK_BASE_LINUX_H_
 
-#if defined(LINUX) || defined(ANDROID)
+#if defined(LINUX) || defined(ANDROID) || defined(BSD)
 #include <string>
 #include <map>
 #include <vector>
@@ -131,5 +131,5 @@
 
 }  // namespace talk_base
 
-#endif  // defined(LINUX) || defined(ANDROID)
+#endif  // defined(LINUX) || defined(ANDROID) || defined(BSD)
 #endif  // TALK_BASE_LINUX_H_
