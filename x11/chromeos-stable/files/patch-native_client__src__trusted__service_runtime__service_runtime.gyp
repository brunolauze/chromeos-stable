--- ./native_client/src/trusted/service_runtime/service_runtime.gyp.orig	2014-03-04 03:18:08.000000000 +0100
+++ ./native_client/src/trusted/service_runtime/service_runtime.gyp	2014-03-07 14:10:34.000000000 +0100
@@ -6,7 +6,7 @@
 {
   'variables': {
     'conditions': [
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="freebsd"', {
         'syscall_handler': [
           'posix/nacl_syscall_impl.c'
         ],
