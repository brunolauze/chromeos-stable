--- chrome/browser/chromeos/input_method/component_extension_ime_manager_impl.cc.orig	2014-03-26 07:39:11.823507214 -0600
+++ chrome/browser/chromeos/input_method/component_extension_ime_manager_impl.cc	2014-03-26 07:41:09.041348448 -0600
@@ -22,6 +22,7 @@
 
 namespace {
 
+#if defined(OS_FREEBSD)
 struct WhitelistedComponentExtensionIME {
   const char* id;
   const char* path;
@@ -74,6 +75,32 @@
     "/usr/share/chromeos-assets/input_methods/zhuyin",
   },
   {
+    // Google Chinese Input (pinyin)
+    "nmblnjkfdkabgdofidlkienfnnbjhnab",
+    "/usr/share/chromeos-assets/input_methods/pinyin",
+  },
+  {
+    // Google Chinese Input (cangjie)
+    "gjhclobljhjhgoebiipblnmdodbmpdgd",
+    "/usr/share/chromeos-assets/input_methods/cangjie",
+  },
+  {
+    // Google input tools.
+    "gjaehgfemfahhmlgpdfknkhdnemmolop",
+    "/usr/share/chromeos-assets/input_methods/input_tools",
+  },
+#else
+  {
+    // Open-sourced Pinyin Chinese Input Method.
+    "cpgalbafkoofkjmaeonnfijgpfennjjn",
+    "/usr/share/chromeos-assets/input_methods/pinyin",
+  },
+  {
+    // Open-sourced Zhuyin Chinese Input Method.
+    "ekbifjdfhkmdeeajnolmgdlmkllopefi",
+    "/usr/share/chromeos-assets/input_methods/zhuyin",
+  },
+  {
     // Open-sourced Cangjie Chinese Input Method.
     "aeebooiibjahgpgmhkeocbeekccfknbj",
     "/usr/share/chromeos-assets/input_methods/cangjie",
@@ -85,6 +112,71 @@
   },
 #endif
 };
+#else
+struct WhitelistedComponentExtensionIME {
+  const char* id;
+  const char* path;
+} whitelisted_component_extension[] = {
+  {
+    // ChromeOS Keyboards extension.
+    "jhffeifommiaekmbkkjlpmilogcfdohp",
+    "/usr/share/chromeos-assets/input_methods/keyboard_layouts",
+  },
+  {
+    // ChromeOS Hangul Input.
+    "bdgdidmhaijohebebipajioienkglgfo",
+    "/usr/share/chromeos-assets/input_methods/hangul",
+  },
+#if defined(OFFICIAL_BUILD)
+  {
+    // Official Google Japanese Input.
+    "fpfbhcjppmaeaijcidgiibchfbnhbelj",
+    "/usr/share/chromeos-assets/input_methods/nacl_mozc",
+  },
+  {
+    // Google Chinese Input (zhuyin)
+    "goedamlknlnjaengojinmfgpmdjmkooo",
+    "/usr/share/chromeos-assets/input_methods/zhuyin",
+  },
+  {
+    // Google Chinese Input (pinyin)
+    "nmblnjkfdkabgdofidlkienfnnbjhnab",
+    "/usr/share/chromeos-assets/input_methods/pinyin",
+  },
+  {
+    // Google Chinese Input (cangjie)
+    "gjhclobljhjhgoebiipblnmdodbmpdgd",
+    "/usr/share/chromeos-assets/input_methods/cangjie",
+  },
+  {
+    // Google input tools.
+    "gjaehgfemfahhmlgpdfknkhdnemmolop",
+    "/usr/share/chromeos-assets/input_methods/input_tools",
+  },
+#else
+  {
+    // Open-sourced Pinyin Chinese Input Method.
+    "cpgalbafkoofkjmaeonnfijgpfennjjn",
+    "/usr/share/chromeos-assets/input_methods/pinyin",
+  },
+  {
+    // Open-sourced Zhuyin Chinese Input Method.
+    "ekbifjdfhkmdeeajnolmgdlmkllopefi",
+    "/usr/share/chromeos-assets/input_methods/zhuyin",
+  },
+  {
+    // Open-sourced Cangjie Chinese Input Method.
+    "aeebooiibjahgpgmhkeocbeekccfknbj",
+    "/usr/share/chromeos-assets/input_methods/cangjie",
+  },
+  {
+    // Open-sourced Mozc Japanese Input.
+    "bbaiamgfapehflhememkfglaehiobjnk",
+    "/usr/share/chromeos-assets/input_methods/nacl_mozc",
+  },
+#endif
+};
+#endif
 
 extensions::ComponentLoader* GetComponentLoader() {
   Profile* profile = ProfileManager::GetDefaultProfileOrOffTheRecord();
