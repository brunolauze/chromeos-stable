--- chrome/browser/chromeos/input_method/component_extension_ime_manager_impl.cc.orig	2014-03-14 21:22:00.000000000 -0600
+++ chrome/browser/chromeos/input_method/component_extension_ime_manager_impl.cc	2014-03-26 21:44:56.751371648 -0600
@@ -22,6 +22,71 @@
 
 namespace {
 
+#if defined(OS_FREEBSD)
+struct WhitelistedComponentExtensionIME {
+  const char* id;
+  const char* path;
+} whitelisted_component_extension[] = {
+  {
+    // ChromeOS Keyboards extension.
+    "jhffeifommiaekmbkkjlpmilogcfdohp",
+    "/usr/local/share/chromeos-assets/input_methods/keyboard_layouts",
+  },
+  {
+    // ChromeOS Hangul Input.
+    "bdgdidmhaijohebebipajioienkglgfo",
+    "/usr/local/share/chromeos-assets/input_methods/hangul",
+  },
+#if defined(OFFICIAL_BUILD)
+  {
+    // Official Google Japanese Input.
+    "fpfbhcjppmaeaijcidgiibchfbnhbelj",
+    "/usr/local/share/chromeos-assets/input_methods/nacl_mozc",
+  },
+  {
+    // Google Chinese Input (zhuyin)
+    "goedamlknlnjaengojinmfgpmdjmkooo",
+    "/usr/local/share/chromeos-assets/input_methods/zhuyin",
+  },
+  {
+    // Google Chinese Input (pinyin)
+    "nmblnjkfdkabgdofidlkienfnnbjhnab",
+    "/usr/local/share/chromeos-assets/input_methods/pinyin",
+  },
+  {
+    // Google Chinese Input (cangjie)
+    "gjhclobljhjhgoebiipblnmdodbmpdgd",
+    "/usr/local/share/chromeos-assets/input_methods/cangjie",
+  },
+  {
+    // Google input tools.
+    "gjaehgfemfahhmlgpdfknkhdnemmolop",
+    "/usr/local/share/chromeos-assets/input_methods/input_tools",
+  },
+#else
+  {
+    // Open-sourced Pinyin Chinese Input Method.
+    "cpgalbafkoofkjmaeonnfijgpfennjjn",
+    "/usr/local/share/chromeos-assets/input_methods/pinyin",
+  },
+  {
+    // Open-sourced Zhuyin Chinese Input Method.
+    "ekbifjdfhkmdeeajnolmgdlmkllopefi",
+    "/usr/local/share/chromeos-assets/input_methods/zhuyin",
+  },
+  {
+    // Open-sourced Cangjie Chinese Input Method.
+    "aeebooiibjahgpgmhkeocbeekccfknbj",
+    "/usr/local/share/chromeos-assets/input_methods/cangjie",
+  },
+  {
+    // Open-sourced Mozc Japanese Input.
+    "bbaiamgfapehflhememkfglaehiobjnk",
+    "/usr/local/share/chromeos-assets/input_methods/nacl_mozc",
+  },
+#endif
+};
+#else
 struct WhitelistedComponentExtensionIME {
   const char* id;
   const char* path;
@@ -85,6 +150,7 @@
   },
 #endif
 };
+#endif
 
 extensions::ComponentLoader* GetComponentLoader() {
   Profile* profile = ProfileManager::GetDefaultProfileOrOffTheRecord();
