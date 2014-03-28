--- chromeos/chromeos.gyp.orig	2014-03-26 14:48:13.327093813 -0600
+++ chromeos/chromeos.gyp	2014-03-26 14:49:00.948092080 -0600
@@ -28,6 +28,9 @@
         '../url/url.gyp:url_lib',
         'ime/input_method.gyp:gencode',
         'power_manager_proto',
+	'../third_party/icu/icu.gyp:icui18n',
+        '../third_party/icu/icu.gyp:icuuc',
+        '../third_party/icu/icu.gyp:icudata',
       ],
       'defines': [
         'CHROMEOS_IMPLEMENTATION',
