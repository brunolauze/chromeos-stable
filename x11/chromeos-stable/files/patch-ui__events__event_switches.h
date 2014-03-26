--- ./ui/events/event_switches.h.orig	2014-03-04 03:17:19.000000000 +0100
+++ ./ui/events/event_switches.h	2014-03-07 14:10:36.000000000 +0100
@@ -16,7 +16,7 @@
 EVENTS_BASE_EXPORT extern const char kTouchEventsEnabled[];
 EVENTS_BASE_EXPORT extern const char kTouchEventsDisabled[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 #endif
 
