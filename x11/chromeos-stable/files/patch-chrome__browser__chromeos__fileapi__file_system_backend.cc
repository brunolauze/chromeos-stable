--- chrome/browser/chromeos/fileapi/file_system_backend.cc.orig	2014-03-23 10:48:10.985902176 -0600
+++ chrome/browser/chromeos/fileapi/file_system_backend.cc	2014-03-23 10:49:01.941897696 -0600
@@ -74,7 +74,13 @@
       "oem",
       fileapi::kFileSystemTypeRestrictedNativeLocal,
       fileapi::FileSystemMountOption(),
-      base::FilePath(FILE_PATH_LITERAL("/usr/share/oem")));
+      base::FilePath(FILE_PATH_LITERAL(
+#if defined(OS_FREEBSD)
+	"/usr/local/share/chromeos-assets/oem"
+#else
+	"/usr/share/oem"
+#endif
+	)));
 }
 
 bool FileSystemBackend::CanHandleType(fileapi::FileSystemType type) const {
