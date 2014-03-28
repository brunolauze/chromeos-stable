--- chrome/browser/ui/webui/about_ui.cc.orig	2014-03-14 21:21:55.000000000 -0600
+++ chrome/browser/ui/webui/about_ui.cc	2014-03-27 12:05:01.780815145 -0600
@@ -477,7 +477,7 @@
   output.append(base::StringPrintf("<a href='%s%s'>Discard tab now</a>",
                                    chrome::kChromeUIDiscardsURL,
                                    kRunCommand));
-
+#if !defined(OS_FREEBSD)
   base::SystemMemoryInfoKB meminfo;
   base::GetSystemMemoryInfo(&meminfo);
   output.append("<h3>System memory information in MB</h3>");
@@ -510,7 +510,7 @@
   output.append(AddStringRow(
       "Graphics", base::IntToString(meminfo.gem_size / 1024 / 1024)));
   output.append("</table>");
-
+#endif
   AppendFooter(&output);
   return output;
 }
@@ -766,7 +766,7 @@
   return data;
 }
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   AppendHeader(&data, 0,
@@ -782,6 +782,7 @@
   return data;
 }
 
+#if !defined(OS_BSD)
 void AboutSandboxRow(std::string* data, const std::string& prefix, int name_id,
                      bool good) {
   data->append("<tr><td>");
@@ -848,6 +849,7 @@
   return data;
 }
 #endif
+#endif
 
 // AboutMemoryHandler ----------------------------------------------------------
 
@@ -1013,7 +1015,7 @@
   } else if (source_name_ == chrome::kChromeUIDNSHost) {
     AboutDnsHandler::Start(profile(), callback);
     return;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (source_name_ == chrome::kChromeUILinuxProxyConfigHost) {
     response = AboutLinuxProxyConfig();
 #endif
