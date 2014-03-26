--- ./third_party/webrtc/voice_engine/voice_engine_defines.h.orig	2014-03-04 03:18:45.000000000 +0100
+++ ./third_party/webrtc/voice_engine/voice_engine_defines.h	2014-03-07 14:10:36.000000000 +0100
@@ -233,7 +233,7 @@
 #include <pthread.h>
 #include <sys/socket.h>
 #include <sys/types.h>
-#ifndef QNX
+#if !defined(QNX) && !defined(WEBRTC_BSD)
   #include <linux/net.h>
 #ifndef ANDROID
   #include <sys/soundcard.h>
