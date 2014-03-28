--- chrome/browser/memory_details_linux.cc.orig	2014-03-27 13:36:47.158435026 -0600
+++ chrome/browser/memory_details_linux.cc	2014-03-27 13:37:06.542433632 -0600
@@ -233,7 +233,7 @@
     process_data_.push_back(browser);
   }
 
-#if defined(OS_CHROMEOS)
+#if defined(OS_CHROMEOS) && !defined(OS_FREEBSD)
   base::GetSwapInfo(&swap_info_);
 #endif
 
