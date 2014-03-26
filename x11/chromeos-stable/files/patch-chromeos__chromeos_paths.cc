--- chromeos/chromeos_paths.cc.orig	2014-03-26 07:41:29.819939093 -0600
+++ chromeos/chromeos_paths.cc	2014-03-26 07:43:43.318382750 -0600
@@ -13,9 +13,21 @@
 
 const base::FilePath::CharType kDefaultAppOrderFileName[] =
 #if defined(GOOGLE_CHROME_BUILD)
-    FILE_PATH_LITERAL("/usr/share/google-chrome/default_app_order.json");
+    FILE_PATH_LITERAL(
+#if defined(OS_FREEBSD)
+        "/usr/local/share/google-chrome/default_app_order.json"
 #else
-    FILE_PATH_LITERAL("/usr/share/chromium/default_app_order.json");
+	"/usr/share/google-chrome/default_app_order.json"
+#endif
+	);
+#else
+    FILE_PATH_LITERAL(
+#if defined(OS_FREEBSD)
+        "/usr/local/share/chromium/default_app_order.json"
+#else
+	"/usr/share/chromium/default_app_order.json"
+#endif
+	);
 #endif  // defined(GOOGLE_CHROME_BUILD)
 
 const base::FilePath::CharType kDefaultUserPolicyKeysDir[] =
@@ -28,7 +40,13 @@
     FILE_PATH_LITERAL("/var/run/lockbox/install_attributes.pb");
 
 const base::FilePath::CharType kUptimeFileName[] =
-    FILE_PATH_LITERAL("/proc/uptime");
+    FILE_PATH_LITERAL(
+#if defined(OS_FREEBSD)
+	"/usr/bin/uptime"
+#else
+	"/proc/uptime"
+#endif
+	);
 
 const base::FilePath::CharType kUpdateRebootNeededUptimeFile[] =
     FILE_PATH_LITERAL("/var/run/chrome/update_reboot_needed_uptime");
