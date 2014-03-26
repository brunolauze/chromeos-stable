--- ./ui/events/event_switches.cc.orig	2014-03-04 03:17:19.000000000 +0100
+++ ./ui/events/event_switches.cc	2014-03-07 14:10:36.000000000 +0100
@@ -20,7 +20,7 @@
 //   disabled: touch events are disabled.
 const char kTouchEventsDisabled[] = "disabled";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Tells chrome to interpret events from these devices as touch events. Only
 // available with XInput 2 (i.e. X server 1.8 or above). The id's of the
 // devices can be retrieved from 'xinput list'.
