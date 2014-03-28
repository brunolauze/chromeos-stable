--- ui/ui.gyp.orig	2014-03-26 15:06:42.225017847 -0600
+++ ui/ui.gyp	2014-03-26 15:07:38.874013099 -0600
@@ -385,7 +385,7 @@
             'base/x/selection_utils.h',
           ]
         }],
-        ['use_aura==0 or OS!="linux"', {
+        ['use_aura==0 or (OS!="linux" and OS!="freebsd")', {
           'sources!': [
             'base/resource/resource_bundle_auralinux.cc',
           ],
@@ -436,7 +436,7 @@
             'base/clipboard/clipboard_aurax11.cc',
           ],
         }],
-        ['chromeos==1 or (use_aura==1 and OS=="linux" and use_x11==0)', {
+        ['chromeos==1 or (use_aura==1 and (OS=="linux" or OS=="freebsd") and use_x11==0)', {
           'sources!': [
             'base/dragdrop/os_exchange_data_provider_aurax11.cc',
             'base/touch/touch_device.cc',
