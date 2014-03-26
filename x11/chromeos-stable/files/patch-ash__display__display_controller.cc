--- ash/display/display_controller.cc.orig	2014-03-26 05:24:14.650980329 -0600
+++ ash/display/display_controller.cc	2014-03-26 05:24:27.883959521 -0600
@@ -772,7 +772,7 @@
   root_windows_[display.id()] = root_window->window();
   SetDisplayPropertiesOnHostWindow(root_window, display);
 
-#if defined(OS_CHROMEOS)
+#if defined(OS_CHROMEOS) && !defined(OS_FREEBSD)
   static bool force_constrain_pointer_to_root =
       CommandLine::ForCurrentProcess()->HasSwitch(
           switches::kAshConstrainPointerToRoot);
