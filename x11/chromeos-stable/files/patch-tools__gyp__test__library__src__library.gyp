--- ./tools/gyp/test/library/src/library.gyp.orig	2014-03-04 03:18:35.000000000 +0100
+++ ./tools/gyp/test/library/src/library.gyp	2014-03-07 14:10:36.000000000 +0100
@@ -48,7 +48,7 @@
     },
   ],
   'conditions': [
-    ['OS=="linux"', {
+    ['OS=="linux" or OS=="freebsd"', {
       'target_defaults': {
         # Support 64-bit shared libs (also works fine for 32-bit).
         'cflags': ['-fPIC'],
