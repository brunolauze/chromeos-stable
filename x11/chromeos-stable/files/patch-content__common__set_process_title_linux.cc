--- ./content/common/set_process_title_linux.cc.orig	2014-03-04 03:17:46.000000000 +0100
+++ ./content/common/set_process_title_linux.cc	2014-03-07 14:10:33.000000000 +0100
@@ -48,6 +48,8 @@
 extern char** environ;
 
 static char** g_main_argv = NULL;
+
+#if !defined(OS_FREEBSD)
 static char* g_orig_argv0 = NULL;
 
 void setproctitle(const char* fmt, ...) {
@@ -100,6 +102,7 @@
   va_end(ap);
   g_main_argv[1] = NULL;
 }
+#endif
 
 // A version of this built into glibc would not need this function, since
 // it could stash the argv pointer in __libc_start_main(). But we need it.
