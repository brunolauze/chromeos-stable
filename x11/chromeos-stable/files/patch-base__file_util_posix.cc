--- ./base/file_util_posix.cc.orig	2014-03-04 03:16:26.000000000 +0100
+++ ./base/file_util_posix.cc	2014-03-07 14:10:31.000000000 +0100
@@ -673,7 +673,7 @@
 #endif  // defined(OS_ANDROID)
   results->is_directory = S_ISDIR(file_info.st_mode);
   results->size = file_info.st_size;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || (defined(OS_FREEBSD) && __FreeBSD_version < 900000)
   results->last_modified = Time::FromTimeSpec(file_info.st_mtimespec);
   results->last_accessed = Time::FromTimeSpec(file_info.st_atimespec);
   results->creation_time = Time::FromTimeSpec(file_info.st_ctimespec);
