--- build/linux/system.gyp.orig	2014-03-26 05:35:49.811382768 -0600
+++ build/linux/system.gyp	2014-03-26 05:36:23.428878009 -0600
@@ -29,7 +29,7 @@
         'use_system_ssl%': 1,
       },
     }],
-    [ 'chromeos==0', {
+    [ 'chromeos==0 or os_bsd==1', {
       # Hide GTK and related dependencies for Chrome OS, so they won't get
       # added back to Chrome OS. Don't try to use GTK on Chrome OS.
       'targets': [
