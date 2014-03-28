--- chrome/chrome_resources.gyp.orig	2014-03-27 12:10:36.785791265 -0600
+++ chrome/chrome_resources.gyp	2014-03-27 12:11:03.970793728 -0600
@@ -249,7 +249,7 @@
             'platform_locale_settings_grd':
                 'app/resources/locale_settings_win.grd',
           },],
-          ['OS=="linux"', {
+          ['OS=="linux" or os_bsd==1', {
             'conditions': [
               ['chromeos==1', {
                 'conditions': [
@@ -267,7 +267,7 @@
               }],
             ],
           },],
-          ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "linux"', {
+          ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "linux" and os_bsd != 1', {
             'platform_locale_settings_grd':
                 'app/resources/locale_settings_linux.grd',
           },],
