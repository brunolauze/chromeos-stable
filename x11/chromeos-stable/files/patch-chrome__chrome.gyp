--- chrome/chrome.gyp.orig	2014-03-27 06:22:42.402229749 -0600
+++ chrome/chrome.gyp	2014-03-27 12:11:25.556786682 -0600
@@ -53,7 +53,7 @@
           'service',
         ],
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or os_bsd==1', {
         'conditions': [
           ['chromeos==1', {
             'conditions': [
@@ -71,7 +71,7 @@
           }],
         ],
       },],
-      ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "linux"', {
+      ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "linux" or os_bsd != 1', {
         'platform_locale_settings_grd':
             'app/resources/locale_settings_linux.grd',
       },],
