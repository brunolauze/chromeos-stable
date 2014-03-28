--- sync/sync_tests.gypi.orig	2014-03-26 16:00:15.645796382 -0600
+++ sync/sync_tests.gypi	2014-03-26 16:00:48.688793804 -0600
@@ -210,7 +210,7 @@
         'test_support_sync_core',
       ],
       'conditions': [
-        ['OS=="linux" and chromeos==1', {
+        ['(OS=="linux" or OS=="freebsd") and chromeos==1', {
           # Required by get_session_name_unittest.cc on Chrome OS.
           'dependencies': [
             '../chromeos/chromeos.gyp:chromeos',
