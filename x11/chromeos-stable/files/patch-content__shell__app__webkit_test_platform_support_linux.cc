--- content/shell/app/webkit_test_platform_support_linux.cc.orig	2014-03-24 16:41:10.936776784 -0600
+++ content/shell/app/webkit_test_platform_support_linux.cc	2014-03-24 17:17:00.500628625 -0600
@@ -39,6 +39,37 @@
 }
 
 const char* const kFonts[] = {
+#if defined(OS_FREEBSD)
+    "/usr/local/share/font-kochi/kochi-gothic-subst.ttf",
+    "/usr/local/share/font-kochi/kochi-mincho-subst.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/arial.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/arialbd.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/arialbi.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/ariali.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/comic.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/comicbd.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/cour.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/courbd.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/courbi.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/couri.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/georgia.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/georgiab.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/georgiai.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/impact.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/trebuc.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/trebucbd.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/trebucbi.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/trebucit.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/times.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/timesbd.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/timesbi.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/timesi.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/verdana.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/verdanab.ttf",
+    "/usr/local/lib/X11/fonts/webfonts/verdanai.ttf",
+     // The DejaVuSans font is used by the css2.1 tests.
+    "/usr/local/lib/X11/fonts/dejavu/DejaVuSans.ttf",
+#else
     "/usr/share/fonts/truetype/kochi/kochi-gothic.ttf",
     "/usr/share/fonts/truetype/kochi/kochi-mincho.ttf",
     "/usr/share/fonts/truetype/msttcorefonts/Arial.ttf",
@@ -73,6 +104,7 @@
     "/usr/share/fonts/truetype/ttf-indic-fonts-core/lohit_hi.ttf",
     "/usr/share/fonts/truetype/ttf-indic-fonts-core/lohit_ta.ttf",
     "/usr/share/fonts/truetype/ttf-indic-fonts-core/MuktiNarrow.ttf",
+#endif
 };
 
 bool SetupFontConfig() {
@@ -105,6 +137,7 @@
     }
   }
 
+#if !defined(OS_FREEBSD)
   if (!CheckAndLoadFontFile(
           font_config,
           "/usr/share/fonts/truetype/thai/Garuda.ttf",
@@ -118,6 +151,7 @@
       font_config,
       "/usr/share/fonts/truetype/ttf-indic-fonts-core/lohit_pa.ttf",
       "/usr/share/fonts/truetype/ttf-punjabi-fonts/lohit_pa.ttf");
+#endif
 
   base::FilePath ahem_font = base_path.Append("AHEM____.TTF");
   if (!FcConfigAppFontAddFile(
