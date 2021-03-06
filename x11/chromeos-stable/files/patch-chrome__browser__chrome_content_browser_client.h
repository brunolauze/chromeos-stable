--- ./chrome/browser/chrome_content_browser_client.h.orig	2014-03-04 03:17:17.000000000 +0100
+++ ./chrome/browser/chrome_content_browser_client.h	2014-03-07 14:10:32.000000000 +0100
@@ -251,7 +251,7 @@
       const base::FilePath& storage_partition_path,
       ScopedVector<fileapi::FileSystemBackend>* additional_backends) OVERRIDE;
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   virtual void GetAdditionalMappedFilesForChildProcess(
       const CommandLine& command_line,
       int child_process_id,
