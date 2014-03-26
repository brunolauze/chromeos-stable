--- base/x11/x11_error_tracker.h.orig	2014-03-26 06:24:35.262972984 -0600
+++ base/x11/x11_error_tracker.h	2014-03-26 06:24:47.583799933 -0600
@@ -26,9 +26,7 @@
   bool FoundNewError();
 
  private:
-#if !defined(TOOLKIT_GTK)
   XErrorHandler old_handler_;
-#endif
 
   DISALLOW_COPY_AND_ASSIGN(X11ErrorTracker);
 };
