--- chrome/common/chrome_constants.cc.orig	2014-03-26 21:53:59.173333607 -0600
+++ chrome/common/chrome_constants.cc	2014-03-26 21:54:12.170342397 -0600
@@ -233,7 +233,7 @@
 // This is used by the PreRead experiment.
 const char kPreReadEnvironmentVariable[] = "CHROME_PRE_READ_EXPERIMENT";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 const int kLowestRendererOomScore = 300;
 const int kHighestRendererOomScore = 1000;
 #endif
