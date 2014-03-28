--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2014-03-26 17:19:06.255475081 -0600
+++ content/browser/renderer_host/render_widget_host_view_aura.cc	2014-03-26 17:19:35.877467960 -0600
@@ -733,7 +733,7 @@
     return reinterpret_cast<gfx::NativeViewId>(
         dispatcher->host()->GetAcceleratedWidget());
 #endif
-  return static_cast<gfx::NativeViewId>(NULL);
+  return reinterpret_cast<gfx::NativeViewId>(NULL);
 }
 
 gfx::NativeViewAccessible RenderWidgetHostViewAura::GetNativeViewAccessible() {
