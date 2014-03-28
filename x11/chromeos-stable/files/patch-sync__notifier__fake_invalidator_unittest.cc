--- sync/notifier/fake_invalidator_unittest.cc.orig	2014-03-26 15:35:37.303897715 -0600
+++ sync/notifier/fake_invalidator_unittest.cc	2014-03-26 15:36:38.690904284 -0600
@@ -10,6 +10,27 @@
 
 namespace syncer {
 
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
+
+
 namespace {
 
 class FakeInvalidatorTestDelegate {
