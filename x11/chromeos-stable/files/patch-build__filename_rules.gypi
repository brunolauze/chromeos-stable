--- build/filename_rules.gypi.orig	2014-03-26 08:32:13.750347218 -0600
+++ build/filename_rules.gypi	2014-03-26 08:33:20.893313293 -0600
@@ -92,7 +92,7 @@
     ['<(use_aura)==0 or OS!="win" or >(nacl_untrusted_build)==1', {
       'sources/': [ ['exclude', '_aurawin\\.(h|cc)$'] ]
     }],
-    ['<(use_aura)==0 or OS!="linux" or >(nacl_untrusted_build)==1', {
+    ['<(use_aura)==0 or (OS!="linux" and OS!="freebsd") or >(nacl_untrusted_build)==1', {
       'sources/': [ ['exclude', '_auralinux\\.(h|cc)$'] ]
     }],
     ['<(use_ash)==0 or >(nacl_untrusted_build)==1', {
