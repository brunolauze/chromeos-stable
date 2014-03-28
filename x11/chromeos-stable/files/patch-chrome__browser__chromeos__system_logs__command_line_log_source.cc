--- chrome/browser/chromeos/system_logs/command_line_log_source.cc.orig	2014-03-26 13:09:27.076501226 -0600
+++ chrome/browser/chromeos/system_logs/command_line_log_source.cc	2014-03-26 13:12:21.997489947 -0600
@@ -29,11 +29,23 @@
   command.AppendArg("contents");
   commands.push_back(std::make_pair("alsa controls", command));
 
-  command = CommandLine((base::FilePath("/usr/bin/cras_test_client")));
+  command = CommandLine((base::FilePath(
+#if defined(OS_FREEBSD)
+        "/usr/local/bin/cras_test_client"
+#else
+	"/usr/bin/cras_test_client"
+#endif
+	)));
   command.AppendArg("--dump_server_info");
   commands.push_back(std::make_pair("cras", command));
 
-  command = CommandLine((base::FilePath("/usr/bin/cras_test_client")));
+  command = CommandLine((base::FilePath(
+#if defined(OS_FREEBSD)
+	"/usr/local/bin/cras_test_client"
+#else
+        "/usr/bin/cras_test_client"
+#endif
+	)));
   command.AppendArg("--loopback_file");
   command.AppendArg("/dev/null");
   command.AppendArg("--rate");
@@ -46,17 +58,35 @@
   command = CommandLine((base::FilePath("/usr/bin/printenv")));
   commands.push_back(std::make_pair("env", command));
 
-  command = CommandLine(base::FilePath("/usr/bin/setxkbmap"));
+  command = CommandLine(base::FilePath(
+#if defined(OS_FREEBSD)
+	"/usr/local/bin/setxkbmap"
+#else
+	"/usr/bin/setxkbmap"
+#endif
+	));
   command.AppendArg("-print");
   command.AppendArg("-query");
   commands.push_back(std::make_pair("setxkbmap", command));
 
-  command = CommandLine(base::FilePath("/usr/bin/xinput"));
+  command = CommandLine(base::FilePath(
+#if defined(OS_FREEBSD)
+	"/usr/local/bin/xinput"
+#else
+	"/usr/bin/xinput"
+#endif
+	));
   command.AppendArg("list");
   command.AppendArg("--long");
   commands.push_back(std::make_pair("xinput", command));
 
-  command = CommandLine(base::FilePath("/usr/bin/xrandr"));
+  command = CommandLine(base::FilePath(
+#if defined(OS_FREEBSD)
+	"/usr/local/bin/xrandr"
+#else
+	"/usr/bin/xrandr"
+#endif
+	));
   command.AppendArg("--verbose");
   commands.push_back(std::make_pair("xrandr", command));
 
