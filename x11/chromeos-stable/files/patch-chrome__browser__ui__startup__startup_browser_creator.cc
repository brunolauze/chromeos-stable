--- chrome/browser/ui/startup/startup_browser_creator.cc.orig	2014-03-27 12:14:23.371775809 -0600
+++ chrome/browser/ui/startup/startup_browser_creator.cc	2014-03-27 12:15:09.196775061 -0600
@@ -77,7 +77,7 @@
 #include "chromeos/chromeos_switches.h"
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(OS_LINUX)
+#if defined(TOOLKIT_VIEWS) && defined(USE_X11) && defined(OS_LINUX)
 #include "ui/events/x/touch_factory_x11.h"
 #endif
 
@@ -625,7 +625,7 @@
   }
 #endif
 
-#if defined(TOOLKIT_VIEWS) && defined(USE_X11)
+#if defined(TOOLKIT_VIEWS) && defined(USE_X11) && defined(OS_LINUX)
   ui::TouchFactory::SetTouchDeviceListFromCommandLine();
 #endif
 
