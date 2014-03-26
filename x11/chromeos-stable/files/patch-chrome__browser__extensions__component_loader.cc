--- chrome/browser/extensions/component_loader.cc.orig	2014-03-14 21:21:52.000000000 -0600
+++ chrome/browser/extensions/component_loader.cc	2014-03-26 08:00:39.869502166 -0600
@@ -391,12 +391,23 @@
   // to AddDefaultComponentExtensionsWithBackgroundPages.
 #if defined(OS_CHROMEOS)
   Add(IDR_MOBILE_MANIFEST,
-      base::FilePath(FILE_PATH_LITERAL("/usr/share/chromeos-assets/mobile")));
+      base::FilePath(FILE_PATH_LITERAL(
+#if defined(OS_FREEBSD)
+	"/usr/local/share/chromeos-assets/mobile"
+#else
+	"/usr/share/chromeos-assets/mobile"
+#endif
+      )));
 
 #if defined(GOOGLE_CHROME_BUILD)
   if (browser_defaults::enable_help_app) {
     Add(IDR_HELP_MANIFEST, base::FilePath(FILE_PATH_LITERAL(
-                               "/usr/share/chromeos-assets/helpapp")));
+#if defined(OS_FREEBSD)
+			       "/usr/local/share/chromeos-assets/helpapp"
+#else
+                               "/usr/share/chromeos-assets/helpapp"
+#endif
+	)));
   }
 #endif
 
@@ -407,7 +418,12 @@
       AddBookmarksExtensions();
 
     Add(IDR_CROSH_BUILTIN_MANIFEST, base::FilePath(FILE_PATH_LITERAL(
-        "/usr/share/chromeos-assets/crosh_builtin")));
+#if defined(OS_FREEBSD)
+	"/usr/local/share/chromeos-assets/crosh_builtin"
+#else
+        "/usr/share/chromeos-assets/crosh_builtin"
+#endif
+	)));
   }
 #else  // !defined(OS_CHROMEOS)
   DCHECK(!skip_session_components);
@@ -455,7 +471,12 @@
   if (!command_line->HasSwitch(chromeos::switches::kDisableGeniusApp)) {
     AddWithName(IDR_GENIUS_APP_MANIFEST,
                 base::FilePath(FILE_PATH_LITERAL(
-                    "/usr/share/chromeos-assets/genius_app")),
+#if defined(OS_FREEBSD)
+		    "/usr/local/share/chromeos-assets/genius_app"
+#else
+                    "/usr/share/chromeos-assets/genius_app"
+#endif
+		)),
                 l10n_util::GetStringUTF8(IDS_GENIUS_APP_NAME));
   }
 #endif
@@ -498,13 +519,24 @@
         manifest_id = IDR_QUICKOFFICE_VIEWING_MANIFEST;
       }
       std::string id = Add(manifest_id, base::FilePath(
-          FILE_PATH_LITERAL("/usr/share/chromeos-assets/quick_office")));
+          FILE_PATH_LITERAL(
+#if defined(OS_FREEBSD)
+                "/usr/local/share/chromeos-assets/quick_office"
+#else
+		"/usr/share/chromeos-assets/quick_office"
+#endif
+		)));
       EnableFileSystemInGuestMode(id);
     }
 #endif  // defined(GOOGLE_CHROME_BUILD)
 
     base::FilePath echo_extension_path(FILE_PATH_LITERAL(
-        "/usr/share/chromeos-assets/echo"));
+#if defined(OS_FREEBSD)
+        "/usr/local/share/chromeos-assets/echo"
+#else
+        "/usr/share/chromeos-assets/echo"
+#endif
+	));
     if (command_line->HasSwitch(chromeos::switches::kEchoExtensionPath)) {
       echo_extension_path = command_line->GetSwitchValuePath(
           chromeos::switches::kEchoExtensionPath);
