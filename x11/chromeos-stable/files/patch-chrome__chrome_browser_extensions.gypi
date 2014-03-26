--- ./chrome/chrome_browser_extensions.gypi.orig	2014-03-04 03:17:18.000000000 +0100
+++ ./chrome/chrome_browser_extensions.gypi	2014-03-07 14:10:32.000000000 +0100
@@ -908,6 +908,11 @@
         'browser/extensions/window_controller_list_observer.h',
       ],
       'conditions': [
+        ['os_bsd==1', {
+         'sources/': [
+            ['exclude', '^browser/extensions/api/image_writer_private/removable_storage_provider_linux.cc'],
+         ],
+        }],
         ['chromeos==1', {
           'dependencies': [
             '../build/linux/system.gyp:dbus',
