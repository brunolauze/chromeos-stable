--- chrome/common/chrome_paths.h.orig	2014-03-26 20:46:43.960611420 -0600
+++ chrome/common/chrome_paths.h	2014-03-26 20:46:58.944625759 -0600
@@ -49,7 +49,7 @@
                                  // Getting this path does not create it.
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   DIR_STANDALONE_EXTERNAL_EXTENSIONS,  // Directory for 'per-extension'
                                        // definition manifest files that
                                        // describe extensions which are to be
