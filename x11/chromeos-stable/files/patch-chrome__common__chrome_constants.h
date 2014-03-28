--- chrome/common/chrome_constants.h.orig	2014-03-26 21:53:43.300347029 -0600
+++ chrome/common/chrome_constants.h	2014-03-26 21:53:56.919344206 -0600
@@ -111,7 +111,7 @@
 // This is used by the PreRead experiment.
 extern const char kPreReadEnvironmentVariable[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // The highest and lowest assigned OOM score adjustment
 // (oom_score_adj) used by the OomPriority Manager.
 extern const int kLowestRendererOomScore;
