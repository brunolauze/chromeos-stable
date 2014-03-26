--- base/base.gypi.orig	2014-03-14 21:21:07.000000000 -0600
+++ base/base.gypi	2014-03-26 08:36:14.892111324 -0600
@@ -864,6 +864,9 @@
               'sources/': [ ['exclude', '_freebsd\\.cc$'] ],
             },
           ],
+	  ['OS == "freebsd" or OS == "openbsd"', {
+	      'sources/': [ ['exclude', 'process_handle_linux.cc'] ],
+	  }],
           ['OS != "openbsd" or >(nacl_untrusted_build)==1', {
               'sources/': [ ['exclude', '_openbsd\\.cc$'] ],
             },
@@ -917,11 +920,15 @@
               'process/memory_stubs.cc',
             ],
             'sources/': [
+              ['exclude', '^debug/proc_maps_linux\\.cc$'],
               ['exclude', '^files/file_path_watcher_linux\\.cc$'],
               ['exclude', '^files/file_path_watcher_stub\\.cc$'],
               ['exclude', '^file_util_linux\\.cc$'],
+              ['exclude', '^process/memory_linux\\.cc$'],
               ['exclude', '^process/process_linux\\.cc$'],
               ['exclude', '^sys_info_linux\\.cc$'],
+              ['exclude', '^process/process_iterator_linux\\.cc$'],
+              ['exclude', '^process/process_metrics_linux\\.cc$'],
             ],
           }],
           ['<(chromeos)!=1 or >(nacl_untrusted_build)==1', {
