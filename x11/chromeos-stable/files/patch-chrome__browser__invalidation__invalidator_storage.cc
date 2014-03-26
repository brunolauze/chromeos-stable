--- chrome/browser/invalidation/invalidator_storage.cc.orig	2014-03-26 09:41:07.909770901 -0600
+++ chrome/browser/invalidation/invalidator_storage.cc	2014-03-26 09:41:17.511284222 -0600
@@ -17,6 +17,32 @@
 #include "chrome/common/pref_names.h"
 #include "components/user_prefs/pref_registry_syncable.h"
 
+
+/* HACK: This is missing when using shared library */
+namespace syncer {
+
+bool InvalidationVersionLessThan::operator()(
+    const Invalidation& a,
+    const Invalidation& b) const {
+  DCHECK(a.object_id() == b.object_id())
+      << "a: " << ObjectIdToString(a.object_id()) << ", "
+      << "b: " << ObjectIdToString(a.object_id());
+
+  if (a.is_unknown_version() && !b.is_unknown_version())
+    return true;
+
+  if (!a.is_unknown_version() && b.is_unknown_version())
+    return false;
+
+  if (a.is_unknown_version() && b.is_unknown_version())
+    return false;
+
+  return a.version() < b.version();
+}
+
+}
+
+
 namespace {
 
 const char kInvalidatorMaxInvalidationVersions[] =
