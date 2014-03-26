--- chrome/common/extensions/extension_constants.cc.orig	2014-03-23 11:52:35.712636311 -0600
+++ chrome/common/extensions/extension_constants.cc	2014-03-23 11:54:06.669629715 -0600
@@ -133,11 +133,23 @@
 const char kChromeVoxExtensionId[] =
     "mndnfokpggljbaajbnioimlmbfngpief";
 const char kConnectivityDiagnosticsPath[] =
+#if defined(OS_FREEBSD)
+    "/usr/local/share/chromeos-assets/connectivity_diagnostics";
+#else
     "/usr/share/chromeos-assets/connectivity_diagnostics";
+#endif
 const char kConnectivityDiagnosticsLauncherPath[] =
+#if defined(OS_FREEBSD)
+    "/usr/local/share/chromeos-assets/connectivity_diagnostics_launcher";
+#else
     "/usr/share/chromeos-assets/connectivity_diagnostics_launcher";
+#endif
 const char kSpeechSynthesisExtensionPath[] =
+#if defined(OS_FREEBSD)
+    "/usr/local/share/chromeos-assets/speech_synthesis/patts";
+#else
     "/usr/share/chromeos-assets/speech_synthesis/patts";
+#endif
 const char kSpeechSynthesisExtensionId[] =
     "gjjabgpgjpampikjhjpfhneeoapjbjaf";
 const char kWallpaperManagerId[] = "obklkkbkpaoaejdabbfldmcfplpdgolj";
