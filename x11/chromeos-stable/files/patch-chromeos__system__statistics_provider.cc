--- chromeos/system/statistics_provider.cc.orig	2014-03-26 07:44:10.856405599 -0600
+++ chromeos/system/statistics_provider.cc	2014-03-26 07:45:20.614671524 -0600
@@ -29,7 +29,13 @@
 
 // Path to the tool used to get system info, and delimiters for the output
 // format of the tool.
-const char* kCrosSystemTool[] = { "/usr/bin/crossystem" };
+const char* kCrosSystemTool[] = { 
+#if defined(OS_FREEBSD)
+	"/usr/local/bin/crossystem"
+#else
+	"/usr/bin/crossystem" 
+#endif
+	};
 const char kCrosSystemEq[] = "=";
 const char kCrosSystemDelim[] = "\n";
 const char kCrosSystemCommentDelim[] = "#";
@@ -61,7 +67,13 @@
 
 // The location of OEM manifest file used to trigger OOBE flow for kiosk mode.
 const CommandLine::CharType kOemManifestFilePath[] =
-    FILE_PATH_LITERAL("/usr/share/oem/oobe/manifest.json");
+    FILE_PATH_LITERAL(
+#if defined(OS_FREEBSD)
+        "/usr/local/share/chromeos-assets/oem/oobe/manifest.json"
+#else
+	"/usr/share/oem/oobe/manifest.json"
+#endif
+	);
 
 }  // namespace
 
