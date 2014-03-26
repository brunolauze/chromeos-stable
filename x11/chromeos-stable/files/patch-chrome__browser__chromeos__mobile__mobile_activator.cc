--- chrome/browser/chromeos/mobile/mobile_activator.cc.orig	2014-03-26 07:37:50.402361300 -0600
+++ chrome/browser/chromeos/mobile/mobile_activator.cc	2014-03-26 07:38:32.063689276 -0600
@@ -45,7 +45,11 @@
 
 // Cellular configuration file path.
 const char kCellularConfigPath[] =
+#if defined(OS_FREEBSD)
+    "/usr/local/share/chromeos-assets/mobile/mobile_config.json";
+#else
     "/usr/share/chromeos-assets/mobile/mobile_config.json";
+#endif
 
 // Cellular config file field names.
 const char kVersionField[] = "version";
