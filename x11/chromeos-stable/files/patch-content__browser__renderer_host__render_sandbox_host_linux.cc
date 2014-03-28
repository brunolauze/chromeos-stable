--- content/browser/renderer_host/render_sandbox_host_linux.cc.orig	2014-03-26 17:18:14.953473583 -0600
+++ content/browser/renderer_host/render_sandbox_host_linux.cc	2014-03-26 17:18:33.320484633 -0600
@@ -709,7 +709,7 @@
   childs_lifeline_fd_ = pipefds[1];
 
   // We need to be monothreaded before we fork().
-#if !defined(TOOLKIT_GTK)
+#if !defined(TOOLKIT_GTK) && !defined(OS_FREEBSD)
   // Exclude gtk port as TestSuite in base/tests/test_suite.cc is calling
   // gtk_init.
   // TODO(oshima): Remove ifdef when above issues are resolved.
