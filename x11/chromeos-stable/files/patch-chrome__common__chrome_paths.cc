--- chrome/common/chrome_paths.cc.orig	2014-03-14 21:21:26.000000000 -0600
+++ chrome/common/chrome_paths.cc	2014-03-26 20:49:59.607596812 -0600
@@ -92,6 +92,9 @@
 #else
     FILE_PATH_LITERAL("/usr/share/chromium/extensions");
 #endif  // defined(GOOGLE_CHROME_BUILD)
+#elif defined(OS_FREEBSD)
+const base::FilePath::CharType kFilepathSinglePrefExtensions[] =
+    FILE_PATH_LITERAL("/usr/local/share/chromeos-assets/resources/extensions");
 #endif  // defined(OS_LINUX)
 
 }  // namespace
@@ -401,7 +404,7 @@
       cur = cur.Append(FILE_PATH_LITERAL("custom_wallpapers"));
       break;
 #endif
-#if defined(OS_LINUX) && defined(ENABLE_MANAGED_USERS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && defined(ENABLE_MANAGED_USERS)
     case chrome::DIR_MANAGED_USERS_DEFAULT_APPS:
       if (!PathService::Get(chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS, &cur))
         return false;
@@ -436,10 +439,12 @@
       if (!base::PathExists(cur))  // We don't want to create this
         return false;
       break;
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD)
+#if defined(OS_POSIX) && !defined(OS_MACOSX)
     case chrome::DIR_POLICY_FILES: {
 #if defined(GOOGLE_CHROME_BUILD)
       cur = base::FilePath(FILE_PATH_LITERAL("/etc/opt/chrome/policies"));
+#elif defined(OS_BSD)
+      cur = base::FilePath(FILE_PATH_LITERAL("/usr/local/etc/chrome/policies"));
 #else
       cur = base::FilePath(FILE_PATH_LITERAL("/etc/chromium/policies"));
 #endif
@@ -468,7 +473,7 @@
       break;
     }
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     case chrome::DIR_STANDALONE_EXTERNAL_EXTENSIONS: {
       cur = base::FilePath(kFilepathSinglePrefExtensions);
       break;
