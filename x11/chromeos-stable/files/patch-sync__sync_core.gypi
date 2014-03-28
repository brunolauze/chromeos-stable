--- sync/sync_core.gypi.orig	2014-03-26 15:40:54.453876320 -0600
+++ sync/sync_core.gypi	2014-03-26 15:41:17.586896574 -0600
@@ -19,7 +19,7 @@
     '../url/url.gyp:url_lib',
   ],
   'conditions': [
-    ['OS=="linux" and chromeos==1', {
+    ['(OS=="linux" or OS=="freebsd") and chromeos==1', {
       # Required by get_session_name.cc on Chrome OS.
       'dependencies': [
         '../chromeos/chromeos.gyp:chromeos',
