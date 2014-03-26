--- ./chrome/browser/ui/webui/options/browser_options_handler.h.orig	2014-03-04 03:17:09.000000000 +0100
+++ ./chrome/browser/ui/webui/options/browser_options_handler.h	2014-03-07 14:10:32.000000000 +0100
@@ -160,7 +160,8 @@
 
   void ObserveThemeChanged();
   void ThemesReset(const base::ListValue* args);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS) && !defined(OS_MACOSX) && \
+    !defined(OS_ANDROID)
   void ThemesSetNative(const base::ListValue* args);
 #endif
 
