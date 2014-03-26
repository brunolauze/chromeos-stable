--- build/common.gypi.orig	2014-03-14 21:20:43.000000000 -0600
+++ build/common.gypi	2014-03-26 06:37:04.273821151 -0600
@@ -573,7 +573,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or OS=="freebsd") and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -1008,6 +1008,10 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    'os_ver%': 0,
+    'prefix_dir%': '/usr',
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -1203,10 +1207,10 @@
     'msbuild_toolset%': '',
 
     # Native Client is enabled by default.
-    'disable_nacl%': 0,
+    'disable_nacl%': 1,
 
     # Portable Native Client is enabled by default.
-    'disable_pnacl%': 0,
+    'disable_pnacl%': 1,
 
     # Whether to build full debug version for Debug configuration on Android.
     # Compared to full debug version, the default Debug configuration on Android
@@ -1283,7 +1287,7 @@
       }],
       ['os_posix==1 and OS!="mac" and OS!="ios"', {
         # Figure out the python architecture to decide if we build pyauto.
-        'python_arch%': '<!(<(DEPTH)/build/linux/python_arch.sh <(sysroot)/usr/<(system_libdir)/libpython<(python_ver).so.1.0)',
+        'python_arch%': '<!(<(DEPTH)/build/linux/python_arch.sh <(sysroot)<(prefix_dir)/lib/libpython<(python_ver).so.1)',
         'conditions': [
           ['target_arch=="mipsel"', {
             'werror%': '',
@@ -1891,7 +1895,7 @@
       }],
 
       # Enable brlapi by default for chromeos.
-      [ 'chromeos==1', {
+      [ 'chromeos==1 and os_bsd!=1', {
         'use_brlapi%': 1,
       }],
 
@@ -3610,6 +3614,13 @@
         'ldflags': [
           '-Wl,--no-keep-memory',
         ],
+        'ldflags!': [
+          '-ldl',
+          '-pie',
+        ],
+        'libraries!': [
+          '-ldl',
+        ],
       },
     }],
     # Android-specific options; note that most are set above with Linux.
