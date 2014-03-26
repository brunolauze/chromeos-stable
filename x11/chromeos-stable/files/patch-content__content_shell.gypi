--- content/content_shell.gypi.orig	2014-03-26 08:07:24.774568243 -0600
+++ content/content_shell.gypi	2014-03-26 08:17:48.664447403 -0600
@@ -40,7 +40,6 @@
         'content_resources.gyp:content_resources',
         '../base/base.gyp:base',
         '../base/third_party/dynamic_annotations/dynamic_annotations.gyp:dynamic_annotations',
-        '../components/components.gyp:breakpad_component',
         '../ipc/ipc.gyp:ipc',
         '../media/media.gyp:media',
         '../net/net.gyp:net',
@@ -68,8 +67,6 @@
         'shell/android/shell_manager.h',
         'shell/app/paths_mac.h',
         'shell/app/paths_mac.mm',
-        'shell/app/shell_breakpad_client.cc',
-        'shell/app/shell_breakpad_client.h',
         'shell/app/shell_main_delegate.cc',
         'shell/app/shell_main_delegate.h',
         'shell/app/shell_main_delegate_mac.h',
@@ -211,7 +208,7 @@
             'test_support_content',
           ],
         }],  # OS=="android"
-        ['os_posix == 1 and OS != "mac" and android_webview_build != 1', {
+        ['os_posix == 1 and OS != "mac" and OS != "freebsd" and android_webview_build != 1', {
           'dependencies': [
             '../components/components.gyp:breakpad_host',
           ],
