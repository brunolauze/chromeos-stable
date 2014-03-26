--- ./chrome/test/perf/perf_test.cc.orig	2014-03-04 03:17:01.000000000 +0100
+++ ./chrome/test/perf/perf_test.cc	2014-03-07 14:10:33.000000000 +0100
@@ -352,7 +352,7 @@
   AppendResult(output, "ws_final_t", "", "ws_f_t" + trace_name,
                total_working_set_size, "bytes",
                false /* not important */);
-#elif defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_NACL)
   AppendResult(output,
                "vm_size_final_b",
                std::string(),
