--- remoting/client/plugin/normalizing_input_filter.cc.orig	2014-03-27 13:46:26.039394932 -0600
+++ remoting/client/plugin/normalizing_input_filter.cc	2014-03-27 13:46:52.067418895 -0600
@@ -11,7 +11,7 @@
 using protocol::InputFilter;
 using protocol::InputStub;
 
-#if !defined(OS_MACOSX) && !defined(OS_CHROMEOS)
+#if !defined(OS_MACOSX) && (!defined(OS_CHROMEOS) || defined(OS_FREEBSD))
 scoped_ptr<InputFilter> CreateNormalizingInputFilter(InputStub* input_stub) {
   return scoped_ptr<InputFilter>(new InputFilter(input_stub));
 }
