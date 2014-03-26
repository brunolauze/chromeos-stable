--- ui/gl/gl.gyp.orig	2014-03-14 21:21:16.000000000 -0600
+++ ui/gl/gl.gyp	2014-03-26 07:21:18.808567885 -0600
@@ -27,12 +27,14 @@
         'GL_IMPLEMENTATION',
       ],
       'include_dirs': [
+	'/usr/local/include',
         '<(DEPTH)/third_party/swiftshader/include',
         '<(DEPTH)/third_party/mesa/src/include',
         '<(gl_binding_output_dir)',
       ],
       'direct_dependent_settings': {
         'include_dirs': [
+	  '/usr/local/include',
           '<(gl_binding_output_dir)',
         ],
       },
@@ -177,7 +179,7 @@
         },
       ],
       'conditions': [
-        ['OS in ("win", "android", "linux")', {
+        ['OS in ("win", "android", "linux", "freebsd", "openbsd")', {
           'sources': [
             'egl_util.cc',
             'egl_util.h',
@@ -313,11 +315,13 @@
         'gl',
       ],
       'include_dirs': [
+	'/usr/local/include',
         '<(gl_binding_output_dir)',
         '../..',
       ],
       'direct_dependent_settings': {
         'include_dirs': [
+	  '/usr/local/include',
           '<(gl_binding_output_dir)',
         ],
       },
