--- ./chrome/browser/web_applications/web_app.cc.orig	2014-03-04 03:17:15.000000000 +0100
+++ ./chrome/browser/web_applications/web_app.cc	2014-03-07 14:10:32.000000000 +0100
@@ -226,7 +226,7 @@
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 std::string GetWMClassFromAppName(std::string app_name) {
   file_util::ReplaceIllegalCharactersInPath(&app_name, '_');
   base::TrimString(app_name, "_", &app_name);
